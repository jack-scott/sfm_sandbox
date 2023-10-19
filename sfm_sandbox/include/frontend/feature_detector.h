#ifndef FEATURE_DETECTOR_H
#define FEATURE_DETECTOR_H

#include <vector>

#include <opencv4/opencv2/core.hpp>
#include <glog/logging.h>


#include "shared/image.h"
#include "shared/frame.h"

//TODO: Const all through here?
namespace sfm{

class FeatureDetector
{
protected:
    virtual void detect(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints) = 0;
    virtual void compute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) = 0;
    virtual void detectAndCompute(const std::shared_ptr<cv::Mat>& image, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) = 0;
    virtual ~FeatureDetector() {};

public:
    void detect(std::vector<std::shared_ptr<Image>> images, std::vector<std::vector<cv::KeyPoint>>& keypoints){
        for (size_t i = 0; i < images.size(); i++){
            detect(images[i]->getData(), keypoints[i]);
        }
    }

    void detect(std::shared_ptr<Frame> frame){
        std::vector<cv::KeyPoint> keypoints;
        detect(frame->getImage()->getData(), keypoints);
        frame->setKeypoints(keypoints);
    }

    void detect(std::vector<std::shared_ptr<Frame>> frames){
        for (auto frame : frames){
            std::vector<cv::KeyPoint> image_keypoints;
            detect(frame->getImage()->getData(), image_keypoints);
            frame->setKeypoints(image_keypoints);
        }
    }

    void compute(std::vector<std::shared_ptr<Image>> images, std::vector<std::vector<cv::KeyPoint>>& keypoints, std::vector<cv::Mat>& descriptors)
    {
        CHECK_EQ(images.size(), keypoints.size());
        CHECK_EQ(images.size(), descriptors.size());

        for (size_t i = 0; i < images.size(); i++){
            compute(images[i]->getData(), keypoints[i], descriptors[i]);
        }
    }

    void compute(std::shared_ptr<Frame> frame){
        std::vector<cv::KeyPoint> keypoints = frame->getKeypoints();
        cv::Mat descriptors;
        compute(frame->getImage()->getData(), keypoints, descriptors);
        frame->setKeypoints(keypoints);
        frame->setDescriptors(descriptors);
    }

    void compute(std::vector<std::shared_ptr<Frame>> frames){
        for (auto frame : frames){
            std::vector<cv::KeyPoint> image_keypoints = frame->getKeypoints();
            cv::Mat image_descriptors;
            compute(frame->getImage()->getData(), image_keypoints, image_descriptors);
            frame->setKeypoints(image_keypoints);
            frame->setDescriptors(image_descriptors);
        }
    }

    void detectAndCompute(std::vector<std::shared_ptr<Image>> images, std::vector<std::vector<cv::KeyPoint>>& keypoints, std::vector<cv::Mat>& descriptors)
    {
        CHECK_EQ(images.size(), keypoints.size());
        CHECK_EQ(images.size(), descriptors.size());
        for (size_t i = 0; i < images.size(); i++){
            detectAndCompute(images[i]->getData(), keypoints[i], descriptors[i]);
        }
    }

    void detectAndCompute(std::shared_ptr<Frame> frame){
        std::vector<cv::KeyPoint> keypoints;
        cv::Mat descriptors;
        detectAndCompute(frame->getImage()->getData(), keypoints, descriptors);
        frame->setKeypoints(keypoints);
        frame->setDescriptors(descriptors);
    }

    void detectAndCompute(std::vector<std::shared_ptr<Frame>> frames){
        for (auto frame : frames){
            std::vector<cv::KeyPoint> image_keypoints;
            cv::Mat image_descriptors;
            detectAndCompute(frame->getImage()->getData(), image_keypoints, image_descriptors);
            frame->setKeypoints(image_keypoints);
            frame->setDescriptors(image_descriptors);
        }
    }

};

} // namespace sfm
#endif // FEATURE_DETECTOR_H