// ConsoleApplication2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("../_res/airplane.bmp", IMREAD_COLOR);
	Mat mask = imread("../_res/mask_plane.bmp", IMREAD_GRAYSCALE);
	Mat dst = imread("../_res/field.bmp", IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	src.copyTo(dst, mask);

	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
    return 0;
}