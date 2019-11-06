#include "opencv2/opencv.hpp"
#include<iostream>
using namespace std;
using namespace cv;

void setLabel(Mat& img, const vector<Point>& pts, const String& label) {
	Rect rc = boundingRect(pts);
	rectangle(img, rc, Scalar(0, 0, 255), 1);
	putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
}

int main()
{
	Mat src = imread("../_res/kids.png");

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	CascadeClassifier classifier("../haarcascades/haarcascade_frontalface_default.xml");

	if (classifier.empty()) {
		cerr << "XML load failed!" << endl;
		return -1;
	}

	vector<Rect> faces;
	classifier.detectMultiScale(src, faces);

	for (Rect rc : faces) {
		rectangle(src, rc, Scalar(255, 0, 255), 2);
	}

	imshow("src", src);

	waitKey();
	destroyAllWindows();

	return 0;
}