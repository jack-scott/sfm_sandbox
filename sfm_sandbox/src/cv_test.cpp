#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

int main(int argc, char** argv) {
  cv::Mat blah = cv::imread(argv[1], cv::IMREAD_COLOR);
  if (blah.empty()) {
    std::cout << "empty" << std::endl;
  } else {
    std::cout << "not empty" << std::endl;
  }
  return 0;
}