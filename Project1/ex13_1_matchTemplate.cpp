//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
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
//	Mat tempMat, refMat;
//	Mat frame;
//	Mat disMat; //��ö�����������
//
//	int cnt = 0;
//	while (1) {
//		
//		bool rSucess = cap.read(frame);
//		if (!rSucess)
//		{
//			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
//			break;
//		}
//
//		//ѡȡ��һ֡������
//		if (cnt == 0) {
//			Rect2d r;
//			r = selectROI(frame, true);
//			tempMat = frame(r);
//			tempMat.copyTo(refMat);
//			destroyAllWindows();
//		}	
//
//		//ģ��ƥ��
//		Mat resultMat;//ƥ��Mat���ԭͼ��Сһ��
//		int match_method = 0;
//		matchTemplate(frame, refMat, resultMat, match_method);
//		normalize(resultMat, resultMat, 0, 1, NORM_MINMAX, -1, Mat());
//
//		double minVal;
//		double maxVal;
//		Point minLoc;
//		Point maxLoc;
//
//		Point matchLoc;
//		minMaxLoc(resultMat, &minVal, &maxVal, &minLoc, &maxLoc, Mat()); //Ѱ�Ҽ�ֵ
//
//		//�ж�������Сֵ�������ֵ
//		if (match_method==TM_SQDIFF||match_method==TM_SQDIFF_NORMED)
//		{
//			matchLoc = minLoc;
//		}
//		else
//		{
//			matchLoc = maxLoc;
//		}
//
//
//		frame.copyTo(disMat);
//		Point Loc2;
//		Loc2.x = matchLoc.x + refMat.rows;
//		Loc2.y = matchLoc.y + refMat.cols;
//		rectangle(disMat, matchLoc,Loc2, Scalar(1, 0, 0));
//
//		imshow("�ο�ͼ", refMat);
//		imshow("׷��", disMat);
//		
//
//		cnt++;
//		waitKey(30);
//	}
//
//}