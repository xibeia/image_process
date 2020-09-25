#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

void salt(cv::Mat &image, int n)
{   //添加椒盐噪声
	for (int k = 0; k < n; k++) {
		int i = rand() % image.cols;
		int j = rand() % image.rows;
		if (image.channels() == 1) {
			image.at<uchar>(j, i) = 255;
		}
		else if (image.channels() == 3) {
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
		}
	}

}

//int main()
//{
//
//	cv::Mat image;
//	image = cv::imread("D://大三上学习资料//数字图像处理//images/boldt.jpg");
//	salt(image, 300);
//
//	cv::namedWindow("Image");
//	cv::imshow("Image", image);
//
//	cv::waitKey(0);
//
//}