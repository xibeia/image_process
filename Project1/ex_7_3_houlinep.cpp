////#include <opencv2/opencv.hpp>
////#include <iostream>
////using namespace cv;
////using namespace std;
////int main()
////{
////	Mat srcMat = imread("Áã¼þ.jpg");
////	Mat cannyMat, lineMat;
////	Canny(srcMat, cannyMat, 100, 200, 3);
////	HoughLinesP(cannyMat, lineMat, 1, CV_PI / 180, 50, 50, 10);
//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace cv;
//using namespace std;
//int main()
//{
//	Mat srcMat = imread("0.jpg");
//	Mat cannyMat, lineMat;
//	Canny(srcMat, cannyMat, 100, 200, 3);
//	HoughLinesP(cannyMat, lineMat, 1, CV_PI / 180, 50, 50, 10);
//
//	for (int i = 0; i < lineMat.rows; i++)
//	{
//		Vec4i  lines = lineMat.at<Vec4i>(i);
//		line(srcMat, Point(lines[0], lines[1]), Point(lines[2], lines[3]), Scalar(0, 255, 255), 1, CV_AA);
//	}
//	
//	imshow("srcMat", srcMat);
//	waitKey(0);
//	return 0;
//}
////	waitKey(0);
////	return 0;
////}