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

//二值后再用,主要思想是遍历每行，有连续两个为白的话周边就置为黑的，然后再跳出去
void edgeConvertBlack(cv::Mat &image) {

	int n1 = image.rows;
	int nc = image.cols;
	//从左边开始遍历
	for (int j = 1; j < n1; j++) {
		for (int i = 1; i < nc; i++) {
			if (image.at<uchar>(j-1, i)==255&& image.at<uchar>(j, i)==255)
			{
				image.at<uchar>(j-1, i) = 0; //检测到白的转化为黑的
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
	//从左边开始遍历
	for (int j = 1; j < n1; j++) {
		for (int i = 1; i < nc; i++) {
			if (image.at<uchar>(j - 1, i) == 255 && image.at<uchar>(j, i) == 255)
			{
				image.at<uchar>(j - 1, i) = 0; //检测到白的转化为黑的
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
	srcMat = imread("曲别针.jpg", 0);
	imshow("原图", srcMat);

	imgconvert(srcMat);
	imshow("黑白转换", srcMat);

	threshold(srcMat, thresold_img, 100, 255, THRESH_OTSU);  //大津法二值化
	imshow("二值图", thresold_img);

	edgeConvertBlack(thresold_img);
	imshow("去掉边缘", thresold_img);

	Mat stats;
	Mat centroids;
	Mat labels;


	//对图像先腐蚀去噪点
	int g_nStructElementSize = 3; //结构元素(内核矩阵)的尺寸
	Mat element = getStructuringElement(MORPH_RECT,
		Size(g_nStructElementSize, g_nStructElementSize));

	Mat erode_cv,dilated_cv, dilated_cv2;
	erode (thresold_img, erode_cv, element);
	imshow("腐蚀去噪后", erode_cv);

	Mat element2 = getStructuringElement(MORPH_RECT,
		Size(10,10));  //MORPH_ELLIPSE
	Mat element3 = getStructuringElement(MORPH_CROSS, Size(5, 5));  //7*7十字膨胀

	dilate(erode_cv, dilated_cv, element3);
	imshow("膨胀后", dilated_cv); 
	dilate(dilated_cv, dilated_cv2, element2);
	imshow("二次膨胀", dilated_cv2);


	int num_labels = connectedComponentsWithStats(dilated_cv2, labels, stats, centroids, 8, CV_32S);
	cout << num_labels - 1 << endl;


	waitKey(0);
	return 0;
}





