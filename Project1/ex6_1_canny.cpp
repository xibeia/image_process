//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//		VideoCapture cap;
//		cap.open(0);
//		if (!cap.isOpened())
//		{
//			std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
//			return -1;
//		}
//	
//		double fps = cap.get(CAP_PROP_FPS);
//		std::cout << "fps" << fps << std::endl;
//
//		Mat frame, frame_medianBlur;
//		Mat dxframe,dyframe,frame_canny;
//
//		while (1) {
//			
//			bool rSucess = cap.read(frame);
//			if (!rSucess)
//			{
//				std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
//				break;
//			}
//			else
//			{
//				//��ϰ1��2,3
//				medianBlur(frame, frame_medianBlur, 3);
//
//				Sobel(frame, dxframe, CV_16SC1, 1, 0, 3);
//				Sobel(frame, dyframe, CV_16SC1, 0, 1, 3);
//
//				Canny(dxframe, dyframe,frame_canny, 50, 100);
//
//				imshow("ԭͼ", frame);
//				imshow("��ֵ�˲�", frame_medianBlur);
//				imshow("canny��Ե��ȡ", frame_canny);
//
//		
//
//
//			}
//			waitKey(30);
//		}
//}