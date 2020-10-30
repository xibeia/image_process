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
//			std::cout << "不能打开视频文件" << std::endl;
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
//				std::cout << "不能从视频文件中读取帧" << std::endl;
//				break;
//			}
//			else
//			{
//				//练习1，2,3
//				medianBlur(frame, frame_medianBlur, 3);
//				blur(frame, frame_blur, Size(3,3));
//				GaussianBlur(frame, frame_Gau,Size(5,5),0,0);
//
//				imshow("原图", frame);
//				imshow("中值滤波", frame_medianBlur);
//				imshow("均值滤波", frame_blur);
//				imshow("高斯滤波", frame_Gau);
//
//				//练习4
//				Sobel(frame, dxframe, CV_16SC1, 1, 0, 3);
//				convertScaleAbs(dxframe, dxframe);
//				Sobel(frame, dyframe, CV_16SC1, 0, 1, 3);				
//				convertScaleAbs(dyframe, dyframe);
//				
//				//看到好多红点点，用高斯滤波后的试试
//				Sobel(frame_Gau, dyframe_Gau, CV_16SC1, 0, 1, 3);
//				convertScaleAbs(dyframe_Gau, dyframe_Gau);
//
//				imshow("dx边缘提取", dxframe);
//				imshow("dy边缘提取", dyframe);
//				imshow("高斯滤波后的dy边缘提取", dyframe_Gau);  //高斯滤波后可以看出来噪点明显减少
//
//
//			}
//			waitKey(30);
//		}
//}