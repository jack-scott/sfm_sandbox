#include <gtest/gtest.h>
#include <image.h>
#include <filesystem>
#include <fstream>
#include <opencv4/opencv2/imgcodecs.hpp>


using namespace sfm;
class ImageTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        // Create a temporary directory and some test image files.
        path_ = "/tmp/test_images";
        std::filesystem::remove_all(path_);

        std::filesystem::create_directory(path_);
        std::ofstream file1(path_ + "/empty_file.jpg");
        std::ofstream file2(path_ + "/empty_file.png");
        file1.close();
        file2.close();

        // Generate a 1x1 image as a test image.
        cv::Mat image(1, 1, CV_8UC3, cv::Scalar(0, 0, 0));
        cv::imwrite(path_ + "/1x1.jpg", image);
    }

    void TearDown() override
    {
        // Clean up any resources allocated in SetUp().
        std::filesystem::remove_all(path_);
    }

    std::string path_;
};

TEST_F(ImageTest, test_load_data)
{
    // Test that loadData loads the image data correctly.
    Image image(path_ + "/1x1.jpg", false);
    EXPECT_FALSE(image.isLoaded());
    EXPECT_TRUE(image.loadData());
    EXPECT_TRUE(image.isLoaded());
}

TEST_F(ImageTest, test_unload_data)
{
    // Test that unloadData unloads the image data correctly.
    Image image(path_ + "/1x1.jpg", true);
    EXPECT_TRUE(image.isLoaded());
    EXPECT_TRUE(image.unloadData());
    EXPECT_FALSE(image.isLoaded());
}

TEST_F(ImageTest, test_get_thumbnail)
{
    // Test that getThumbnail generates the thumbnail correctly.
    Image image(path_ + "/1x1.jpg", true);
    cv::Mat thumbnail = image.getThumbnail();
    EXPECT_TRUE(!thumbnail.empty());
}

TEST_F(ImageTest, test_get_resolution)
{
    // Test that getResolution returns the correct resolution.
    Image image(path_ + "/1x1.jpg", true);
    cv::Size resolution = image.getResolution();
    EXPECT_EQ(resolution.width, 1);
    EXPECT_EQ(resolution.height, 1);
}

TEST_F(ImageTest, test_thumbnail_resolution)
{
    Image image(path_ + "/1x1.jpg", true);
    cv::Mat thumbnail = image.getThumbnail();
    cv::Size actual_resolution = thumbnail.size();
    cv::Size expected_resolution = image.getThumbnailResolution();
    EXPECT_EQ(actual_resolution.width, expected_resolution.width);
    EXPECT_EQ(actual_resolution.height, expected_resolution.height);
}


TEST_F(ImageTest, test_get_name)
{
    // Test that getName returns the correct name.
    Image image(path_ + "/empty_file.jpg", false);
    EXPECT_EQ(image.getName(), "empty_file.jpg");
}

TEST_F(ImageTest, test_get_path)
{
    // Test that getPath returns the correct path.
    Image image(path_ + "/empty_file.jpg", false);
    EXPECT_EQ(image.getPath(), path_ + "/empty_file.jpg");
}
