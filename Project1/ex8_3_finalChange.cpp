#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//ex8_3�����˺ܶ࣬�����ǰ��������ɫ��������һ���⣬ʵ�ڲ��л���һ�ַ�ʽ��
//��ֱ�ӰѺ�ɫ��⵽��Ϊ��ɫ���ɽ�����ͼ����ȷ�����ŵ�RGB��Χ
void RedDetect(cv::Mat &image) {
	int n1 = image.rows;
	int nc = image.cols;
	for (int j = 0; j < n1; j++) {
		for (int i = 0; i < nc; i++) {
			if (image.at<Vec3b>(j, i)[0] < 110 && image.at<Vec3b>(j, i)[1] < 110 && image.at<Vec3b>(j, i)[2] >120) {
				image.at<Vec3b>(j, i)[0] = 255;
				image.at<Vec3b>(j, i)[1] = 255;
				image.at<Vec3b>(j, i)[2] = 255;

			}
			else {
				image.at<Vec3b>(j, i)[0] = 0;
				image.at<Vec3b>(j, i)[1] = 0;
				image.at<Vec3b>(j, i)[2] = 0;
			}
		}
	}
}



int main() {
	Mat srcMat, srcMat2, thresold_img;
	srcMat = imread("�����.jpg", 0);//��ͨ��
	srcMat2 = imread("�����.jpg", 1);//��ͨ��
	if (srcMat.empty()) return -1;
	//imshow("ԭͼ", srcMat);

	//ԭͼ̫���ˣ���Сһ��
	Mat resizeMat, resizeMat2;
	resize(srcMat2, resizeMat, Size(srcMat.cols / 6, srcMat.rows / 6), 0, 0, INTER_LINEAR); //��ͨ��
	resize(srcMat2, resizeMat2, Size(srcMat.cols / 6, srcMat.rows / 6), 0, 0, INTER_LINEAR);  //��ͨ��
	
	imshow("��Сͼ", resizeMat2);
	int flag = 0;
	RedDetect(resizeMat2);

	imshow("��ɫ���ͼ", resizeMat2);
	//���Կ������Դ����ȷ��������ӵ�λ��
	cvtColor(resizeMat2, thresold_img, CV_BGR2GRAY);
	//threshold(resizeMat2, thresold_img, 80, 255, THRESH_OTSU);

	//ͨ��finvontoursѰ����ͨ��
	vector<vector<Point>>  contours;
	vector<Vec4i> hierachy;

	findContours(thresold_img, contours,hierachy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	//CV_RETR_EXTERNAL ֻ�������Χ������CV_CHAIN_APPROX_NONE�����������㵽contours������
	//coutous����洢�����е������ĵ�

	for (int i = 0; i < contours.size(); ++i) {
		RotatedRect rbox = minAreaRect(contours[i]);

		float width = rbox.size.width;
		float height = rbox.size.height;
		
		float kk = width / height;
		float ci_area = width * height;
		

		if (ci_area > 200) {  //ȡ�����ģ����������ȥ��С���
			//��������
			drawContours(resizeMat, contours, i, Scalar(0, 255, 255), 1, 8);

			//��������ı���
			Rect r = boundingRect(Mat(contours[i]));
			rectangle(resizeMat, r, Scalar(0,0,255), 2);
		}
		

	}

	imshow("���ͼ", resizeMat);
	


	waitKey(0);
	return 0;
}



