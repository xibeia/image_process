//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//int main() {
//	Mat srcMat, srcMat2, dstMat;
//	srcMat2 = imread("���.jpg", 1); //��ȡ��ͨ�� ��ע����滭ͼʱ�������ȡ��ͨ�����滭ͼ����ʾ�Һ�ɫ�������ٶ�����ͨ��ͼ
//	srcMat = imread("���.jpg", 0); //��ȡ��ͨ��
//	if (srcMat.empty()) return -1;
//
//	Mat threhold_img, canny_img;
//
//	threshold(srcMat, threhold_img, 100, 255, THRESH_BINARY);
//	Canny(threhold_img, canny_img, 100, 200, 3);
//	 
//	Mat lines;
//	HoughLinesP(canny_img, lines, 1, CV_PI / 180, 30, 0, 20);
//
//	//����˼��
//	//������һ�����������������a, ������ڵ���aʱ��������
//	//�����ڶ������������ֱ�ߵ���С����b��ֱ�߳���С��bʱ���������Ҫ��������е�ֱ�ߣ�������Ϊ0
//	//����������������ֱ���ϵĵ��������ڸõ�������ʾ����
//	//��ʵ����2,3��������Щ��ͬ���ɹ̶�һ������һ��
//
//
//	for (int i = 0; i < lines.rows; i++)
//	{
//		Vec4i  myline = lines.at<Vec4i>(i);
//		line(srcMat2, Point(myline[0], myline[1]), Point(myline[2], myline[3]), Scalar(255, 0, 0), 1, CV_AA);
//	}
//
//
//	imshow("��Ե", canny_img);
//	imshow("ԭͼ", srcMat2);
//
//
//
//	waitKey(0);
//
//	return 0;
//}