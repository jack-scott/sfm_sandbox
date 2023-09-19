#ifndef FEATURE_DETECTOR_H
#define FEATURE_DETECTOR_H

#include <vector>

#include <opencv4/opencv2/core.hpp>

#include "shared/image.h"
#include "shared/frame.h"


class FeatureDetector
{
public:
    virtual void detect(std::shared_ptr<cv::Mat> image, std::vector<cv::KeyPoint>& keypoints) = 0;
    virtual void compute(std::shared_ptr<cv::Mat>, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) = 0;
    virtual void detectAndCompute(std::shared_ptr<cv::Mat>, std::vector<cv::KeyPoint>& keypoints, cv::Mat& descriptors) = 0;
    virtual ~FeatureDetector() {};

    void detect(std::vector<std::shared_ptr<Image>> images, std::vector<std::vector<cv::KeyPoint>>& keypoints){
        for (auto image : images){
            std::vector<cv::KeyPoint> image_keypoints;
            detect(image->getData(), image_keypoints);
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
        for (int i = 0; i < images.size(); i++){
            std::vector<cv::KeyPoint> image_keypoints = keypoints[i];
            cv::Mat image_descriptors;
            compute(images[i]->getData(), image_keypoints, image_descriptors);
            keypoints[i] = image_keypoints;
            descriptors.push_back(image_descriptors);
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
        for (int i = 0; i < images.size(); i++){
            std::vector<cv::KeyPoint> image_keypoints;
            cv::Mat image_descriptors;
            detectAndCompute(images[i]->getData(), image_keypoints, image_descriptors);
            keypoints.push_back(image_keypoints);
            descriptors.push_back(image_descriptors);
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

#endif // FEATURE_DETECTOR_H