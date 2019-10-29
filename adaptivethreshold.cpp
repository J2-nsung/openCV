// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

Mat src;
void on_trackbar(int pos, void* userdata);

int main()
{
	src = imread("../_res/sudoku.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed" << endl;
		return -1;
	}

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("Block Size", "dst", 0, 200, on_trackbar, &src);
	setTrackbarPos("Block Size", "dst", 11);

	Mat dst2;
	threshold(src, dst2, 0, 255, THRESH_BINARY | THRESH_OTSU);

	imshow("dst2", dst2);

	waitKey();

	return 0;
}

void on_trackbar(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;

	int bsize = pos;
	if (bsize % 2 == 0) bsize--;
	if (bsize < 3) bsize = 3;

	Mat dst;
	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);
	
	imshow("dst", dst);
}