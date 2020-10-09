//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//
//	cv::Mat srcimg;
//	srcimg = imread("D://大三上学习资料//数字图像处理//22.jpg");
//	std::vector<cv::Mat> vchannels;
//	cv::split(srcimg, vchannels);
//	cv::Mat mB = vchannels.at(0);
//	cv::Mat mG = vchannels.at(1);
//	cv::Mat mR = vchannels.at(2);
//
//	imshow("blue", mB);
//	imshow("green", mG);
//	imshow("red", mR);
//	imshow("src", srcimg);
//	waitKey(0);
//
//
//}