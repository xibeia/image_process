//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//
//void colorReduce(cv::Mat &image) {
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//
//			uchar ave = (image.at<Vec3b>(j, i)[0] + image.at<Vec3b>(j, i)[1] + image.at<Vec3b>(j, i)[2]) / 3;
//			image.at<Vec3b>(j, i)[0] = ave;
//			image.at<Vec3b>(j, i)[1] = ave;
//			image.at<Vec3b>(j, i)[2] = ave;
//		}
//
//	}
//}
//
//
//void colorReduce2(cv::Mat &image,uchar  threshold = 100) {
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//
//			uchar ave = (image.at<Vec3b>(j, i)[0] + image.at<Vec3b>(j, i)[1] + image.at<Vec3b>(j, i)[2]) / 3;
//			if (ave>threshold)
//			{
//				image.at<Vec3b>(j, i)[0] = 255;
//				image.at<Vec3b>(j, i)[1] = 255;
//				image.at<Vec3b>(j, i)[2] = 255;
//			}
//			else
//			{
//				image.at<Vec3b>(j, i)[0] = 0;
//				image.at<Vec3b>(j, i)[1] = 0;
//				image.at<Vec3b>(j, i)[2] = 0;
//			}
//			
//			
//		}
//
//	}
//}
//
//
//int main() {
//	cv::Mat imgsrc;
//	imgsrc = imread("D:/������ѧϰ����/����ͼ����/lenna.jpg");
//	namedWindow("ͼƬ");
//	imshow("ͼƬ", imgsrc);
//	waitKey(0);
//
//	// ��ʾ����1���ͼƬ���Ҷ�   
//	colorReduce(imgsrc);
//	namedWindow("����1");
//	imshow("����1", imgsrc);
//	waitKey(0);
//
//	//����2�Ҷ�
//	cv::Mat img2;
//	img2 = imread("D:/������ѧϰ����/����ͼ����/lenna.jpg", 0);
//	namedWindow("����2");
//	imshow("����2", img2);
//	waitKey(0);
//
//	//����3����ֵͼ��
//	cv::Mat img3;
//	img3 = imread("D:/������ѧϰ����/����ͼ����/lenna.jpg");
//	colorReduce2(img3);
//	namedWindow("����3");
//	imshow("����3", img3);
//	waitKey(0);
//	
//	//����4
//	cv::Mat srcMat,deepMat, shallowMat;
//	srcMat= imread("D:/������ѧϰ����/����ͼ����/lenna.jpg");
//	shallowMat = srcMat;  //ǳ����
//	srcMat.copyTo(deepMat);  //���
//	colorReduce2(srcMat);
//
//	namedWindow("ǳ����");
//	imshow("ǳ����", shallowMat);
//	waitKey(0);
//
//	namedWindow("���");
//	imshow("���", deepMat);
//	waitKey(0);
//
//	return 0;
//
//}
