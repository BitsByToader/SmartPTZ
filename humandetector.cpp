#include "humandetector.h"

HumanDetector::HumanDetector(QObject *parent) : QObject(parent) {
    //Initialize the HoG Descriptor
    this->hogDescriptor = cv::HOGDescriptor();//(cv::Size(48, 96), cv::Size(16, 16), cv::Size(8, 8), cv::Size(8, 8), 9);
    this->hogDescriptor.winSize = cv::Size(96, 160);
    this->hogDescriptor.cellSize = cv::Size(4, 4);

    //Get the classifier from the file
    cv::Ptr<cv::ml::SVM> classifier = cv::ml::SVM::load("/Users/tudor/Developer/SmartPTZ/svmClassifier");
    qDebug()<< "Loaded classifier!";

    //Set the classifier
    this->hogDescriptor.setSVMDetector(this->getClassifier(classifier));
//    this->hogDescriptor.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
    qDebug()<<"Classifier set!";
}

std::vector<float> HumanDetector::getClassifier(cv::Ptr<cv::ml::SVM> classifier) {
    // get the support vectors
    cv::Mat svm = classifier->getSupportVectors();
    // get the decision function
    cv::Mat alpha, svidx;
    double rho = classifier->getDecisionFunction(0, alpha, svidx);

    // create a variable to return the support vectors in desired type
    std::vector<float> hogDetector(svm.cols + 1);
    memcpy(&hogDetector[0], svm.ptr(), svm.cols*sizeof(hogDetector[0]));
    hogDetector[svm.cols] = static_cast<float>(- rho);
    return hogDetector;
}

QVector<cv::Rect> HumanDetector::findHumans(cv::InputArray frame) {
    std::vector<cv::Rect> foundRectangles;
    qDebug()<<"Began finding the humans!";
    this->hogDescriptor.detectMultiScale(frame, foundRectangles);
//    this->hogDescriptor.detectMultiScale(frame, foundRectangles, 0, cv::Size(8,8), cv::Size(), 1.05, 2, false);
    qDebug()<<"Found humans in a frame!";

    return QVector<cv::Rect>(foundRectangles.begin(), foundRectangles.end());
}

void HumanDetector::adjustBox(cv::Rect &box) {
    //The detector will make the boxes slightly bigger than the actual human, so we're adjusting that lo look prettier.
    box.x += cvRound(box.width*0.1);
    box.width = cvRound(box.width*0.8);
    box.y += cvRound(box.height*0.07);
    box.height = cvRound(box.height*0.8);
}
