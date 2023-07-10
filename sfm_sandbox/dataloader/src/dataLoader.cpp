#include <iostream>
#include <string>
#include "imageLoader.h"

class DataLoader {
private:
    ImageLoader* imageLoader;

public:
    DataLoader() : imageLoader(nullptr) {}

    ~DataLoader() {
        delete imageLoader;
    }

    void importImage(const std::string& filePath) {
        detectImageType(filePath);
        if (imageLoader != nullptr) {
            imageLoader->load(filePath);
        }
        else {
            std::cout << "Unsupported image type: " << filePath << std::endl;
        }
    }

    void importVideo(const std::string& filePath) {
        videoLoader.load(filePath);
    }

private:
    void detectImageType(const std::string& filePath) {
        // Add code to detect the image type based on the file extension or content
        // You can use third-party libraries or custom logic for detection

        // Here, we assume the file extension is used for simplicity
        std::string extension = getFileExtension(filePath);
        if (extension == "jpg" || extension == "jpeg") {
            delete imageLoader;
            imageLoader = new JpegLoader();
        }
        else if (extension == "png") {
            delete imageLoader;
            imageLoader = new PngLoader();
        }
        else if (extension == "gif") {
            delete imageLoader;
            imageLoader = new GifLoader();
        }
        else {
            // Unsupported image type
            delete imageLoader;
            imageLoader = nullptr;
        }
    }

    std::string getFileExtension(const std::string& filePath) {
        size_t dotPos = filePath.find_last_of(".");
        if (dotPos != std::string::npos) {
            return filePath.substr(dotPos + 1);
        }
        return "";
    }
};

int main() {
    DataLoader dataLoader;

    std::string imageFilePath = "path/to/image.jpg";
    std::string videoFilePath = "path/to/video.mp4";

    dataLoader.importImage(imageFilePath);
    dataLoader.importVideo(videoFilePath);

    return 0;
}