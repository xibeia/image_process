//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//string window_name = "binaryMat";
//void threshold_Mat(int th,void*data) {
//	Mat src = *(Mat*)(data);
//
//	Mat dst;
//	threshold(src, dst, th, 255, 0);
//	imshow(window_name, dst);
//
//}
//
//
//int main() {
//
//	Mat srcMat;
//	Mat gryMat;
//	int lowTh = 30;
//	int maxTh = 255;
//	srcMat = imread("D://大三上学习资料//数字图像处理//lenna2.jpg");
//	imshow("srcMat", srcMat);
//
//	if (!srcMat.data) {
//		cout << "图像加载失败" << endl;
//		return 0;
//	}
//	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
//	imshow(window_name, gryMat);
//	createTrackbar("threshold", window_name, &lowTh, maxTh, threshold_Mat, &gryMat);
//	waitKey(0);
//	
//	return 0;
//
//}