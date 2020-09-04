#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv)  {
	Mat image = imread("show.jpeg");

	if (image.empty()) {
		cout<<"Could not find or open the file"<<endl;
		cin.get(); // wait for keypress
		return -1;
	}

	Mat imageContrastHigh2;
	image.convertTo(imageContrastHigh2,-1,2,0);

	Mat imageContrastHigh4;
	image.convertTo(imageContrastHigh4,-1,4,0);

	Mat imageContrastlow0_5;
	image.convertTo(imageContrastlow0_5,-1,0.5,0);

	Mat imageContrastlow0_25;
	image.convertTo(imageContrastlow0_25,-1,0.25,0);

	string windowOriginal = "Orignal image";
	string windowhigh2 = "High 2";
	string windowhigh4 = "High 4";
	string windowlow0_5 = "Low 0_5";
	string windowlow0_25 = "Low 0_25";

	// Create and open windows for above images

	namedWindow(windowOriginal,WINDOW_NORMAL);
	namedWindow(windowhigh2,WINDOW_NORMAL);
	namedWindow(windowhigh4,WINDOW_NORMAL);
	namedWindow(windowlow0_5,WINDOW_NORMAL);
	namedWindow(windowlow0_25,WINDOW_NORMAL);

	// Show above images inside the created windows

	imshow(windowOriginal,image);
	imshow(windowhigh2,imageContrastHigh2);
	imshow(windowhigh4,imageContrastHigh4);
	imshow(windowlow0_5,imageContrastlow0_5);
	imshow(windowlow0_25,imageContrastlow0_25);

	waitKey(0); // Wait for any key stroke

	destroyAllWindows(); // Destroy every windows;

	return 0;
}