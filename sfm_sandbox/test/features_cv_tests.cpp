#include "frontend/opencv/features_sift_ocv.h"
#include "frontend/opencv/features_orb_ocv.h"

#include <iostream>
#include <filesystem>

#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


class FeaturesCVTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        //add generic setup
        const std::string relative_image_path = "../test/monkey.png";
        const std::filesystem::path current_dir = std::filesystem::current_path();
        const std::filesystem::path image_file = current_dir / relative_image_path;

        image_path = image_file.string();
    }

    void TearDown() override
    {
        // Clean up any resources allocated in SetUp().
    }

    std::string image_path;
};

TEST_F(FeaturesCVTest, test_orb_features)
{
    // Test that loadData loads the image data correctly.
    std::shared_ptr<cv::Mat> img = std::make_shared<cv::Mat>(cv::imread(image_path, cv::IMREAD_COLOR));
    EXPECT_FALSE(img->empty());

    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;

    ORBFeatureDetectorCV detector;
    detector.detectAndCompute(img, keypoints, descriptors);

    //check that the number of keypoints is not zero
    EXPECT_TRUE(keypoints.size() > 0);
    //check that the number of descriptors is not zero
    EXPECT_TRUE(descriptors.size().height > 0);
    EXPECT_TRUE(descriptors.size().width > 0);

    std::vector<cv::KeyPoint> keypoints2;
    detector.detect(img, keypoints2);
    EXPECT_TRUE(keypoints2.size() > 0);

    cv::Mat descriptors2;
    detector.compute(img, keypoints2, descriptors2);
    EXPECT_TRUE(descriptors2.size().height > 0);
    EXPECT_TRUE(descriptors2.size().width > 0);

}



TEST_F(FeaturesCVTest, test_sift_features)
{
    // Test that loadData loads the image data correctly.
    std::shared_ptr<cv::Mat> img = std::make_shared<cv::Mat>(cv::imread(image_path, cv::IMREAD_COLOR));
    EXPECT_FALSE(img->empty());

    std::vector<cv::KeyPoint> keypoints;
    cv::Mat descriptors;

    SIFTFeatureDetectorCV detector;
    detector.detectAndCompute(img, keypoints, descriptors);

    //check that the number of keypoints is not zero
    EXPECT_TRUE(keypoints.size() > 0);
    //check that the number of descriptors is not zero
    EXPECT_TRUE(descriptors.size().height > 0);
    EXPECT_TRUE(descriptors.size().width > 0);

    std::vector<cv::KeyPoint> keypoints2;
    detector.detect(img, keypoints2);
    EXPECT_TRUE(keypoints2.size() > 0);

    cv::Mat descriptors2;
    detector.compute(img, keypoints2, descriptors2);
    EXPECT_TRUE(descriptors2.size().height > 0);
    EXPECT_TRUE(descriptors2.size().width > 0);

}
