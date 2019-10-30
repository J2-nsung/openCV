#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

Mat src;
Mat dst;
Mat dst1;
Point2f srcQuad[4], dstQuad[4];

void on_mouse_src(int event, int x, int y, int flags, void* userdata);
void on_mouse_dst(int event, int x, int y, int flags, void* userdata);

int main()
{
	src = imread("../_res/card_noise.jpg", IMREAD_GRAYSCALE);
	dst = Mat::zeros(src.rows, src.cols, CV_8UC1);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	bilateralFilter(src, dst1, -1, 20, 5);

	namedWindow("src");
	setMouseCallback("src", on_mouse_src);
	imshow("src", dst1);

	namedWindow("dst");
	setMouseCallback("dst", on_mouse_dst);
	imshow("dst", dst);

	waitKey();

	return 0;
}

void on_mouse_src(int event, int x, int y, int flags, void*) {
	static int cnt = 0;

	if (event == EVENT_LBUTTONDOWN) {
		if (cnt < 4) {
			srcQuad[cnt++] = Point2f(x, y);

			circle(dst1, Point(x, y), 5, Scalar(0, 0, 255), -1);
			imshow("src", dst1);
		}
	}
}

void on_mouse_dst(int event, int x, int y, int flags, void*) {
	static int cnt = 0;

	if (event == EVENT_LBUTTONDOWN) {
		if (cnt < 4) {
			dstQuad[cnt++] = Point2f(x, y);

			circle(dst, Point(x, y), 5, Scalar(255, 255, 255), -1);
			imshow("dst", dst);

			if (cnt == 4) {
				Mat pers = getPerspectiveTransform(srcQuad, dstQuad);
				warpPerspective(dst1, dst, pers, Size(src.cols, src.rows));

				imshow("dst", dst);
			}
		}
	}
}
