#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("../_res/building.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	vector<KeyPoint> keypoints;
	FAST(src, keypoints, 60, true);

	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);

	for (KeyPoint kp : keypoints) {
		Point pt(cvRound(kp.pt.x), cvRound(kp.pt.y));
		circle(dst, pt, 5, Scalar(0, 0, 255), 2);
	}

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();

	return 0;
}