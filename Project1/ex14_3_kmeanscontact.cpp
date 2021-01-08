#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int createMaskByKmeans(cv::Mat src, cv::Mat & mask)
{
	if ((mask.type() != CV_8UC1)
		|| (src.size() != mask.size())
		) {
		return 0;
	}

	int width = src.cols;
	int height = src.rows;

	int pixNum = width * height;

	int clusterCount = 2;

	Mat labels;
	Mat centers;

	//����kmeans�õ�����
	Mat sampleData = src.reshape(3, pixNum);
	Mat km_data;
	sampleData.convertTo(km_data, CV_32F);

	//ִ��kmeans
	TermCriteria criteria = TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 0.1);
	kmeans(km_data, clusterCount, labels, criteria, clusterCount, KMEANS_PP_CENTERS, centers);

	//����mask
	uchar fg[2] = { 0,255 };
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			mask.at<uchar>(row, col) = fg[labels.at<int>(row*width + col)]; //����k-means�������õ�mask
		}
	}

	return 0;
}


int main() {

	VideoCapture srccap, drgcap;
	srccap.open("bg.mp4");
	drgcap.open("dragon.mp4");

	if (!srccap.isOpened() || !drgcap.isOpened())
	{
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
		return -1;
	};

	Mat srcframe, drgframe;

	double srcfps = srccap.get(CAP_PROP_FPS);
	std::cout << "src:fps" << srcfps << std::endl;

	double drgfps = drgcap.get(CAP_PROP_FPS);
	std::cout << "dragon:fps" << drgfps << std::endl;

	Mat drggray;
	Mat mask;
	Mat maskinv;

	Mat dragonFront, srcFront, filimg;

	while (1) {

		drgcap >> drgframe;
		srccap >> srcframe;

		//Mat mask = Mat::zeros(drgframe.size(), CV_8UC1);
		//createMaskByKmeans(drgframe, mask);
		// ��kmeans��ȡmaskЧ������,������ֱ�Ӷ�ֵ��


		//�����ҶȻ�
		cvtColor(drgframe, drggray, CV_BGR2GRAY);
		//���Ҷ�ֵ��ֵ�����õ�ͼ����ģ,��ʱ����mask�Ǻڵļ�Ϊ0
		threshold(drggray, mask, 100, 255, THRESH_BINARY);
		//�����Ϊ�׵�
		bitwise_not(mask, maskinv);

		imshow("mask", mask);
		imshow("maskinv", maskinv);


		//��ȡ����
		bitwise_and(drgframe, drgframe, dragonFront, maskinv);

		imshow("��ǰ��", dragonFront);

		////��ȡ����
		bitwise_and(srcframe, srcframe, srcFront, mask);  //?������

		//////ǰ�������ں�
		add(dragonFront, srcFront, filimg);

		//add(drgframe, srcframe, filimg);

		imshow("��ǰ��", dragonFront);
		imshow("��������", srcFront);

		imshow("�ںϺ�", filimg);

		waitKey(30);
	}



}