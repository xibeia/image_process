#include<iostream>
#include<opencv2/opencv.hpp>
#include <math.h>

using namespace cv;
using namespace std;


int calcHog(cv::Mat &src, float * hist, int cellSize = 16, int nAngle = 8) {

	int nX = src.cols / cellSize; //横向block个数
	int nY = src.rows / cellSize; //纵向block个数
	int binAngle = 360 / nAngle;

	Mat gx, gy;
	Mat mag, angle;

	Sobel(src, gx, CV_32F, 1, 0, 1);
	Sobel(src, gy, CV_32F, 0, 1, 1);

	//将直角坐标系转到极坐标系，默认输出为弧度,radians，也可以选择角度;mag, angle为输出的幅度值与角度值
	cartToPolar(gx, gy, mag, angle, true);

	Rect roi;
	roi.x = 0;
	roi.y = 0;
	roi.width = cellSize;
	roi.height = cellSize;


	for (int i = 0; i < nY; i++) {
		for (int j = 0; j < nX; j++) {
			Mat roiMat;
			Mat roiMag;
			Mat roiAgl;

			//取图像的一个cell
			roi.x = j * cellSize;
			roi.y = i * cellSize;

			roiMat = src(roi);  
			roiMag = mag(roi);
			roiAgl = angle(roi);

			int head = (i*nX + j)*nAngle;  //当前Cell在数组中的位置

			//统计直方图信息
			for (int n = 0; n < roiMat.rows; n++) {
				for (int m = 0; m < roiMat.cols; m++) {

					//计算角度在哪个区间（8个），通过int自动取整实现
					int pos = (int)(roiAgl.at<float>(n, m) / binAngle);
					//以像素点的值为权重
					hist[head + pos] += roiMag.at<float>(n, m);
				}
			}


		}
	}

	return 0;
}

//计算直方图相似度，欧几里得距离
float normL2(float * hist1, float * hist2, int size) {

	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (hist1[i] - hist2[i])*(hist1[i] - hist2[i]);

	}
	sum = sqrt(sum);

	return sum;

}

int main() {

	Mat refMat, plMat, bgMat;
	refMat = imread("hogTemplate.jpg",0);//单通道读取，不然报错
	plMat = imread("img1.jpg",0);
	bgMat = imread("img2.jpg",0);

	//判断图片是否加载成功
	if ( refMat.empty() || plMat.empty() || bgMat.empty())
	{
		cout << "image load failed!" << endl;
		return -1;
	}

	//计算三张输入图片的HOG
	int cellSize = 16;
	int nAngle = 8;

	int nX = refMat.cols / cellSize; //横向block个数
	int nY = refMat.rows / cellSize; //纵向block个数
	int bins = nX * nY*nAngle;  //维度

	//为直方图开辟内存
	float *ref_hist = new float[bins];
	memset(ref_hist, 0, sizeof(float)*bins);
	float *pl_hist = new float[bins];
	memset(pl_hist, 0, sizeof(float)*bins);
	float *bg_hist = new float[bins];
	memset(bg_hist, 0, sizeof(float)*bins);


	int recCode = 0;

	recCode = calcHog(refMat, ref_hist, nAngle, cellSize);
	recCode = calcHog(plMat, pl_hist, nAngle, cellSize);
	recCode = calcHog(bgMat, bg_hist, nAngle, cellSize);

	//判断函数是否运行成功
	if (recCode != 0) {
		delete[] ref_hist;
		delete[] pl_hist;
		delete[] bg_hist;

		cout << "calcHog working error" << endl;

		return -1;
	}


	//计算直方图距离
	float dis1 = normL2(ref_hist, pl_hist, bins);
	float dis2 = normL2(ref_hist, bg_hist, bins);

	cout << "dis1与原图的相似度为：" << dis1 << endl;
	cout << "dis2与原图的相似度为：" << dis2 << endl;


	//输出谁最相似
	(dis1 <= dis2) ? (std::cout << "img1 is similar" << std::endl) : (std::cout << "img2 is similar" << std::endl);


	imshow("ref", refMat);
	imshow("img1", plMat);
	imshow("img2", bgMat);

	//释放内存
	delete[] ref_hist;
	delete[] pl_hist;
	delete[] bg_hist;

	waitKey(0);


	return 0;
}