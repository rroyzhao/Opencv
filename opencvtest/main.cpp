#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

/////////////////////////////////////////实验一///////////////////////////////////////////
void lab1_1() {
	Mat a = imread("C:/Users/ruiru/Pictures/Saved Pictures/IMG_1992.JPG", IMREAD_UNCHANGED);
	namedWindow("a", WINDOW_AUTOSIZE);
	imshow("a", a);
	waitKey(0);
}

void lab1_2() {
	Mat a = imread("C:/Users/ruiru/Pictures/Saved Pictures/IMG_1992.JPG", IMREAD_UNCHANGED);
	namedWindow("a", WINDOW_AUTOSIZE);
    for (int nrow = 0; nrow < a.rows; nrow++)
    {
        uchar* data = a.ptr<uchar>(nrow);
        for (int ncol = 0; ncol < a.cols * a.channels(); ncol++)
        {
            cout << int(data[ncol]) << ",";
        }
        cout << endl;
    }
    imshow("a", a);
    waitKey(0);
}

int lab1_3_1() {
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        return -1;
    }
    Mat frame;
    Mat edges;

    bool stop = false;
    while (!stop)
    {
        cap >> frame;
        imshow("当前视频", frame);
        if (waitKey(30) >= 0)
            stop = true;
    }
    return 0;
}

int lab1_3_2() {
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        return -1;
    }
    Mat frame;
    Mat edges;

    bool stop = false;
    while (!stop)
    {
        cap >> frame;
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        blur(edges, edges, Size(7, 7));
        Canny(edges, edges, 0, 30, 3);
        imshow("被Canny后的视频", edges);

        if (waitKey(30) >= 0)
            stop = true;
    }
}

int lab1_3_3() {
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        return -1;
    }
    Mat frame;
    Mat edges;

    bool stop = false;
    while (!stop)
    {
        cap >> frame;

        for (int nrow = 0; nrow < frame.rows; nrow++) {
            uchar* data = frame.ptr<uchar>(nrow);
            for (int ncol = 0; ncol < frame.cols * frame.channels(); ncol++) {
                if (ncol % 3 == 0) {
                    data[ncol] = 0;
                }
            }
        }

        imshow("当前视频", frame);
        if (waitKey(30) >= 0)
            stop = true;
    }
}
/////////////////////////////////////////实验一///////////////////////////////////////////

int main()
{
    ////////////////实验一////////////////
	//lab1_1();
    //lab1_2();
    //lab1_3_1();
    //lab1_3_2();
    lab1_3_3();
    ////////////////实验一////////////////

    //实验二
}
