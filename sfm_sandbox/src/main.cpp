#include <string.h>
#include <iostream>
#include <vector>
#include "dataloader.h"
#include "image.h"

using namespace sfm;

int main(int argc, char** argv) {
  std::string path = argv[1];
  DataLoader dataloader;
  std::vector<Image> images = dataloader.loadImages(path);
  for (Image image : images) {
    std::cout << image.getName() << std::endl;
  }
  return 0;
}
