#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>

#include "image.h"


Image::Image(std::string path) : path_(path) {
    if (!loadData()) {
        std::cout << "Error loading image data from " << path << std::endl;
        // Should throw an exception here
    } 
    resolution_ = data_->size();
    setNameFromPath_();
    generateThumbnailAndSet_();
    generateTimestampAndSet_();
    unloadData();
}

void Image::setNameFromPath_() {
    size_t found = path_.find_last_of("/\\");
    if (found != std::string::npos) {
        name_ = path_.substr(found + 1);
    }
    name_ = path_;
}

std::shared_ptr<cv::Mat> Image::getData() {
    return data_;
}

bool Image::isLoaded() {
    return !data_->empty();
}

bool Image::loadData() {
    if (data_->empty()) {
        data_ = std::make_shared<cv::Mat>(cv::imread(path_, cv::IMREAD_COLOR));
        return true;
    }
    return false;
}

bool Image::unloadData() {
    if (!data_->empty()) {
        data_->release();
        return true;
    }
    return false;
}

cv::Mat Image::getThumbnail() {
    return thumbnail_;
}

std::string Image::getName() {
    return name_;
}

std::string Image::getPath() {
    return path_;
}

void Image::generateThumbnailAndSet_() {
    cv::Size thumbnail_resolution_ = cv::Size(thumbnail_width_, thumbnail_width_ * resolution_.height / resolution_.width);
    cv::resize(*data_, thumbnail_, thumbnail_resolution_);
}

void Image::generateTimestampAndSet_() {
    timestamp_ = std::time(nullptr);
}
