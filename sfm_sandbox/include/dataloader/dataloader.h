#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>

#include "shared/image.h"
namespace sfm {
class DataLoader {
 public:
  DataLoader();
  ~DataLoader();
  std::vector<Image> loadImages(std::string path);
  std::vector<Image> importImages(std::string path);

  std::vector<std::string> getFilenames(std::string path);
  bool is_supported_image(const std::string& filename);
  bool is_supported_video(const std::string& filename);

  std::vector<std::string> supported_image_extensions = {".jpg", ".jpeg", ".png"};
  std::vector<std::string> supported_video_extensions = {".mp4", ".avi", ".mov", ".mkv"};

 private:
  std::vector<Image> createImagesFromPath(std::string path, bool load_now);
  bool is_supported_file(const std::string& filename,
                         const std::vector<std::string>& supported_extensions);
};
}  // namespace sfm

#endif  // DATALOADER_H