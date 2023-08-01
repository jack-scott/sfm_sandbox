#ifndef FRAME_H
#define FRAME_H

#include <opencv4/opencv2/core.hpp>
#include <gtsam/geometry/Pose3.h>
#include "sfmTypes.h"

class Frame {
private:
    Camera& camera;
    cv::Mat image;
    cv::Mat depth;
    cv::Mat mask;
    cv::Mat descriptors;
    std::vector<cv::KeyPoint> keypoints;
    gtsam::Pose3 pose;

public:
    // Constructor
    Frame(Camera& camera, cv::Mat image);
    Frame(Camera& camera, cv::Mat image, gtsam::Pose3 pose);
    // Getters
    Camera& getCamera();
    cv::Mat getImage();
    cv::Mat getDepth();
    cv::Mat getMask();
    cv::Mat getDescriptors();
    std::vector<cv::KeyPoint> getKeypoints();
    gtsam::Pose3 getPose();

    // Setters
    void setPose(gtsam::Pose3 pose);
};


#endif // FRAME_H