//#include <iostream>  
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//
//	Mat srcimg = imread("直方图增强.jpg");
//
//	if (!srcimg.data)
//	{
//		printf("加载失败");
//		return -1;
//	}
//
//	imshow("原图", srcimg);
//
//	Mat dst;
//
//
//	std::vector<cv::Mat> vchannels;
//	cv::split(srcimg, vchannels);
//
//	//对各个通道直方图均衡化  
//	for (int i = 0; i < srcimg.channels(); i++) {
//
//		//Mat mm = vchannels.at(i);
//
//		equalizeHist(vchannels[i], vchannels[i]);  //均衡每个通道
//	}
//	
//	//合并通道  
//	merge(vchannels, dst);
//
//	imshow("三通道直方图均衡", dst);
//
//
//	waitKey(0);
//	return 0;
//}