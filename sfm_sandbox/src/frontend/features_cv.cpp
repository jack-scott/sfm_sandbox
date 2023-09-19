#include "frontend/features_cv.h"

class ORBFeatureDetectorCV : public FeatureDetector
{
public:
    ORBFeatureDetectorCV()
    {
        detector = cv::ORB::create();
    }
    ~ORBFeatureDetectorCV()
    {
    }
    void detect(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints)
    {
        detector->detect(image->getImage(), keypoints);
    }
    void compute(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors)
    {
        detector->compute(image->getImage(), keypoints, descriptors);
    }
    void detectAndCompute(std::shared_ptr<Image> image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors)
    {
        detector->detectAndCompute(image->getImage(), cv::noArray(), keypoints, descriptors);
    }