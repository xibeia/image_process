//#include<iostream>
//#include<opencv2/opencv.hpp>
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
//	double fps = cap.get(CV_CAP_PROP_FPS);//��ȡFPS ��֡�� 
//	std::cout << "fps" << fps << std::endl;
//
//
//	Mat subMat;//��� 
//
//	Mat bgMat; //����
//
//	int cnt = 0;
//
//	while (1) {
//		Mat frame; //����֡
//
//		bool rSucess = cap.read(frame);
//		
//		if (!rSucess)
//		{
//			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
//			break;
//		}
//
//
//		if (cnt == 0) {
//			frame.copyTo(bgMat);
//	
//		}
//		else
//		{
//			//cap >> frame;//��֡��frame  
//			//�ӵڶ�֡��ʼ�������
//			absdiff(frame, bgMat, subMat);
//
//			//��ֽ����ֵ��
//			threshold(subMat, subMat, 100, 255, THRESH_BINARY);
//
//			imshow("ֱ�Ӳ��", subMat);
//
//
//		}
//		cnt++;
//
//		waitKey(30); //����Ϊ0�����30��
//
//	}
//}