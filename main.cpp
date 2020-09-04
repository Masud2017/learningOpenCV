#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat image = imread("show.jpeg");
	Mat image2(600,800,CV_8UC3,Scalar(100,250,30));
	VideoCapture cap("showvid.mp4");

	if (cap.isOpened() == false) {
		cout <<"Cannot open the video error code 404"<<endl;
		cin.get(); // wait for any keystroke
		return -1;
	}

	if (image.empty()) {
		cout << "Could not open or find the image"<<endl;
		cin.get(); // wait for any key press
		return -1;
	}


	string windowName2 = "Custome photo";
	string windowName = "Pikachu the adorable pokemon"; // Name of the window
	
	namedWindow(windowName); // Creat a window
	namedWindow(windowName2);
	imshow(windowName,image); // Show our image inside the creted window.
	imshow(windowName2,image2);
	waitKey(0); // Wait for any keystroke in the window

	double fps = cap.get(CAP_PROP_FPS);
	double totalFrame = cap.get(CAP_PROP_FRAME_COUNT);
	cout << "Frames per seconds : "<<fps<<endl;
	cout << "Total frame count : "<<totalFrame<<endl;
	string window_name = "Playing the video";

	namedWindow(window_name);

	while(true) {
		Mat frame;
		bool bSuccess = cap.read(frame); // Read a new frame from a video

		if (bSuccess == false) {
			cout <<"Found the end of the video"<<endl;
			break;
		}
		imshow(window_name,frame);

		if (waitKey(10) == 27) {
			cout <<"Esc key is pressed by the user, Quiting the video"<<endl;
			break;
		}
	}
	destroyWindow(window_name);

	destroyWindow(windowName); // Destory the created window
	destroyWindow(windowName2);

	return 0;
} 