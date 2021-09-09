//Qt libs
#include <QCoreApplication>
#include <QtDebug>
#include <QFile>
//OpenCV libs
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

//Namespaces
using namespace cv;

#include "humandetector.h"

int main(int, char**) {
    Mat frame;

    HumanDetector detector;

    //--- INITIALIZE VIDEOCAPTURE
    VideoCapture cap;

    // open selected camera using selected API
    cap.open("/Users/tudor/Desktop/test3.mp4", CAP_ANY);

    // check if we succeeded
    if (!cap.isOpened()) {
        qDebug() << "ERROR! Unable to open camera\n";
        return -1;
    }
    //--- GRAB AND WRITE LOOP
    qDebug() << "Start grabbing" << Qt::endl
        << "Press any key to terminate" << Qt::endl;

    for (;;) {
        // wait for a new frame from camera and store it into 'frame'
        cap >> frame;

        // check if we succeeded
        if (frame.empty()) {
            qDebug() << "ERROR! blank frame grabbed\n";
            break;
        }

        resize(frame, frame, Size(720, 480));
        cvtColor(frame, frame, COLOR_RGB2GRAY);

        //Find humans in the frame and get the bounding boxes for them;
        QVector<Rect> boxes = detector.findHumans(frame);

        //Places the boxes in frame
        for ( int i = 0; i < boxes.count(); i++ ) {
            Rect &r = boxes[i];
            detector.adjustBox(r);
            rectangle(frame, r.tl(), r.br(), cv::Scalar(255, 0, 0), 2);
        }

        // show live and wait for a key with timeout long enough to show images
        imshow("Webcam", frame);
        if (waitKey(5) >= 0)
            break;
    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
