#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

void salt(cv::Mat &image, int n)
{   //��ӽ�������
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
//	image = cv::imread("D://������ѧϰ����//����ͼ����//images/boldt.jpg");
//	salt(image, 300);
//
//	cv::namedWindow("Image");
//	cv::imshow("Image", image);
//
//	cv::waitKey(0);
//
//}