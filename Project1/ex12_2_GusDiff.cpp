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
//		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
//		return -1;
//	}
//
//	//double fps = cap.get(CAP_PROP_FPS);
//	//std::cout << "fps" << fps << std::endl;
//	//int cnt = cap.get(CV_CAP_PROP_FRAME_COUNT);//��ȡ֡��   ��Ƶ�ļ���֡�� ������ͷ����-1
//	
//	double fps = cap.get(CV_CAP_PROP_FPS);//��ȡFPS  
//	std::cout << "fps" << fps << std::endl;
//
//	Mat frame; //����֡
//	Mat subMat ;//��� 
//	Mat bgMat; //����
//
//
//	vector<Mat> sumMat;
//	Mat meanMat; //��ֵ
//	Mat varMat;  //����
//	Mat dstMat;
//
//	
//
//	int cnt = 0;
//
//	//��ȡn֡��ͼƬ�����ֵ����
//	int n = 10;
//	for (int tt = 0; tt < n; tt++) {
//		
//		bool rSucess = cap.read(frame);
//		
//		//������ͷ��ȡ����ͼ��ת��Ϊ�Ҷ�ͼ
//		cvtColor(frame, frame, COLOR_BGR2GRAY);
//		//threshold(frame, frame, 100, 255, THRESH_BINARY);
//
//		if (!rSucess)
//		{
//			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
//			break;
//		}
//
//		if (tt == 0) {
//			frame.copyTo(bgMat);
//			//��ʼ��meanMat �� varMatΪ0
//			meanMat = Mat::zeros(bgMat.rows, bgMat.cols, bgMat.type());
//			varMat = Mat::zeros(bgMat.rows, bgMat.cols, bgMat.type());
//			dstMat = Mat::zeros(bgMat.rows, bgMat.cols, bgMat.type());
//		}
//
//		sumMat.push_back(frame); //����frame
//
//
//		////�����ֵ
//		//for (int j = 0; j < n1; j++) {
//		//	for (int i = 0; i < nc; i++) {
//		//		meanMat.at<uchar>(j, i) = meanMat.at<uchar>(j, i) + frame.at<uchar>(j, i) / n;  //�����е�ƽ��ֵ����һ��mat
//		//	}
//		//}
//
//	}
//
//	int n1 = bgMat.rows;
//	int nc = bgMat.cols;
//
//	//���㷽��
//	for (int j = 0; j < bgMat.rows; j++) {
//		for (int i = 0; i < bgMat.cols; i++) {
//
//			//��ֵ
//			for (int k = 0; k < n; k++) {
//				meanMat.at<uchar>(j, i) += sumMat[k].at<uchar>(j, i)/n;  //�����е�ƽ��ֵ����һ��mat
//			}
//
//			for (int k = 0; k < n; k++) {
//				varMat.at<uchar>(j, i) += pow((sumMat[k].at<uchar>(j, i) - meanMat.at<uchar>(j, i)),2)/n;  
//			}
//			//����
//			//varMat.at<uchar>(j, i) = (int)sqrt(varMat.at<uchar>(j, i));
//
//		}
//	}
//
//	imshow("��ֵ", meanMat);  //�ǵö�ֵ������Ȼ��ֻ��1/3����������
//	waitKey(30);
//
//	imshow("����", varMat);
//	waitKey(30);
//
//
//
//	//����ֲ���ֵ��
//	int th=0.7; //��˹��ֵ��ʱ��Ȩֵ
//
//	while (1) {
//		
//
//		bool rSucess = cap.read(frame);
//		cvtColor(frame, frame, COLOR_BGR2GRAY);
//
//		if (!rSucess)
//		{
//			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
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
//					dstMat.at<uchar>(j, i) = 0;  //dstMat Ҫ�ǵó�ʼ������Ȼ�ᱨ��
//				}
//			}
//		}
//
//
//		imshow("��˹�������", dstMat);
//
//		waitKey(30); //����Ϊ0�����30��
//
//	}
//}
