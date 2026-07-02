#include <QCoreApplication>
#include <QDebug>
#include <opencv2/core.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    cv::Mat m = cv::Mat::eye(3, 3, CV_8U);
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    std::cout << "Matrix(0,0): " << static_cast<int>(m.at<unsigned char>(0, 0)) << std::endl;
    qInfo() << "Qt version:" << QT_VERSION_STR;

    return 0;
}
