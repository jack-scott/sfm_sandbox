#include "visualizer/visualizer_tools.h"
#include <opencv2/opencv.hpp>

namespace sfm {
namespace visualizer {
void drawKeypoints(std::shared_ptr<Frame> frame) {
  cv::Mat image_with_points;
  cv::drawKeypoints(*frame->getImage()->getData(), frame->getKeypoints(), image_with_points);
  cv::imshow("Keypoints", image_with_points);
  cv::waitKey(0);
}
}  // namespace visualizer
}  // namespace sfm