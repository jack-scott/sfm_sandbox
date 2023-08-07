include "image.h"

Image::Image(std::string path) : path(path) {
    data = cv::imread(path, cv::IMREAD_COLOR);
    resolution = data.size();
    name = generateName(path);
    generateThumbnail(data);
    generateTimestamp();
}

std::string Image::generateName(std::string& path) {
    size_t found = filePath.find_last_of("/\\");
    if (found != std::string::npos) {
        return filePath.substr(found + 1);
    }
    return filePath;
}

cv::Mat Image::getData() {
    return data;
}

cv::Mat Image::getThumbnail() {
    return thumbnail;
}

std::string Image::getName() {
    return name;
}

std::string Image::getPath() {
    return path;
}

void Image::generateThumbnail() {
    cv::size thumbnail_resolution = cv::Size(thumbnail_width, thumbnail_width * resolution.height / resolution.width);
    cv::resize(data, thumbnail, thumbnail_resolution);
}