#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void imgconvert(cv::Mat &image) {
	int n1 = image.rows;
	int nc = image.cols;
	for (int j = 0; j < n1; j++) {
		for (int i = 0; i < nc; i++) {
			image.at<uchar>(j, i) = 255 - image.at<uchar>(j, i);
		}
	}
}

//��ֵ������,��Ҫ˼���Ǳ���ÿ�У�����������Ϊ�׵Ļ��ܱ߾���Ϊ�ڵģ�Ȼ��������ȥ
void edgeConvertBlack(cv::Mat &image) {

	int n1 = image.rows;
	int nc = image.cols;
	//����߿�ʼ����
	for (int j = 1; j < n1; j++) {
		for (int i = 1; i < nc; i++) {
			if (image.at<uchar>(j-1, i)==255&& image.at<uchar>(j, i)==255)
			{
				image.at<uchar>(j-1, i) = 0; //��⵽�׵�ת��Ϊ�ڵ�
				image.at<uchar>(j, i) = 0;
				image.at<uchar>(j, i-1) = 0;
				image.at<uchar>(j-1, i-1) = 0;
			}
			else
			{
				break;
			}
		}
	}
}

void edgeConvertWhite(cv::Mat &image) {

	int n1 = image.rows;
	int nc = image.cols;
	//����߿�ʼ����
	for (int j = 1; j < n1; j++) {
		for (int i = 1; i < nc; i++) {
			if (image.at<uchar>(j - 1, i) == 255 && image.at<uchar>(j, i) == 255)
			{
				image.at<uchar>(j - 1, i) = 0; //��⵽�׵�ת��Ϊ�ڵ�
				image.at<uchar>(j, i) = 0;
			}
			else
			{
				continue;
			}
		}
	}
}


int main() {
	Mat srcMat, thresold_img;
	srcMat = imread("������.jpg", 0);
	imshow("ԭͼ", srcMat);

	imgconvert(srcMat);
	imshow("�ڰ�ת��", srcMat);

	threshold(srcMat, thresold_img, 100, 255, THRESH_OTSU);  //��򷨶�ֵ��
	imshow("��ֵͼ", thresold_img);

	edgeConvertBlack(thresold_img);
	imshow("ȥ����Ե", thresold_img);

	Mat stats;
	Mat centroids;
	Mat labels;


	//��ͼ���ȸ�ʴȥ���
	int g_nStructElementSize = 3; //�ṹԪ��(�ں˾���)�ĳߴ�
	Mat element = getStructuringElement(MORPH_RECT,
		Size(g_nStructElementSize, g_nStructElementSize));

	Mat erode_cv,dilated_cv, dilated_cv2;
	erode (thresold_img, erode_cv, element);
	imshow("��ʴȥ���", erode_cv);

	Mat element2 = getStructuringElement(MORPH_RECT,
		Size(10,10));  //MORPH_ELLIPSE
	Mat element3 = getStructuringElement(MORPH_CROSS, Size(5, 5));  //7*7ʮ������

	dilate(erode_cv, dilated_cv, element3);
	imshow("���ͺ�", dilated_cv); 
	dilate(dilated_cv, dilated_cv2, element2);
	imshow("��������", dilated_cv2);


	int num_labels = connectedComponentsWithStats(dilated_cv2, labels, stats, centroids, 8, CV_32S);
	cout << num_labels - 1 << endl;


	waitKey(0);
	return 0;
}





