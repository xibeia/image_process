#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int createMaskByKmeans(cv::Mat src, cv::Mat & mask)
{
	if ((mask.type() != CV_8UC1)
		|| (src.size() != mask.size())
		) {
		return 0;
	}

	int width = src.cols;
	int height = src.rows;

	int pixNum = width * height;

	int clusterCount = 2;

	Mat labels;
	Mat centers;

	//制作kmeans用的数据
	Mat sampleData = src.reshape(3, pixNum);
	Mat km_data;
	sampleData.convertTo(km_data, CV_32F);

	//执行kmeans
	TermCriteria criteria = TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 0.1);
	kmeans(km_data, clusterCount, labels, criteria, clusterCount, KMEANS_PP_CENTERS, centers);

	//制作mask
	uchar fg[2] = { 0,255 };
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			mask.at<uchar>(row, col) = fg[labels.at<int>(row*width + col)]; //利用k-means聚类结果得到mask
		}
	}

	return 0;
}


int main() {

	VideoCapture srccap, drgcap;
	srccap.open("bg.mp4");
	drgcap.open("dragon.mp4");

	if (!srccap.isOpened() || !drgcap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return -1;
	};

	Mat srcframe, drgframe;

	double srcfps = srccap.get(CAP_PROP_FPS);
	std::cout << "src:fps" << srcfps << std::endl;

	double drgfps = drgcap.get(CAP_PROP_FPS);
	std::cout << "dragon:fps" << drgfps << std::endl;

	Mat drggray;
	Mat mask;
	Mat maskinv;

	Mat dragonFront, srcFront, filimg;

	while (1) {

		drgcap >> drgframe;
		srccap >> srcframe;

		//Mat mask = Mat::zeros(drgframe.size(), CV_8UC1);
		//createMaskByKmeans(drgframe, mask);
		// 用kmeans提取mask效果不好,还不如直接二值化


		//将龙灰度化
		cvtColor(drgframe, drggray, CV_BGR2GRAY);
		//将灰度值二值化，得到图像掩模,此时龙的mask是黑的即为0
		threshold(drggray, mask, 100, 255, THRESH_BINARY);
		//反向变为白的
		bitwise_not(mask, maskinv);

		imshow("mask", mask);
		imshow("maskinv", maskinv);


		//提取出龙
		bitwise_and(drgframe, drgframe, dragonFront, maskinv);

		imshow("龙前景", dragonFront);

		////提取背景
		bitwise_and(srcframe, srcframe, srcFront, mask);  //?报错？？

		//////前景背景融合
		add(dragonFront, srcFront, filimg);

		//add(drgframe, srcframe, filimg);

		imshow("龙前景", dragonFront);
		imshow("环境背景", srcFront);

		imshow("融合后", filimg);

		waitKey(30);
	}



}