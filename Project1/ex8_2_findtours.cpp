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
//	Mat srcMat, srcMat2, thresold_img;
//	srcMat = imread("оƬ.jpg", 0);//��ͨ��
//	srcMat2 = imread("оƬ.jpg", 1);//��ͨ��
//	if (srcMat.empty()) return -1;
//
//	imshow("ԭͼ", srcMat);
//
//	//imgconvert(srcMat);
//	//imshow("�ڰ�ת��", srcMat);
//
//	threshold(srcMat, thresold_img, 250, 255, THRESH_OTSU);  //��򷨶�ֵ��
//	imshow("��ֵͼ", thresold_img);
//
//	//оƬ�м��кܶ��ߣ���ʴһ�£���������
//	Mat element = getStructuringElement(MORPH_RECT,Size(3,3));
//	
//	Mat moropenimg;
//	morphologyEx(thresold_img, moropenimg, MORPH_OPEN, element);
//	imshow("������", moropenimg);
//
//
//	//ͨ��finvontoursѰ����ͨ��
//	vector<vector<Point>>  contours;
//	vector<Vec4i> hierachy;
//
//	findContours(moropenimg, contours, hierachy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	//CV_RETR_EXTERNAL ֻ�������Χ������CV_CHAIN_APPROX_NONE�����������㵽contours������
//
//	for (int i = 0; i < contours.size(); ++i) {
//		RotatedRect rbox = minAreaRect(contours[i]);
//
//		float width = rbox.size.width;
//		float height = rbox.size.height;
//
//		float kk = width / height;
//		float ci_area = width * height;  //����ı��ε����
//
//		int contour_area =contourArea(contours[i]);  //��ͨ�����
//
//		if (kk > 0.9&& contour_area > 400) {  //ȡ�ӽ�Բ�εģ������ģ����������ȥ��С���
//			//��������
//			drawContours(srcMat2, contours, i, Scalar(0, 255, 255), 1, 8);
//
//			////������С����ı���
//			//Point2f vtx[4];
//			//for (int j = 0; j < 4; ++j) {
//			//	line(srcMat2, vtx[j], vtx[j < 3 ? j + 1 : 0], Scalar(0, 255, 255), 2, CV_AA);
//			//}
//
//			Rect r = boundingRect(Mat(contours[i]));
//			rectangle(srcMat2, r, Scalar(0, 0, 255), 2);
//		}
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
