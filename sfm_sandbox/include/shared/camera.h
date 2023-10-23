#ifndef CAMERA_H
#define CAMERA_H

#include <opencv4/opencv2/calib3d.hpp>
#include <opencv4/opencv2/core.hpp>

#include "shared/sfm_types.h"

namespace sfm {
class Camera {
 private:
  std::string name;
  CameraModel model;
  DistortionModel distortion_model;
  cv::Mat K;
  cv::Mat distortion;
  cv::Size resolution;

 public:
  // Constructor
  Camera(const std::string& name, cv::Size resolution, CameraModel model = CameraModel::PINHOLE,
         DistortionModel distortion_model = DistortionModel::RADTAN,
         cv::Mat K = cv::Mat::eye(3, 3, CV_64F), cv::Mat distortion = cv::Mat::zeros(1, 5, CV_64F));
  void undistortImage(const cv::Mat& image, cv::Mat& undistorted_image);
  void undistortPoints(const std::vector<cv::Point2f>& points,
                       std::vector<cv::Point2f>& undistorted_points);
};

}  // namespace sfm

#endif  // CAMERA_H