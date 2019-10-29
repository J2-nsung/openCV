// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

Mat src;
void on_threshold(int pos, void* userdata);

int main()
{
	src = imread("../_res/lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return -1;
	}

	Mat dst1;
	int th1 = (int)threshold(src, dst1, 0, 255, THRESH_OTSU);

	namedWindow("dst2");
	createTrackbar("Threshold", "dst2", 0, 255, on_threshold, &src);
	setTrackbarPos("Threshold", "dst2", 128);

	imshow("src", src);
	imshow("dst1", dst1);

	waitKey();

	return 0;
}

void on_threshold(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;

	Mat dst;
	threshold(src, dst, pos, 255, THRESH_BINARY);

	imshow("dst2", dst);
}