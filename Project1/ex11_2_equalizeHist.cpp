//#include <iostream>  
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main()
//{
//
//	Mat srcimg = imread("ֱ��ͼ��ǿ.jpg");
//
//	if (!srcimg.data)
//	{
//		printf("����ʧ��");
//		return -1;
//	}
//
//	imshow("ԭͼ", srcimg);
//
//	Mat dst;
//
//
//	std::vector<cv::Mat> vchannels;
//	cv::split(srcimg, vchannels);
//
//	//�Ը���ͨ��ֱ��ͼ���⻯  
//	for (int i = 0; i < srcimg.channels(); i++) {
//
//		//Mat mm = vchannels.at(i);
//
//		equalizeHist(vchannels[i], vchannels[i]);  //����ÿ��ͨ��
//	}
//	
//	//�ϲ�ͨ��  
//	merge(vchannels, dst);
//
//	imshow("��ͨ��ֱ��ͼ����", dst);
//
//
//	waitKey(0);
//	return 0;
//}