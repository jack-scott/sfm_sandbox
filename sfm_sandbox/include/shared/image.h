#ifndef IMAGE_H
#define IMAGE_H

#include <opencv4/opencv2/core.hpp>
#include "sfmTypes.h"

/**
 * @class
 * @brief Basic image data container class
 * 
 * This class contains all of the basic image data and metadata for an image. 
 * It can contain image data of any type as long as the type is correctly set.
 * TODO: This class should more natively support lazy loading of image data.
 * 
*/

class Image {
private:
    //config params
    int thumbnail_width = 150;
    //
    cv::Mat& data;   //TODO: This should be a pointer to allow lazy loading
    cv::Size resolution;
    cv::Mat thumbnail;
    cv::Size thumbnail_resolution;
    std::string name;
    std::string path;
    ImageType type;
    std::string format;
    std::time_t timestamp;
    
    void generateThumbnail();
    void generateTimestamp();
    void generateName(std::string path);
public:
    // Constructor
    Image(std::string path);
    cv::Mat getData();
    cv::Mat getThumbnail();
    std::string getName();
    std::string getPath();

};

#endif // IMAGE_H