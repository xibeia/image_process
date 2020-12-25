#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;


float normL2(float * a, float * b, int n);
int calcHog(Mat src, float * hist, int nAngle, int cellSize);


int main()
{
	Mat refMat = imread("img13_ref.jpg", 0); //计算hog时要单通道读取,检测的物体
	Mat srcMat = imread("img13_src.jpg", 0);


	int nAngle = 8;
	int cellSize = 16;
	int nX = refMat.cols / cellSize;
	int nY = refMat.rows / cellSize;

	int bins = nX * nY*nAngle;

	//分配内存
	float * ref_hist = new float[bins];
	memset(ref_hist, 0, sizeof(float)*bins);
	//float * box_hist = new float[bins];
	//memset(box_hist, 0, sizeof(float)*bins);
	

	//计算refMat的hog
	int reCode = 0;
	reCode = calcHog(refMat, ref_hist, nAngle, cellSize);
	if (reCode != 0) {
		////释放内存
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
			//开辟内存，要在里面定义，外面定义有差错，
			float * box_hist = new float[bins];
			memset(box_hist, 0, sizeof(float)*bins);
			//取出一个box
			rect = Rect(j, i, refMat.cols, refMat.rows);
			BoxMat = srcMat(rect);

			//计算box的hog
			calcHog(BoxMat, box_hist, nAngle, cellSize);
			//计算相似度
			dist = normL2(ref_hist, box_hist, bins);

			//更新相似度，找到距离最小的，即dist最小的地方，dist越小，相似度越大
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
			//释放内存
			delete[] box_hist;
		}
	}

	rectangle(srcMat, pos, Point(pos.x + refMat.cols, pos.y + refMat.rows), Scalar(255, 0, 0), 1, 8, 0); //注意颜色，单通道黑白
	
	//释放内存
	delete[] ref_hist;
	//delete[] box_hist;


	imshow("检测到的图像", srcMat);

	waitKey(0);
	return 0;

}

int calcHog(cv::Mat src, float * hist, int nAngle,int cellSize) {  
	
	//防止cellsize设置过大

	if (cellSize > src.cols || cellSize > src.rows) {
		cout << "cellSize is out!" << endl;
		return -1;
	}
	
	int nX = src.cols / cellSize; //横向block个数
	int nY = src.rows / cellSize; //纵向block个数
	int binAngle = 360 / nAngle;

	Mat gx, gy;
	Mat mag, angle;

	Sobel(src, gx, CV_32F, 1, 0, 1);
	Sobel(src, gy, CV_32F, 0, 1, 1);

	//将直角坐标系转到极坐标系，默认输出为弧度,radians，也可以选择角度;mag, angle为输出的幅度值与角度值
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

			//取图像的一个cell
			roi.x = j * cellSize;
			roi.y = i * cellSize;

			roiMat = src(roi);  
			roiMag = mag(roi);
			roiAgl = angle(roi);

			int head = (i*nX + j)*nAngle;  //当前Cell在数组中的位置

			//统计直方图信息
			for (int n = 0; n < roiMat.rows; n++) {
				for (int m = 0; m < roiMat.cols; m++) {

					//计算角度在哪个区间（8个），通过int自动取整实现
					int pos = (int)(roiAgl.at<float>(n, m) / binAngle);
					//以像素点的值为权重
					hist[head + pos] += roiMag.at<float>(n, m);
				}
			}


		}
	}

	return 0;
}

//计算直方图相似度，欧几里得距离
float normL2(float * hist1, float * hist2, int size) {

	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (hist1[i] - hist2[i])*(hist1[i] - hist2[i]);

	}
	sum = sqrt(sum);

	return sum;

}

