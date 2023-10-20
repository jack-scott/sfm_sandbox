#include "frontend/feature_detector.h"
#include "frontend/opencv/features_orb_ocv.h"

#include <filesystem>
#include <iostream>

#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include "shared/camera.h"
#include "shared/frame.h"
#include "shared/image.h"
#include "shared/sfm_types.h"

using namespace sfm;
class GenericFeatureDetectorTest : public ::testing::Test {
 protected:
  void SetUp() override {
    //add generic setup
    const std::string relative_image_path = "../test/monkey.png";
    const std::filesystem::path current_dir = std::filesystem::current_path();
    const std::filesystem::path image_file = current_dir / relative_image_path;

    image_path = image_file.string();
  }

  void TearDown() override {
    // Clean up any resources allocated in SetUp().
  }

  std::string image_path;
};

TEST_F(GenericFeatureDetectorTest, test_from_image_vector) {
  std::shared_ptr<Image> image1 = std::make_shared<Image>(image_path, true);
  std::shared_ptr<Image> image2 = std::make_shared<Image>(image_path, true);

  EXPECT_TRUE(image1->isLoaded());
  EXPECT_TRUE(image2->isLoaded());

  std::vector<std::shared_ptr<Image>> images;
  images.push_back(image1);
  images.push_back(image2);

  cv::Mat camera_matrix = cv::Mat::eye(3, 3, CV_64F);
  cv::Mat distortion_coefficients = cv::Mat::zeros(5, 1, CV_64F);
  cv::Size image_size(640, 480);
  Camera camera1("test", CameraModel::PINHOLE, DistortionModel::RADTAN, camera_matrix,
                 distortion_coefficients, image_size);

  Frame frame1(camera1, image1);

  std::vector<cv::KeyPoint> keypoints1;
  std::vector<cv::KeyPoint> keypoints2;
  std::vector<std::vector<cv::KeyPoint>> keypoints_vec;
  keypoints_vec.push_back(keypoints1);
  keypoints_vec.push_back(keypoints2);

  sfm::ORBFeatureDetectorCV detector;

  detector.detect(images, keypoints_vec);

  //check that the number of keypoints is not zero
  EXPECT_TRUE(keypoints_vec[0].size() > 0);
  EXPECT_TRUE(keypoints_vec[1].size() > 0);

  cv::Mat descriptors1;
  cv::Mat descriptors2;
  std::vector<cv::Mat> descriptors_vec;
  descriptors_vec.push_back(descriptors1);
  descriptors_vec.push_back(descriptors2);

  detector.compute(images, keypoints_vec, descriptors_vec);
  EXPECT_TRUE(descriptors_vec[0].size().height > 0);
  EXPECT_TRUE(descriptors_vec[1].size().width > 0);
}