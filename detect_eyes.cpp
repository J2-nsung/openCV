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

	CascadeClassifier face_classifier("../haarcascades/haarcascade_frontalface_default.xml");
	CascadeClassifier eye_classifier("../haarcascades/haarcascade_eye.xml");

	if (eye_classifier.empty() || face_classifier.empty()) {
		cerr << "XML load failed!" << endl;
		return -1;
	}

	vector<Rect> faces;
	face_classifier.detectMultiScale(src, faces);

	for (Rect face : faces) {
		rectangle(src, face, Scalar(255, 0, 255), 2);

		Mat faceROI = src(face);
		vector<Rect> eyes;
		eye_classifier.detectMultiScale(faceROI, eyes);

		for (Rect eye : eyes) {
			Point center(eye.x + eye.width / 2, eye.y + eye.height / 2);
			circle(faceROI, center, eye.width / 2, Scalar(255, 0, 0), 2, LINE_AA);
		}
	}

	imshow("src", src);

	waitKey();
	destroyAllWindows();

	return 0;
}