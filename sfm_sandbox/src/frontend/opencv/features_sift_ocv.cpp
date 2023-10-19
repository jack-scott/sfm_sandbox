#include "frontend/opencv/features_sift_ocv.h"

namespace sfm{

SIFTFeatureDetectorCV::SIFTFeatureDetectorCV()
{
    detector = cv::SIFT::create();
}
SIFTFeatureDetectorCV::~SIFTFeatureDetectorCV()
{
}
void SIFTFeatureDetectorCV::detect(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints)
{
    detector->detect(*image,  keypoints);
}
void SIFTFeatureDetectorCV::compute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors)
{
    detector->compute(*image,  keypoints, descriptors);
}
void SIFTFeatureDetectorCV::detectAndCompute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors)
{
    detector->detectAndCompute(*image,  cv::noArray(), keypoints, descriptors);
}

} // namespace sfm