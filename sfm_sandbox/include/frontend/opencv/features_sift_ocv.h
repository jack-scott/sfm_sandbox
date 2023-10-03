#ifndef FEATURES_SIFT_CV_H
#define FEATURES_SIFT_CV_H

#include "frontend/feature_detector.h"

#include <opencv2/features2d.hpp>

class SIFTFeatureDetectorCV : public FeatureDetector
{
public:
    SIFTFeatureDetectorCV();
    ~SIFTFeatureDetectorCV();
    void detect(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints);
    void compute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
    void detectAndCompute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
private:
    cv::Ptr<cv::SIFT> detector;
};

#endif // FEATURES_SIFT_CV_H