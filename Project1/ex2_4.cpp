#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

float calculateHistgram(cv::Mat &image) {
	float histgram[256] = { 0 };
	int n1 = image.rows;
	int nc = image.cols;
	for (int j = 0; j < n1; j++) {
		for (int i = 0; i < nc; i++) {
			histgram[image.at<uchar>(j, i)]++;
		}
	}
	//int sum = 0;
	//for (int k = 0; k < 256; k++) {
	//	sum += histgram[k];
	//}
	//histgram[256] /= sum;

	return histgram[256]/n1/nc;
		
}

void showHistgram(float histgram[],int N ) {

	Mat drawImage = Mat::zeros(Size(256, 256), CV_8U);

	for (int i = 0; i < N; i++)
	{
		line(drawImage, Point(i, 0), Point(i, histgram[i] * 250), Scalar(0, 0, 255));
	}

	imshow("hist", drawImage);
	waitKey(0);

}



int main() {
	cv::Mat imgsrc;
	imgsrc = imread("D:/大三上学习资料/数字图像处理/lenna.jpg",0);//读灰度值
	cout<<"直方图数组"<<calculateHistgram(imgsrc)<<endl;

	float histgram[256];
	histgram[256] = calculateHistgram(imgsrc);

	showHistgram(histgram,256);

}
