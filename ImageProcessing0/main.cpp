#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {
	string imageName("avto.jpg");
	Mat InputImage = imread(imageName.c_str(), IMREAD_COLOR);

	namedWindow(imageName);
	namedWindow("Result");

	imshow(imageName, InputImage);

	if (InputImage.empty()) {
		cout << "Could not open or find the image: " << imageName << endl;
		return -1;
	}

	/* IProcessing GrayScale.Max*/
	int Max;

	for (int i = 0; i < InputImage.rows; i++) {
		for (int j = 0; j < InputImage.cols; j++) {
			Max = -1;

			for (int k = 0; k < 3; k++) {
				if (InputImage.at<Vec3b>(i, j)[k] > Max)
					Max = InputImage.at<Vec3b>(i, j)[k];
			}

			InputImage.at<Vec3b>(i, j)[0] = Max; //B
			InputImage.at<Vec3b>(i, j)[1] = Max; //G
			InputImage.at<Vec3b>(i, j)[2] = Max; //R
		}
	}

	imshow("Result", InputImage);

	waitKey(0);
	return 0;
}