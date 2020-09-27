#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main() {

	cv::Mat dispMat;
	dispMat.create(600, 600, CV_8UC3);

	cv::Point pt,pt1;
	pt.x = 10;
	pt.y = 10;
	circle(dispMat, pt, 5, CV_RGB(255, 0, 0), 1, 8, 0);
	pt1.x = 500;
	pt1.y = 500;
	circle(dispMat, pt1, 5, CV_RGB(255, 0, 0), 1, 8, 0);
	imshow("µã", dispMat);
	waitKey(0);
	
	cv::Mat dispMat2;
	dispMat2.create(600, 600, CV_8UC3);
	line(dispMat2, pt, pt1, CV_RGB(255, 0, 0), 1, 8, 0);
	imshow("Ïß", dispMat2);
	waitKey(0);


	cv::Mat dispMat3;
	dispMat3.create(600, 600, CV_8UC3);
	cv::Rect rect;
	rect.x = 20;
	rect.y = 20;
	rect.width = 400;
	rect.height = 300;
	rectangle(dispMat3, rect, CV_RGB(255, 0, 0), 1, 8, 0);
	imshow("¾ØÐÎ", dispMat3);
	waitKey(0);


}