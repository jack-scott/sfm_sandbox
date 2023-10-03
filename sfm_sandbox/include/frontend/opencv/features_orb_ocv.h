#ifndef FEATURES_ORB_CV_H
#define FEATURES_ORB_CV_H

#include "frontend/feature_detector.h"

#include <opencv2/features2d.hpp>

class ORBFeatureDetectorCV : public FeatureDetector
{
public:
    ORBFeatureDetectorCV();
    ~ORBFeatureDetectorCV();
    void detect(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints);
    void compute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
    void detectAndCompute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
private:
    cv::Ptr<cv::ORB> detector;
};

#endif // FEATURES_ORB_CV_H
