#ifndef FEATURES_ORB_CV_H
#define FEATURES_ORB_CV_H

#include "frontend/feature_detector.h"

#include <opencv2/features2d.hpp>

namespace sfm {

class ORBFeatureDetectorCV : public FeatureDetector {
 public:
  ORBFeatureDetectorCV();
  ~ORBFeatureDetectorCV();
  using FeatureDetector::compute;
  using FeatureDetector::detect;
  using FeatureDetector::detectAndCompute;
  void detect(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints);
  void compute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints,
               cv::Mat& descriptors);
  void detectAndCompute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints,
                        cv::Mat& descriptors);

 private:
  cv::Ptr<cv::ORB> detector;
};

}  // namespace sfm
#endif  // FEATURES_ORB_CV_H
