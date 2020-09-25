#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;

//void colorReduce(cv::Mat &image, int div = 64);
void colorReduce(cv::Mat &image) {
	int n1 = image.rows;
	int nc = image.cols;
	for (int j = 0; j < n1; j++) {
		for (int i = 0; i < nc; i++) {
			uchar ave = (image.at<Vec3b>(j, i)[0] + image.at<Vec3b>(j, i)[1] + image.at<Vec3b>(j, i)[2]) / 3;
			image.at<Vec3b>(j, i)[0] = ave;
			image.at<Vec3b>(j, i)[1] = ave;
			image.at<Vec3b>(j, i)[2] = ave;
		}
			
	}
}

int main(){
	cv::Mat imgsrc;
	imgsrc = imread("D:/������ѧϰ����/����ͼ����/lenna.jpg");
	namedWindow("ͼƬ");
	imshow("ͼƬ", imgsrc);
	waitKey(0);

	// ��ʾ������ͼƬ   
	 colorReduce(imgsrc);

	 namedWindow("ͼƬ2");
	 imshow("ͼƬ2", imgsrc);
	 waitKey(0);

	
	return 0;


}
