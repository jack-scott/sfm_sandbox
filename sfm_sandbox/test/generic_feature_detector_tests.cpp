#include "frontend/feature_detector.h"
#include "frontend/opencv/features_orb_ocv.h"


#include <iostream>
#include <filesystem>

#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


#include "shared/image.h"
#include "shared/frame.h"
#include "shared/camera.h"
#include "shared/sfm_types.h"

class GenericFeatureDetectorTest : public ::testing::Test
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

TEST_F(GenericFeatureDetectorTest, test_from_image_vector)
{
    Image image1(image_path, true); 
    Image image2(image_path, true);
    std::vector <std::shared_ptr<Image>> images;
    images.push_back(image1);
    images.push_back(image2);

    Camera  camera1("test", CameraModel::PINHOLE , cv::Mat, cv::Mat, cv::Size(640, 480)); 
    Frame frame1(camera1, image1);

    std::vector<cv::KeyPoint> keypoints1;
    std::vector<cv::KeyPoint> keypoints2;
    std::vector<std::vector<cv::KeyPoint>> keypoints_vec;
    keypoints_vec.push_back(keypoints1);
    keypoints_vec.push_back(keypoints2);
    cv::Mat descriptors;

    ORBFeatureDetectorCV detector;
    
    
    detector.detect(images, keypoints_vec);

    //check that the number of keypoints is not zero
    EXPECT_TRUE(keypoints.size() > 0);

    detector.compute(images, keypoints_vec, descriptors);
    EXPECT_TRUE(descriptors.size().height > 0);
    EXPECT_TRUE(descriptors.size().width > 0);

}