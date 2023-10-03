#include "frontend/opencv/features_orb_ocv.h"

ORBFeatureDetectorCV::ORBFeatureDetectorCV()
{
    detector = cv::ORB::create();
}
ORBFeatureDetectorCV::~ORBFeatureDetectorCV()
{
}
void ORBFeatureDetectorCV::detect(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints)
{
    detector->detect(*image,  keypoints);
}
void ORBFeatureDetectorCV::compute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors)
{
    detector->compute(*image,  keypoints, descriptors);
}
void ORBFeatureDetectorCV::detectAndCompute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors)
{
    detector->detectAndCompute(*image,  cv::noArray(), keypoints, descriptors);
}