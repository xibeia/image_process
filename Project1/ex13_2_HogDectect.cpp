#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;


float normL2(float * a, float * b, int n);
int calcHog(Mat src, float * hist, int nAngle, int cellSize);


int main()
{
	Mat refMat = imread("img13_ref.jpg", 0); //����hogʱҪ��ͨ����ȡ,��������
	Mat srcMat = imread("img13_src.jpg", 0);


	int nAngle = 8;
	int cellSize = 16;
	int nX = refMat.cols / cellSize;
	int nY = refMat.rows / cellSize;

	int bins = nX * nY*nAngle;

	//�����ڴ�
	float * ref_hist = new float[bins];
	memset(ref_hist, 0, sizeof(float)*bins);
	//float * box_hist = new float[bins];
	//memset(box_hist, 0, sizeof(float)*bins);
	

	//����refMat��hog
	int reCode = 0;
	reCode = calcHog(refMat, ref_hist, nAngle, cellSize);
	if (reCode != 0) {
		////�ͷ��ڴ�
		delete[] ref_hist;
		return -1;
	}

	Rect rect;
	Mat BoxMat;
	Point pos;
	int cnt = 0;
	float distance, dist;

	
	for (int i = 0; i < srcMat.rows - refMat.rows + 1; i++)
	{
		for (int j = 0; j < srcMat.cols - refMat.cols + 1; j++)
		{
			//�����ڴ棬Ҫ�����涨�壬���涨���в��
			float * box_hist = new float[bins];
			memset(box_hist, 0, sizeof(float)*bins);
			//ȡ��һ��box
			rect = Rect(j, i, refMat.cols, refMat.rows);
			BoxMat = srcMat(rect);

			//����box��hog
			calcHog(BoxMat, box_hist, nAngle, cellSize);
			//�������ƶ�
			dist = normL2(ref_hist, box_hist, bins);

			//�������ƶȣ��ҵ�������С�ģ���dist��С�ĵط���distԽС�����ƶ�Խ��
			if (cnt == 0)
			{
				distance = dist;
				pos.x = j;
				pos.y = i;
				cnt++;
			}
			else
			{
				if (dist < distance)
				{
					distance = dist;
					pos.x = j; 
					pos.y = i;
				}
			}
			//�ͷ��ڴ�
			delete[] box_hist;
		}
	}

	rectangle(srcMat, pos, Point(pos.x + refMat.cols, pos.y + refMat.rows), Scalar(255, 0, 0), 1, 8, 0); //ע����ɫ����ͨ���ڰ�
	
	//�ͷ��ڴ�
	delete[] ref_hist;
	//delete[] box_hist;


	imshow("��⵽��ͼ��", srcMat);

	waitKey(0);
	return 0;

}

int calcHog(cv::Mat src, float * hist, int nAngle,int cellSize) {  
	
	//��ֹcellsize���ù���

	if (cellSize > src.cols || cellSize > src.rows) {
		cout << "cellSize is out!" << endl;
		return -1;
	}
	
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

