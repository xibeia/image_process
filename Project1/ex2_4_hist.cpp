//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//void calculateHistgram(cv::Mat &image, float *  histgram ) { 	
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//			histgram[image.at<uchar>(j, i)]++;
//		}
//	}
//
//	//int n = n1 * nc;
//
//	//for (int i = 0; i < 256; i++) {
//	//	
//	//	histgram[i] = float(histgram[i] / n);
//
//	//}
//
//}
//
///*修正原因
//line(drawImage, Point(i, 256), Point(i, (1-histgram[i]) * 200), Scalar(0, 0, 255));
//绘制显示不太对，因为此时histgram[i]为算出的比率，很小，数量级为0.0001，导致显示的很小，不能直接用
//*/
//void showHistgram(float * histgram,int N ) {
//
//	
//	float pixmax = 0;
//	for (int i = 0; i < 256; i++) {
//		if (histgram[i] > pixmax)
//		{
//			pixmax = histgram[i];  //统计出最大的值，然后后面根据最大值调整画布
//		}
//	}
//
//	Mat drawImage = Mat::zeros(Size(256, 256), CV_8UC3);  //设置画布尺寸为256*256
//	float hrate = float(256 / pixmax);  //高度缩放比例,使其缩放在画布范围内
//
//	for (int i = 0; i < N; i++)
//	{
//
//		line(drawImage, Point(i, 256), Point(i, 256 - histgram[i]* hrate), Scalar(0, 0, 255));  //scalar 是线颜色,像素坐标（0,0）在左上角，因此要倒过来绘制
//	}
//
//	imshow("hist", drawImage);
//
//}
//
////void ReadRGBhist(cv::Mat &image, float *  histB, float *  histG, float *  histR) {
////
////	int n1 = image.rows;
////	int nc = image.cols;
////	for (int j = 0; j < n1; j++) {
////		for (int i = 0; i < nc; i++) {
////			histB[image.at<Vec3b>(j, i)[0]]++;
////			histG[image.at<Vec3b>(j, i)[1]]++;
////			histR[image.at<Vec3b>(j, i)[2]]++;
////		}
////	}
////
////	//for (int i = 0; i < 256; i++) {
////	//	int n = n1 * nc;
////	//	histB[i] = float(histB[i] / n);
////	//	histG[i] = float(histG[i] / n);
////	//	histR[i] = float(histR[i] / n);
////	//}
////
////}
//
//
//
//int main() {
//
//	cv::Mat imgsrc,img2;
//
//	//灰度直方图
//	imgsrc = imread("D://大三上学习资料//数字图像处理//lenna2.jpg",0);//读灰度值
//	imshow("src", imgsrc);
//
//
//	float histgram[256] = { 0 };
//	calculateHistgram(imgsrc, histgram);
//
//	showHistgram(histgram, 256);
//
//	////RGB直方图
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
//
//	waitKey(0);
//
//	return 0;
//}
