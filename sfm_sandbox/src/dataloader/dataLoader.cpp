#include "dataLoader.h"
#include <filesystem.h>


DataLoader::DataLoader() {
}

DataLoader::~DataLoader() {
}

std::vector<Image> DataLoader::loadImages(std::string path) {
    std::vector<Image> images;
    std::vector<std::string> filenames = getFilenames(path);
    for (const std::string& filename : filenames) {
        if (is_supported_image(filename)) {
            images.push_back(Image(filename));
        }
    }
    return images;
}

std::vector<std::string> DataLoader::getFilenames(std::string path) {
    std::vector<std::string> filenames;
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        filenames.push_back(entry.path().string());
    }
    return filenames;
}

bool DataLoader::is_supported_image(const std::string& filename) {
    return is_supported_file(filename, supported_image_extensions);
}

bool DataLoader::is_supported_video(const std::string& filename) {
    return is_supported_file(filename, supported_video_extensions);
}

bool DataLoader::is_supported_file(const std::string& filename, const std::vector<std::string>& supported_extensions) {
    size_t pos = filename.find_last_of(".");
    if (pos != std::string::npos) {
        std::string ext = filename.substr(pos);
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        return std::find(supported_extensions.begin(), supported_extensions.end(), ext) != supported_extensions.end();
    }
    return false;
}