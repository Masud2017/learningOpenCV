#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
	vector<string> userString;     
	userString.push_back("G-Version");
	userString.push_back("R-Version");
	userString.push_back("B-Version");

	Mat image = imread("show.jpeg"); // Reading the image
	Mat imageChannel[3];

	split(image,imageChannel); // Spliting the image into 3 different color
	for (int i = 0; i < 3; i++) {
		namedWindow(userString[i]);
		imshow(userString[i],imageChannel[i]);
	}

	imageChannel[2] = Mat::zeros(imageChannel[2].size(),CV_8UC1);

	Mat output;
	merge(imageChannel,3,output);

	imshow("Merged version",output);
	waitKey(0);
	destroyAllWindows();
	return 0;
}