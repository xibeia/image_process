//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//	Mat srcMat,thresold_img;
//	srcMat = imread("Ӳ��.jpg",0);
//	threshold(srcMat, thresold_img, 100, 255, THRESH_BINARY);
//
//	imshow("��ֵͼ", thresold_img);
//	//����ṹ����
//	int g_nStructElementSize = 3; //�ṹԪ��(�ں˾���)�ĳߴ�
//	Mat element = getStructuringElement(MORPH_RECT,
//		Size(g_nStructElementSize, g_nStructElementSize));
//	/*��������ĵ�һ��������ʾ�ں˵���״����������״����ѡ��
//	���Σ�MORPH_RECT;
//	�����Σ�MORPH_CROSS;
//	��Բ�Σ�MORPH_ELLIPSE;*/
//	Mat erode_cv,dilated_cv,morcloseimg,moropenimg;
//	
//	erode(thresold_img,erode_cv, element);
//	imshow("��ʴ��", erode_cv);
//
//	dilate(thresold_img, dilated_cv, element);
//	imshow("���ͺ�", dilated_cv);
//
//	morphologyEx(thresold_img, morcloseimg, MORPH_CLOSE, element); 
//	imshow("������", morcloseimg);
//
//	morphologyEx(thresold_img, moropenimg, MORPH_OPEN, element);
//	imshow("������", moropenimg);
//
//	/*
//	enum { MORPH_ERODE=CV_MOP_ERODE, MORPH_DILATE=CV_MOP_DILATE,
//	   MORPH_OPEN=CV_MOP_OPEN,
//	   MORPH_CLOSE=CV_MOP_CLOSE,
//	   MORPH_GRADIENT=CV_MOP_GRADIENT,
//	   MORPH_TOPHAT=CV_MOP_TOPHAT,
//	   MORPH_BLACKHAT=CV_MOP_BLACKHAT };
//	*/
//
//	waitKey(0);
//	return 0;
//}