#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//ex8_3尝试了很多，他总是把鼠标垫跟红色盒子连在一起检测，实在不行换了一种方式，
//先直接把红色检测到置为白色，可借助画图工具确定其大概的RGB范围
void RedDetect(cv::Mat &image) {
	int n1 = image.rows;
	int nc = image.cols;
	for (int j = 0; j < n1; j++) {
		for (int i = 0; i < nc; i++) {
			if (image.at<Vec3b>(j, i)[0] < 110 && image.at<Vec3b>(j, i)[1] < 110 && image.at<Vec3b>(j, i)[2] >120) {
				image.at<Vec3b>(j, i)[0] = 255;
				image.at<Vec3b>(j, i)[1] = 255;
				image.at<Vec3b>(j, i)[2] = 255;

			}
			else {
				image.at<Vec3b>(j, i)[0] = 0;
				image.at<Vec3b>(j, i)[1] = 0;
				image.at<Vec3b>(j, i)[2] = 0;
			}
		}
	}
}



int main() {
	Mat srcMat, srcMat2, thresold_img;
	srcMat = imread("红盒子.jpg", 0);//单通道
	srcMat2 = imread("红盒子.jpg", 1);//三通道
	if (srcMat.empty()) return -1;
	//imshow("原图", srcMat);

	//原图太大了，缩小一下
	Mat resizeMat, resizeMat2;
	resize(srcMat2, resizeMat, Size(srcMat.cols / 6, srcMat.rows / 6), 0, 0, INTER_LINEAR); //单通道
	resize(srcMat2, resizeMat2, Size(srcMat.cols / 6, srcMat.rows / 6), 0, 0, INTER_LINEAR);  //三通道
	
	imshow("缩小图", resizeMat2);
	int flag = 0;
	RedDetect(resizeMat2);

	imshow("红色检测图", resizeMat2);
	//可以看出可以大概先确定出红盒子的位置
	cvtColor(resizeMat2, thresold_img, CV_BGR2GRAY);
	//threshold(resizeMat2, thresold_img, 80, 255, THRESH_OTSU);

	//通过finvontours寻找连通域
	vector<vector<Point>>  contours;
	vector<Vec4i> hierachy;

	findContours(thresold_img, contours,hierachy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	//CV_RETR_EXTERNAL 只检测最外围轮阔，CV_CHAIN_APPROX_NONE：保存轮廓点到contours向量内
	//coutous里面存储了所有的轮廓的点

	for (int i = 0; i < contours.size(); ++i) {
		RotatedRect rbox = minAreaRect(contours[i]);

		float width = rbox.size.width;
		float height = rbox.size.height;
		
		float kk = width / height;
		float ci_area = width * height;
		

		if (ci_area > 200) {  //取面积大的，用面积限制去除小噪点
			//绘制轮廓
			drawContours(resizeMat, contours, i, Scalar(0, 255, 255), 1, 8);

			//画出外接四边形
			Rect r = boundingRect(Mat(contours[i]));
			rectangle(resizeMat, r, Scalar(0,0,255), 2);
		}
		

	}

	imshow("标记图", resizeMat);
	


	waitKey(0);
	return 0;
}



