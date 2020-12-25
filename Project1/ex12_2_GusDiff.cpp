//#include<iostream>
//#include<opencv2/opencv.hpp>
//#include<math.h>
//#include<cmath>
//
//
//using namespace cv;
//using namespace std;
//
//
//
//int main() {
//
//	VideoCapture cap;
//	cap.open(0);
//	if (!cap.isOpened())
//	{
//		std::cout << "不能打开视频文件" << std::endl;
//		return -1;
//	}
//
//	//double fps = cap.get(CAP_PROP_FPS);
//	//std::cout << "fps" << fps << std::endl;
//	//int cnt = cap.get(CV_CAP_PROP_FRAME_COUNT);//获取帧数   视频文件的帧数 ，摄像头返回-1
//	
//	double fps = cap.get(CV_CAP_PROP_FPS);//获取FPS  
//	std::cout << "fps" << fps << std::endl;
//
//	Mat frame; //读入帧
//	Mat subMat ;//差分 
//	Mat bgMat; //背景
//
//
//	vector<Mat> sumMat;
//	Mat meanMat; //均值
//	Mat varMat;  //方差
//	Mat dstMat;
//
//	
//
//	int cnt = 0;
//
//	//先取n帧的图片计算均值方差
//	int n = 10;
//	for (int tt = 0; tt < n; tt++) {
//		
//		bool rSucess = cap.read(frame);
//		
//		//将摄像头读取到的图像转化为灰度图
//		cvtColor(frame, frame, COLOR_BGR2GRAY);
//		//threshold(frame, frame, 100, 255, THRESH_BINARY);
//
//		if (!rSucess)
//		{
//			std::cout << "不能从视频文件中读取帧" << std::endl;
//			break;
//		}
//
//		if (tt == 0) {
//			frame.copyTo(bgMat);
//			//初始化meanMat 与 varMat为0
//			meanMat = Mat::zeros(bgMat.rows, bgMat.cols, bgMat.type());
//			varMat = Mat::zeros(bgMat.rows, bgMat.cols, bgMat.type());
//			dstMat = Mat::zeros(bgMat.rows, bgMat.cols, bgMat.type());
//		}
//
//		sumMat.push_back(frame); //储存frame
//
//
//		////计算均值
//		//for (int j = 0; j < n1; j++) {
//		//	for (int i = 0; i < nc; i++) {
//		//		meanMat.at<uchar>(j, i) = meanMat.at<uchar>(j, i) + frame.at<uchar>(j, i) / n;  //将所有的平均值存入一个mat
//		//	}
//		//}
//
//	}
//
//	int n1 = bgMat.rows;
//	int nc = bgMat.cols;
//
//	//计算方差
//	for (int j = 0; j < bgMat.rows; j++) {
//		for (int i = 0; i < bgMat.cols; i++) {
//
//			//均值
//			for (int k = 0; k < n; k++) {
//				meanMat.at<uchar>(j, i) += sumMat[k].at<uchar>(j, i)/n;  //将所有的平均值存入一个mat
//			}
//
//			for (int k = 0; k < n; k++) {
//				varMat.at<uchar>(j, i) += pow((sumMat[k].at<uchar>(j, i) - meanMat.at<uchar>(j, i)),2)/n;  
//			}
//			//方差
//			//varMat.at<uchar>(j, i) = (int)sqrt(varMat.at<uchar>(j, i));
//
//		}
//	}
//
//	imshow("均值", meanMat);  //记得二值化，不然会只有1/3，，，，，
//	waitKey(30);
//
//	imshow("方差", varMat);
//	waitKey(30);
//
//
//
//	//检测差分并二值化
//	int th=0.7; //高斯二值化时的权值
//
//	while (1) {
//		
//
//		bool rSucess = cap.read(frame);
//		cvtColor(frame, frame, COLOR_BGR2GRAY);
//
//		if (!rSucess)
//		{
//			std::cout << "不能从视频文件中读取帧" << std::endl;
//			break;
//		}
//
//		
//		for (int j = 0; j < frame.rows; j++) {
//			for (int i = 0; i < frame.cols; i++) {
//
//				int sub;
//				sub = abs(frame.at<uchar>(j, i) - meanMat.at<uchar>(j, i));
//
//				int Th=th * varMat.at<uchar>(j, i);
//
//				if (sub > Th) {
//					dstMat.at<uchar>(j, i) = 255;
//				}
//				else {
//					dstMat.at<uchar>(j, i) = 0;  //dstMat 要记得初始化，不然会报错
//				}
//			}
//		}
//
//
//		imshow("高斯背景差分", dstMat);
//
//		waitKey(30); //不能为0，间隔30读
//
//	}
//}
