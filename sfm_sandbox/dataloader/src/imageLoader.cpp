#include <iostream>
#include <string>

// Abstract base class for image loaders
class ImageLoader {
public:
    virtual void load(const std::string& filePath) = 0;
};

// Concrete image loader for JPEG images
class JpegLoader : public ImageLoader {
public:
    void load(const std::string& filePath) override {
        std::cout << "Loading JPEG image: " << filePath << std::endl;
        
    }
};

// Concrete image loader for PNG images
class PngLoader : public ImageLoader {
public:
    void load(const std::string& filePath) override {
        std::cout << "Loading PNG image: " << filePath << std::endl;
        // Add code to handle loading of PNG image
    }
};
