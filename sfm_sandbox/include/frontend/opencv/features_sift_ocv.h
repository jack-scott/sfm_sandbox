#ifndef FEATURES_SIFT_CV_H
#define FEATURES_SIFT_CV_H

#include "frontend/feature_detector.h"

#include <opencv2/features2d.hpp>

namespace sfm{

class SIFTFeatureDetectorCV : public FeatureDetector
{
public:
    SIFTFeatureDetectorCV();
    ~SIFTFeatureDetectorCV();
    using FeatureDetector::detect;
    using FeatureDetector::compute;
    using FeatureDetector::detectAndCompute;
    void detect(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints);
    void compute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
    void detectAndCompute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
private:
    cv::Ptr<cv::SIFT> detector;
};
} // namespace sfm
#endif // FEATURES_SIFT_CV_H