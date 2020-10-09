//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//
//	Mat srcimg,result1,result2;
//	srcimg = imread("D://大三上学习资料//数字图像处理//lenna2.jpg",0);
//	threshold(srcimg, result1, 100, 255, THRESH_BINARY);
//
//	imshow("srcimg", srcimg);
//	imshow("THRESH_BINARY result1", result1);
//
//	adaptiveThreshold(srcimg, result2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 10);
//
//	imshow("result2", result2);
//
//	waitKey(0);
//}