include "frame.h"


Frame::Frame(Camera& camera, Image& rgb_image) : camera(camera), image(rgb_image) {
    //Might need to initialise depth and mask here
}

Frame::Frame(Camera& camera, Image& rgb_image, gtsam::Pose3 pose) : camera(camera), image(rgb_image), pose(pose) {
    //Might need to initialise depth and mask here
}


gtsam::Pose3 setPose(gtsam::Pose3 pose) {
    this->pose = pose;
}


Camera& Frame::getCamera() {
    return camera;
}

Image& Frame::getImage() {
    return image;
}

Image& Frame::getDepth() {
    return depth;
}

Image& Frame::getMask() {
    return mask;
}

cv::Mat Frame::getDescriptors() {
    return descriptors;
}

std::vector<cv::KeyPoint> Frame::getKeypoints() {
    return keypoints;
}

gtsam::Pose3 Frame::getPose() {
    return pose;
}
