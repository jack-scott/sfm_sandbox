#include <string.h>
#include <iostream>
#include <vector>
#include "dataloader/dataloader.h"
#include "shared/camera.h"
#include "shared/image.h"

using namespace sfm;

int main(int argc, char** argv) {
  std::string path = argv[1];
  DataLoader dataloader;
  std::vector<Image> images = dataloader.loadImages(path);
  Camera cam(std::string("virtual_cam"), cv::Size(512, 512));
  // Camera cam();
  for (Image image : images) {
    std::cout << image.getName() << std::endl;
  }
  return 0;
}
