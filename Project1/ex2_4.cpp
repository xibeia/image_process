//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//void calculateHistgram(cv::Mat &image, float *  histgram) { 	
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//			histgram[image.at<uchar>(j, i)]++;
//		}
//	}
//
//	for (int i = 0; i < 256; i++) {
//		int n = n1 * nc;
//		histgram[i] = float(histgram[i] / n);
//	}
//
//}
//
//void showHistgram(float * histgram,int N ) {
//
//	Mat drawImage = Mat::zeros(Size(256, 256), CV_8UC3);
//
//	for (int i = 0; i < N; i++)
//	{
//		line(drawImage, Point(i, 256), Point(i, (1-histgram[i]) * 200), Scalar(0, 0, 255));  //scalar 是线颜色,像素坐标（0,0）在左上角，因此要倒过来绘制
//	}
//
//	imshow("hist", drawImage);
//	waitKey(0);
//
//}
//
//void ReadRGBhist(cv::Mat &image, float *  histB, float *  histG, float *  histR) {
//
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//			histB[image.at<Vec3b>(j, i)[0]]++;
//			histG[image.at<Vec3b>(j, i)[1]]++;
//			histR[image.at<Vec3b>(j, i)[2]]++;
//		}
//	}
//
//	for (int i = 0; i < 256; i++) {
//		int n = n1 * nc;
//		histB[i] = float(histB[i] / n);
//		histG[i] = float(histG[i] / n);
//		histR[i] = float(histR[i] / n);
//	}
//
//}
//
//
//
//int main() {
//
//	cv::Mat imgsrc,img2;
//
//	//灰度直方图
//	imgsrc = imread("D://大三上学习资料//数字图像处理//lenna2.jpg",0);//读灰度值
//
//	float histgram[256] = { 0 };
//	calculateHistgram(imgsrc, histgram);
//
//	showHistgram(histgram, 256);
//
//	//RGB直方图
//	//img2= imread("D://大三上学习资料//数字图像处理//lenna2.jpg", 0);//读灰度值
//
//	////std::vector<cv::Mat> vchannels;
//	////cv::split(img2, vchannels);
//	////cv::Mat mB = vchannels.at(0);
//	////cv::Mat mG = vchannels.at(1);
//	////cv::Mat mR = vchannels.at(2);
//
//	//float histB[256] = { 0 }, histG[256] = { 0 }, histR[256] = { 0 };
//	//ReadRGBhist(img2, histB, histG, histR);
//
//	//showHistgram(histB, 256);
//	//showHistgram(histG, 256);
//	//showHistgram(histR, 256);
//}
