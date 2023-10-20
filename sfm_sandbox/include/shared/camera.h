#ifndef CAMERA_H
#define CAMERA_H

#include <opencv4/opencv2/calib3d.hpp>
#include <opencv4/opencv2/core.hpp>

#include "shared/sfm_types.h"

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
  Camera(std::string name, CameraModel model, DistortionModel distortion_model, cv::Mat K,
         cv::Mat distortion, cv::Size resolution);

  void undistortImage(const cv::Mat& image, cv::Mat& undistorted_image);
  void undistortPoints(const std::vector<cv::Point2f>& points,
                       std::vector<cv::Point2f>& undistorted_points);
};

#endif  // CAMERA_H