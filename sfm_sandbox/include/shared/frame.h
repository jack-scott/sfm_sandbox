#ifndef FRAME_H
#define FRAME_H

#include <opencv4/opencv2/core.hpp>
#include <gtsam/geometry/Pose3.h>

#include "shared/image.h"
#include "shared/camera.h"
#include "shared/sfm_types.h"

class Frame {
private:
    std::shared_ptr<Camera> camera_;
    std::shared_ptr<Image> image_;
    std::shared_ptr<Image> depth_;
    std::shared_ptr<Image> mask_;
    cv::Mat descriptors_;
    std::vector<cv::KeyPoint> keypoints_;
    gtsam::Pose3 pose_;

public:
    // Constructor
    Frame(std::shared_ptr<Camera> camera, std::shared_ptr<Image> rgb_image);
    Frame(std::shared_ptr<Camera> camera, std::shared_ptr<Image> rgb_image, gtsam::Pose3 pose);

    // Getters
    std::shared_ptr<Camera> getCamera();
    std::shared_ptr<Image> getImage();
    std::shared_ptr<Image> getDepth();
    std::shared_ptr<Image> getMask();
    cv::Mat getDescriptors();
    void setDescriptors(cv::Mat descriptors);
    std::vector<cv::KeyPoint> getKeypoints();
    void setKeypoints(std::vector<cv::KeyPoint> keypoints);
    gtsam::Pose3 getPose();

    // Setters
    void setPose(gtsam::Pose3 pose);
};


#endif // FRAME_H