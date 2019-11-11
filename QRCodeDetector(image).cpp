#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("../_res/qrcode_ie.bmp");

	if (src.empty()) {
		cerr << "Video open failed!" << endl;
		return -1;
	}

	QRCodeDetector detector;
	vector<Point> points;
	String info = detector.detectAndDecode(src, points);

	if (!info.empty()) {
		polylines(src, points, true, Scalar(0, 0, 255), 2);
		cout << info << endl;
		String link = "explorer ";
		link += info;
		system(link.c_str());
	}

	imshow("src", src);

	waitKey();
	destroyAllWindows();

	return 0;
}