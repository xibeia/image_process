#include<iostream>
#include<opencv2/opencv.hpp>
#include <math.h>

using namespace cv;
using namespace std;


int calcHog(cv::Mat &src, float * hist, int cellSize = 16, int nAngle = 8) {

	int nX = src.cols / cellSize; //����block����
	int nY = src.rows / cellSize; //����block����
	int binAngle = 360 / nAngle;

	Mat gx, gy;
	Mat mag, angle;

	Sobel(src, gx, CV_32F, 1, 0, 1);
	Sobel(src, gy, CV_32F, 0, 1, 1);

	//��ֱ������ϵת��������ϵ��Ĭ�����Ϊ����,radians��Ҳ����ѡ��Ƕ�;mag, angleΪ����ķ���ֵ��Ƕ�ֵ
	cartToPolar(gx, gy, mag, angle, true);

	Rect roi;
	roi.x = 0;
	roi.y = 0;
	roi.width = cellSize;
	roi.height = cellSize;


	for (int i = 0; i < nY; i++) {
		for (int j = 0; j < nX; j++) {
			Mat roiMat;
			Mat roiMag;
			Mat roiAgl;

			//ȡͼ���һ��cell
			roi.x = j * cellSize;
			roi.y = i * cellSize;

			roiMat = src(roi);  
			roiMag = mag(roi);
			roiAgl = angle(roi);

			int head = (i*nX + j)*nAngle;  //��ǰCell�������е�λ��

			//ͳ��ֱ��ͼ��Ϣ
			for (int n = 0; n < roiMat.rows; n++) {
				for (int m = 0; m < roiMat.cols; m++) {

					//����Ƕ����ĸ����䣨8������ͨ��int�Զ�ȡ��ʵ��
					int pos = (int)(roiAgl.at<float>(n, m) / binAngle);
					//�����ص��ֵΪȨ��
					hist[head + pos] += roiMag.at<float>(n, m);
				}
			}


		}
	}

	return 0;
}

//����ֱ��ͼ���ƶȣ�ŷ����þ���
float normL2(float * hist1, float * hist2, int size) {

	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (hist1[i] - hist2[i])*(hist1[i] - hist2[i]);

	}
	sum = sqrt(sum);

	return sum;

}

int main() {

	Mat refMat, plMat, bgMat;
	refMat = imread("hogTemplate.jpg",0);//��ͨ����ȡ����Ȼ����
	plMat = imread("img1.jpg",0);
	bgMat = imread("img2.jpg",0);

	//�ж�ͼƬ�Ƿ���سɹ�
	if ( refMat.empty() || plMat.empty() || bgMat.empty())
	{
		cout << "image load failed!" << endl;
		return -1;
	}

	//������������ͼƬ��HOG
	int cellSize = 16;
	int nAngle = 8;

	int nX = refMat.cols / cellSize; //����block����
	int nY = refMat.rows / cellSize; //����block����
	int bins = nX * nY*nAngle;  //ά��

	//Ϊֱ��ͼ�����ڴ�
	float *ref_hist = new float[bins];
	memset(ref_hist, 0, sizeof(float)*bins);
	float *pl_hist = new float[bins];
	memset(pl_hist, 0, sizeof(float)*bins);
	float *bg_hist = new float[bins];
	memset(bg_hist, 0, sizeof(float)*bins);


	int recCode = 0;

	recCode = calcHog(refMat, ref_hist, nAngle, cellSize);
	recCode = calcHog(plMat, pl_hist, nAngle, cellSize);
	recCode = calcHog(bgMat, bg_hist, nAngle, cellSize);

	//�жϺ����Ƿ����гɹ�
	if (recCode != 0) {
		delete[] ref_hist;
		delete[] pl_hist;
		delete[] bg_hist;

		cout << "calcHog working error" << endl;

		return -1;
	}


	//����ֱ��ͼ����
	float dis1 = normL2(ref_hist, pl_hist, bins);
	float dis2 = normL2(ref_hist, bg_hist, bins);

	cout << "dis1��ԭͼ�����ƶ�Ϊ��" << dis1 << endl;
	cout << "dis2��ԭͼ�����ƶ�Ϊ��" << dis2 << endl;


	//���˭������
	(dis1 <= dis2) ? (std::cout << "img1 is similar" << std::endl) : (std::cout << "img2 is similar" << std::endl);


	imshow("ref", refMat);
	imshow("img1", plMat);
	imshow("img2", bgMat);

	//�ͷ��ڴ�
	delete[] ref_hist;
	delete[] pl_hist;
	delete[] bg_hist;

	waitKey(0);


	return 0;
}