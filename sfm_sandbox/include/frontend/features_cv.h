#ifndef FEATURES_CV_H
#define FEATURES_CV_H

#include "frontend/feature_detector.h"

class ORBFeatureDetectorCV : public FeatureDetector
{
public:
    ORBFeatureDetectorCV();
    ~ORBFeatureDetectorCV();
    void detect(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints);
    void compute(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
    void detectAndCompute(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
private:
    cv::Ptr<cv::ORB> detector;
};


class SIFTFeatureDetectorCV : public FeatureDetector
{
public:
    SIFTFeatureDetectorCV();
    ~SIFTFeatureDetectorCV();
    void detect(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints);
    void compute(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
    void detectAndCompute(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors);
private:
    cv::Ptr<cv::SIFT> detector;
};


#endif // FEATURES_CV_H