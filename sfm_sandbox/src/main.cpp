#include <string.h>
#include <iostream>
#include <vector>
#include "dataloader/dataloader.h"
#include "frontend/opencv/features_orb_ocv.h"
#include "shared/camera.h"
#include "shared/frame.h"
#include "shared/image.h"
#include "visualizer/visualizer_tools.h"

#include <opencv2/opencv.hpp>
#include "open3d/Open3D.h"

using namespace sfm;

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Usage: ./sfm_sandbox <path_to_images>" << std::endl;
    return 1;
  }
  std::string path = argv[1];
  DataLoader dataloader;
  std::vector<Image> images = dataloader.loadImages(path);
  Camera cam(std::string("virtual_cam"), cv::Size(512, 512));
  // Camera cam();
  std::vector<std::shared_ptr<Frame>> frame_bundle;
  for (Image image : images) {
    std::cout << image.getName() << std::endl;
    std::shared_ptr<Frame> frame = std::make_shared<Frame>(cam, std::make_shared<Image>(image));
    frame_bundle.push_back(frame);
  }

  ORBFeatureDetectorCV detector;
  detector.detectAndCompute(frame_bundle);
  for (auto frame : frame_bundle) {
    std::cout << frame->getImage()->getName() << std::endl;
    std::cout << frame->getDescriptors().size() << std::endl;
    std::cout << frame->getKeypoints().size() << std::endl;

    visualizer::drawKeypoints(frame);
  }

  for (auto point : frame_bundle[0]->getKeypoints()) {
    std::cout << point.pt << std::endl;
  }

  // Display cv mat in open3d
  // cv::Mat cv_frame = *frame_bundle[0]->getImage()->getData();
  // std::shared_ptr im_ptr = std::make_shared<open3d::geometry::Image>();
  // // Allocate data buffer
  // im_ptr->Prepare(cv_frame.size[0], cv_frame.size[1], 3, 1);
  // // mat is your cv::Mat depth image
  // memcpy(im_ptr->data_.data(), cv_frame.data, im_ptr->data_.size());
  // open3d::visualization::DrawGeometries({im_ptr}, "Image", im_ptr->width_, im_ptr->height_);

  return 0;
}
