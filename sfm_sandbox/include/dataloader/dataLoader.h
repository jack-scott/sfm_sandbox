#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>
#include "image.h"
class DataLoader
{
public:
    DataLoader();
    ~DataLoader();
    std::vector<Image> loadImages(std::string path);

private:
    std::vector<std::string> supported_image_extensions = {".jpg", ".jpeg", ".png", ".gif"};
    std::vector<std::string> supported_video_extensions = {".mp4", ".avi", ".mov", ".mkv"};
    std::vector<std::string> getFilenames(std::string path);
    bool is_supported_image(const std::string& filename);
    bool is_supported_video(const std::string& filename);
    bool is_supported_file(const std::string& filename, const std::vector<std::string>& supported_extensions);                                                          
};


#endif // DATALOADER_H