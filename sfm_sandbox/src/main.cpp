#include "dataLoader.h"
#include "image.h"
#include <string.h>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    std::string path = argv[1];
    DataLoader dataLoader;
    std::vector<Image> images = dataLoader.loadImages(path);
    for (Image image : images) {
        std::cout << image.getName() << std::abort;
    }
    return 0;

}


