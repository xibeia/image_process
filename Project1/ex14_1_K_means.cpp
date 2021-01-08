//#include<iostream>
//#include<opencv2/opencv.hpp>
//
//using namespace cv;
//using namespace std;
//
//
//int main() {
//	const int MAX_CLUSTERS = 5;
//	Scalar colorTab[] = {
//		Scalar(0,0,255),
//		Scalar(0,255,0),
//		Scalar(255,100,100),
//		Scalar(255,0,255),
//		Scalar(0,255,255)
//	};
//	Mat img(500, 500, CV_8UC3);
//	//随机数生成类
//	RNG rng(12345); 
//
//	for (;;) {
//		int k, clusterCount = rng.uniform(2, MAX_CLUSTERS + 1);
//		//随机生成类和样本的数量
//		int i, sampleCount = rng.uniform(1, 1001);
//		//保存样本坐标
//		Mat points(sampleCount, 1, CV_32FC2), labels;
//
//		clusterCount = MIN(clusterCount, sampleCount);
//		std::vector<Point2f> centers;
//
//		for (k = 0; k < clusterCount; k++) {
//			Point center;
//			center.x = rng.uniform(0, img.cols);
//			center.y = rng.uniform(0, img.rows);
//			//生成各个类的样本
//			Mat pointChunk = points.rowRange(k*sampleCount / clusterCount, k == clusterCount - 1 ?
//				sampleCount : (k + 1)*sampleCount / clusterCount);
//			//对矩阵填充随机数
//			rng.fill(pointChunk,
//				RNG::NORMAL,
//				Scalar(center.x, center.y),
//				Scalar(img.cols*0.05, img.rows*0.05));
//		}
//
//		randShuffle(points, 1, &rng);   //因为要聚类，所以先随机打乱points里面的点，注意points和pointChunk是共用数据的。
//
//		double compactness=kmeans(points, clusterCount, labels,
//			TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 10, 1.0),
//			3, KMEANS_PP_CENTERS, centers);  //聚类3次，取结果最好的那次，聚类的初始化采用PP特定的随机算法。
//
//		img = Scalar::all(0);
//
//		for (i = 0; i < sampleCount; i++)
//		{
//			int clusterIdx = labels.at<int>(i);
//			Point ipt = points.at<Point2f>(i);
//			circle(img, ipt, 2, colorTab[clusterIdx], CV_FILLED, CV_AA);
//		}
//
//		for (i = 0; i < (int)centers.size(); ++i)
//		{
//			Point2f c = centers[i];
//			circle(img, c, 40, colorTab[i], 1, LINE_AA);
//		}
//		cout << "Compactness: " << compactness << endl;
//
//		imshow("clusters", img);
//
//		char key = (char)waitKey();     //无限等待
//		if (key == 27 || key == 'q' || key == 'Q') // 'ESC' 按q退出
//			break;
//	}
//
//	return 0;
//}