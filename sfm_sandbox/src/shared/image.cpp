#include "shared/image.h"

#include <iostream>

#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>


Image::Image(std::string path, bool load_now) : path_(path), data_(std::make_shared<cv::Mat>())
{
    if (load_now)
    {
        if (loadData())    //TODO swap out for glogging and assert
        {
            resolution_ = data_->size();
            generateThumbnailAndSet_();
            generateTimestampAndSet_();   
        }else{
            std::cout << "Error loading image data from " << path << std::endl;
            // Should throw an exception here
        }

    }
    setNameFromPath_();
}

void Image::setNameFromPath_()
{
    size_t found = path_.find_last_of("/");
    if (found != std::string::npos)
    {
        name_ = path_.substr(found + 1);
    }
    else
    {
        // fallback behavior
        name_ = path_;
    }
}

std::shared_ptr<cv::Mat> Image::getData()
{
    return data_;
}

bool Image::isLoaded()
{
    return !data_->empty();
}

bool Image::loadData()
{
    if (isLoaded())
    {
        return true;
    }
    else
    {
        try
        {
            data_ = std::make_shared<cv::Mat>(cv::imread(path_, cv::IMREAD_COLOR)); // TODO make an interface between opencv so it can be swapped out in the future
        }
        catch (cv::Exception &e)
        {
            const char *err_msg = e.what();
            std::cout << "exception caught: " << err_msg << std::endl; // TODO Swap out for glogging
        }
    }
    return isLoaded();
}

bool Image::unloadData()
{
    if (!data_->empty())
    {
        data_->release();
        return true;
    }
    return false;
}

cv::Mat Image::getThumbnail()
{
    return thumbnail_;
}

std::string Image::getName()
{
    return name_;
}

std::string Image::getPath()
{
    return path_;
}

cv::Size Image::getResolution()
{
    return resolution_;
}

cv::Size Image::getThumbnailResolution()
{
    return thumbnail_resolution_;
}

void Image::generateThumbnailAndSet_()
{
    thumbnail_resolution_ = cv::Size(thumbnail_width_, thumbnail_width_ * resolution_.height / resolution_.width);
    cv::resize(*data_, thumbnail_, thumbnail_resolution_);
}

void Image::generateTimestampAndSet_()
{
    timestamp_ = std::time(nullptr);
}
