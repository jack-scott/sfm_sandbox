#ifndef FEATURES_ORB_CV_H
#define FEATURES_ORB_CV_H

#include "frontend/feature_detector.h"

#include <opencv2/features2d.hpp>

namespace feature_detector{

class ORBFeatureDetectorCV : public FeatureDetector
{
public:
    ORBFeatureDetectorCV();
    ~ORBFeatureDetectorCV();
    using FeatureDetector::detect;
    using FeatureDetector::compute;
    using FeatureDetector::detectAndCompute;
    void detect(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints);
    void compute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
    void detectAndCompute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
private:
    cv::Ptr<cv::ORB> detector;
};

} // namespace feature_detector

#endif // FEATURES_ORB_CV_H
