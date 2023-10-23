#include "camera.h"

#include <opencv4/opencv2/core.hpp>

namespace sfm {

Camera::Camera(const std::string& name, cv::Size resolution, CameraModel model,
               DistortionModel distortion_model, cv::Mat K, cv::Mat distortion)
    : name(name),
      resolution(resolution),
      model(model),
      distortion_model(distortion_model),
      K(K),
      distortion(distortion) {
  // constructor body
}

void Camera::undistortImage(const cv::Mat& image, cv::Mat& undistorted_image) {
  if (distortion_model == DistortionModel::NONE) {
    undistorted_image = image.clone();
    return;
  } else if (distortion_model == DistortionModel::RADTAN) {
    cv::undistort(image, undistorted_image, K, distortion);
    return;
  } else if (distortion_model == DistortionModel::EQUIDISTANT) {
    cv::fisheye::undistortImage(image, undistorted_image, K, distortion);
    return;
  }
}

void Camera::undistortPoints(const std::vector<cv::Point2f>& points,
                             std::vector<cv::Point2f>& undistorted_points) {
  if (distortion_model == DistortionModel::NONE) {
    undistorted_points = points;
    return;
  } else if (distortion_model == DistortionModel::RADTAN) {
    cv::undistortPoints(points, undistorted_points, K, distortion);
    return;
  } else if (distortion_model == DistortionModel::EQUIDISTANT) {
    cv::fisheye::undistortPoints(points, undistorted_points, K, distortion);
    return;
  }
}

}  // namespace sfm
