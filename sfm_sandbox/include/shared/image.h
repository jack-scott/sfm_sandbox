#ifndef IMAGE_H
#define IMAGE_H

#include <opencv4/opencv2/core.hpp>

#include "sfm_types.h"

/**
 * @class
 * @brief Basic image data container class
 * 
 * This class contains all of the basic image data and metadata for an image. 
 * It can contain image data of any type as long as the type is correctly set.
 * TODO: This class should more natively support lazy loading of image data.
 * 
*/
namespace sfm {

class Image {

 public:
  // Constructor
  Image(std::string path, bool load_now);
  std::shared_ptr<cv::Mat> getData();
  cv::Mat getThumbnail();
  std::string getName();
  std::string getPath();
  cv::Size getResolution();
  cv::Size getThumbnailResolution();
  bool loadData();
  bool unloadData();
  bool isLoaded();

 private:
  //config params
  int thumbnail_width_ = 150;
  //
  std::shared_ptr<cv::Mat> data_;  //TODO: This should be a pointer to allow lazy loading
  cv::Size resolution_;
  cv::Mat thumbnail_;
  cv::Size thumbnail_resolution_;
  std::string name_;
  std::string path_;
  ImageType type_;
  std::string format_;
  std::time_t timestamp_;

  void setNameFromPath_();
  void generateThumbnailAndSet_();
  void generateTimestampAndSet_();
};
}  // namespace sfm
#endif  // IMAGE_H