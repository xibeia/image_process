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
//		Mat frame, frame_medianBlur, frame_blur, frame_Gau;
//		Mat dxframe, dyframe;
//		Mat dyframe_Gau;
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
//				blur(frame, frame_blur, Size(3,3));
//				GaussianBlur(frame, frame_Gau,Size(5,5),0,0);
//
//				imshow("ԭͼ", frame);
//				imshow("��ֵ�˲�", frame_medianBlur);
//				imshow("��ֵ�˲�", frame_blur);
//				imshow("��˹�˲�", frame_Gau);
//
//				//��ϰ4
//				Sobel(frame, dxframe, CV_16SC1, 1, 0, 3);
//				convertScaleAbs(dxframe, dxframe);
//				Sobel(frame, dyframe, CV_16SC1, 0, 1, 3);				
//				convertScaleAbs(dyframe, dyframe);
//				
//				//�����ö���㣬�ø�˹�˲��������
//				Sobel(frame_Gau, dyframe_Gau, CV_16SC1, 0, 1, 3);
//				convertScaleAbs(dyframe_Gau, dyframe_Gau);
//
//				imshow("dx��Ե��ȡ", dxframe);
//				imshow("dy��Ե��ȡ", dyframe);
//				imshow("��˹�˲����dy��Ե��ȡ", dyframe_Gau);  //��˹�˲�����Կ�����������Լ���
//
//
//			}
//			waitKey(30);
//		}
//}