#include "frame.h"


Frame::Frame(std::shared_ptr<Camera> camera, std::shared_ptr<Image> rgb_image) : camera_(camera), image_(rgb_image) {
    //Might need to initialise depth and mask here
}

Frame::Frame(std::shared_ptr<Camera> camera, std::shared_ptr<Image> rgb_image, gtsam::Pose3 pose) : camera_(camera), image_(rgb_image), pose_(pose) {
    //Might need to initialise depth and mask here

}

std::shared_ptr<Camera> Frame::getCamera() {
    return camera_;
}

std::shared_ptr<Image> Frame::getImage() {
    return image_;
}

std::shared_ptr<Image> Frame::getDepth() {
    return depth_;
}

std::shared_ptr<Image> Frame::getMask() {
    return mask_;
}

cv::Mat Frame::getDescriptors() {
    return descriptors_;
}

void Frame::setDescriptors(cv::Mat descriptors) {
    descriptors_ = descriptors;
}

std::vector<cv::KeyPoint> Frame::getKeypoints() {
    return keypoints_;
}

void Frame::setKeypoints(std::vector<cv::KeyPoint> keypoints) {
    keypoints_ = keypoints;
}

gtsam::Pose3 Frame::getPose() {
    return pose_;
}

void Frame::setPose(gtsam::Pose3 pose) {
    pose_ = pose;
}