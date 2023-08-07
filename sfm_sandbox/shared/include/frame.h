#ifndef FRAME_H
#define FRAME_H

#include <opencv4/opencv2/core.hpp>
#include <gtsam/geometry/Pose3.h>
#include "image.h"
#include "sfmTypes.h"

class Frame {
private:
    Camera& camera;
    Image& image;
    Image& depth;
    Image& mask;
    cv::Mat descriptors;
    std::vector<cv::KeyPoint> keypoints;
    gtsam::Pose3 pose;

public:
    // Constructor
    Frame(Camera& camera, Image& rgb_image);
    Frame(Camera& camera, Image& rgb_image, gtsam::Pose3 pose);

    // Getters
    Camera& getCamera();
    Image& getImage();
    Image& getDepth();
    Image& getMask();
    cv::Mat getDescriptors();
    std::vector<cv::KeyPoint> getKeypoints();
    gtsam::Pose3 getPose();

    // Setters
    void setPose(gtsam::Pose3 pose);
};


#endif // FRAME_H