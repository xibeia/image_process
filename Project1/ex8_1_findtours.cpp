//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//void imgconvert(cv::Mat &image) {
//	int n1 = image.rows;
//	int nc = image.cols;
//	for (int j = 0; j < n1; j++) {
//		for (int i = 0; i < nc; i++) {
//			image.at<uchar>(j, i) = 255 - image.at<uchar>(j, i);
//		}
//	}
//}
//
//
//
//int main() {
//	Mat srcMat,srcMat2,thresold_img;
//	srcMat = imread("����.png", 0);//��ͨ��
//	srcMat2 = imread("����.png", 1);//��ͨ��
//	if (srcMat.empty()) return -1;
//
//	imshow("ԭͼ", srcMat);
//
//	imgconvert(srcMat);
//	imshow("�ڰ�ת��", srcMat);
//
//	threshold(srcMat, thresold_img, 100, 255, THRESH_OTSU);  //��򷨶�ֵ��
//	imshow("��ֵͼ", thresold_img);
//
//
//
//	//ͨ��finvontoursѰ����ͨ��
//	vector<vector<Point>>  contours;
//	vector<Vec4i> hierachy;
//
//	findContours(thresold_img, contours,hierachy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	//CV_RETR_EXTERNAL ֻ�������Χ������CV_CHAIN_APPROX_NONE�����������㵽contours������
//	//coutous����洢�����е������ĵ�
//
//	for (int i = 0; i < contours.size(); ++i) {
//		RotatedRect rbox = minAreaRect(contours[i]);
//
//		float width = rbox.size.width;
//		float height = rbox.size.height;
//		
//		float kk = width / height;
//		float ci_area = width * height;
//		
//		if (kk > 0.9&& ci_area > 250) {  //ȡ�ӽ�Բ�εģ������ģ����������ȥ��С���
//			//��������
//			drawContours(srcMat2, contours, i, Scalar(0, 255, 255), 1, 8);
//
//			//for (int j = 0; j < contours[i].size(); j++)
//			//{
//			//	//��ǳ�contours�����ڵ����ص�
//			//	Point P = Point(contours[i][j].x, contours[i][j].y);
//			//	srcMat2.at<Vec3b>(P)[0] = 0;
//			//	srcMat2.at<Vec3b>(P)[1] = 255;
//			//	srcMat2.at<Vec3b>(P)[2] = 255;
//			//}  //��drawContours����һ��
//
//			//��������ı���
//			Rect r = boundingRect(Mat(contours[i]));
//			rectangle(srcMat2, r, Scalar(0,0,255), 2);
//		}
//		
//
//	}
//
//	imshow("���ͼ", srcMat2);
//
//
//	waitKey(0);
//	return 0;
//}
//
//
//
//
//
