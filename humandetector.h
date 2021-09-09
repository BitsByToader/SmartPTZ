#ifndef HUMANDETECTOR_H
#define HUMANDETECTOR_H

//Qt libs
#include <QObject>
#include <QVector>
#include <QDebug>
//OpenCV libs
#include <opencv2/opencv.hpp>

class HumanDetector : public QObject {
    Q_OBJECT
public:
    explicit HumanDetector(QObject *parent = nullptr);
    std::vector<float> getClassifier(cv::Ptr<cv::ml::SVM> classifier);
    QVector<cv::Rect> findHumans(cv::InputArray frame);
    void adjustBox(cv::Rect &box);

private:
    cv::HOGDescriptor hogDescriptor;
    QString classifierPath = "/Users/tudor/Developer/SmartPTZ/svmClassifier";
};

#endif // HUMANDETECTOR_H
