#include "camera.h"

Camera::Camera(std::string name, CameraModel model, DistortionModel distortion_model,
               cv::Mat K = cv::Mat::eye(3, 3, CV_64F),
               cv::Mat distortion = cv::Mat::zeros(1, 5, CV_64F), cv::Size resolution = cv::Size())
    : name(name),
      model(model),
      distortion_model(distortion_model),
      K(K),
      distortion(distortion),
      resolution(resolution) {
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