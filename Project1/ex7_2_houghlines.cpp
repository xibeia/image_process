//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//	Mat srcMat,srcMat2, dstMat;
//	srcMat2 = imread("零件.jpg", 1); //读取san通道
//	srcMat = imread("零件.jpg", 0); //读取单通道
//	if (srcMat.empty()) return -1;
//
//	Mat threhold_img,canny_img;
//
//	threshold(srcMat, threhold_img, 100, 255, THRESH_BINARY);
//	Canny(threhold_img, canny_img, 50, 125, 3);
//
//	std::vector<cv::Vec2f> lines;
//	HoughLines(canny_img, lines, 1, CV_PI/180, 92);
//
//	std::cout << "line number: " << lines.size() << std::endl;
//
//	//画线
//	std::vector<cv::Vec2f>::iterator it = lines.begin();
//	for (; it != lines.end(); ++it) {
//		float rho = (*it)[0], theta = (*it)[1];
//		Point pt1, pt2;
//		double a = cos(theta);
//		double b = sin(theta);
//		double x0 = a * rho;
//		double y0 = b * rho;
//		pt1.x = cv::saturate_cast<int>(x0 + 1000 * (-b));
//		pt1.y = cv::saturate_cast<int>(y0 + 1000 * (a));
//		pt2.x = cv::saturate_cast<int>(x0 - 1000 * (-b));
//		pt2.y = cv::saturate_cast<int>(y0 - 1000 * (a));
//
//		line(srcMat2, pt1, pt2, cv::Scalar(255, 0, 0), 2, CV_AA);
//
//	}
//
//	imshow("边缘", canny_img);
//	imshow("原图", srcMat2);
//
//
//
//	waitKey(0);
//
//	return 0;
//}