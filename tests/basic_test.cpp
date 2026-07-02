#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include <QString>

TEST(SmokeTest, OpenCVMatrixIdentity) {
    cv::Mat matrix = cv::Mat::eye(2, 2, CV_8U);
    EXPECT_EQ(static_cast<int>(matrix.at<unsigned char>(0, 0)), 1);
    EXPECT_EQ(static_cast<int>(matrix.at<unsigned char>(0, 1)), 0);
}

TEST(SmokeTest, QtStringConstruction) {
    QString value = QStringLiteral("Test1_Client");
    EXPECT_FALSE(value.isEmpty());
    EXPECT_EQ(value.toStdString(), std::string("Test1_Client"));
}