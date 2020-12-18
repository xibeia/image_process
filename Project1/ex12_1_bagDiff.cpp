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
//		std::cout << "不能打开视频文件" << std::endl;
//		return -1;
//	}
//
//	//double fps = cap.get(CAP_PROP_FPS);
//	//std::cout << "fps" << fps << std::endl;
//	//int cnt = cap.get(CV_CAP_PROP_FRAME_COUNT);//获取帧数   视频文件的帧数 ，摄像头返回-1
//	double fps = cap.get(CV_CAP_PROP_FPS);//获取FPS ，帧率 
//	std::cout << "fps" << fps << std::endl;
//
//
//	Mat subMat;//差分 
//
//	Mat bgMat; //背景
//
//	int cnt = 0;
//
//	while (1) {
//		Mat frame; //读入帧
//
//		bool rSucess = cap.read(frame);
//		
//		if (!rSucess)
//		{
//			std::cout << "不能从视频文件中读取帧" << std::endl;
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
//			//cap >> frame;//读帧进frame  
//			//从第二帧开始背景差分
//			absdiff(frame, bgMat, subMat);
//
//			//差分结果二值化
//			threshold(subMat, subMat, 100, 255, THRESH_BINARY);
//
//			imshow("直接差分", subMat);
//
//
//		}
//		cnt++;
//
//		waitKey(30); //不能为0，间隔30读
//
//	}
//}