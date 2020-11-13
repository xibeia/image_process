//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//	Mat srcMat, dstMat;
//	srcMat = imread("lenna2.jpg", 1);
//	if (srcMat.empty()) return -1;
//
//	Point2f center(srcMat.cols / 2.0, srcMat.rows / 2.0);
//	float angle = 30.0, scale = 1;
//
//	Mat  rot = getRotationMatrix2D(center, angle, scale);
//	Rect bbox = RotatedRect(center, srcMat.size(), angle).boundingRect();
//
//	rot.at<double>(0, 2) += bbox.width /2.0 - center.x;
//	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;
//
//
//
//	//º∆À„∑≈…‰æÿ’Û
//
//	warpAffine(srcMat, dstMat, rot, bbox.size());
//
//
//	imshow("‘≠Õº", srcMat);
//	imshow("∑¬…‰±‰ªª", dstMat);
//
//
//	waitKey(0);
//
//	return 0;
//}