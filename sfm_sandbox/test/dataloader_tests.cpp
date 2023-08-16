#include <gtest/gtest.h>
#include <dataloader.h>
#include <filesystem>
#include <fstream>

class DataLoaderTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        path_ = "/tmp/test_files";
        std::filesystem::remove_all(path_);
    }

    void TearDown() override
    {
        std::filesystem::remove_all(path_);    
    }

    std::string path_;
};

// TEST_F(DataLoaderTest, test_load_images)
// {
//     // Create a temporary directory and some test image files.
//     std::string path = "/tmp/test_images";
//     std::filesystem::create_directory(path);
//     std::ofstream file1(path + "/test1.jpg");
//     std::ofstream file2(path + "/test2.png");
//     file1.close();
//     file2.close();

//     // Load the images and check that the correct number were loaded.
//     DataLoader loader;
//     std::vector<Image> images = loader.loadImages(path);
//     EXPECT_EQ(images.size(), 2);

//     // Clean up the temporary directory.
//     std::filesystem::remove_all(path);
// }

// TEST_F(DataLoaderTest, test_only_load_images)
// {
//     // Create a temporary directory and some test image files.
//     std::string path = "/tmp/test_images";
//     std::filesystem::create_directory(path);
//     std::ofstream file1(path + "/test1.jpg");
//     std::ofstream file2(path + "/not_an_im.pdf");
//     file1.close();
//     file2.close();

//     // Load the images and check that the correct number were loaded.
//     DataLoader loader;
//     std::vector<Image> images = loader.loadImages(path);
//     EXPECT_EQ(images.size(), 2);

//     // Clean up the temporary directory.
//     std::filesystem::remove_all(path);
// }

TEST_F(DataLoaderTest, test_get_filenames)
{
    // Create a temporary directory and some test files.
    std::filesystem::create_directory(path_);
    std::ofstream file1(path_ + "/test1.txt");
    std::ofstream file2(path_ + "/test2.dat");
    file1.close();
    file2.close();

    // Get the filenames and check that the correct number were returned.
    DataLoader loader;
    std::vector<std::string> filenames = loader.getFilenames(path_);
    EXPECT_EQ(filenames.size(), 2);

    // Check that the filenames are correct.
    EXPECT_EQ(filenames[0], path_ + "/test1.txt");
    EXPECT_EQ(filenames[1], path_ + "/test2.dat");

    // Clean up the temporary directory.
    std::filesystem::remove_all(path_);
}

TEST_F(DataLoaderTest, test_is_supported_image)
{
    // Test that is_supported_image returns true for supported image files.
    DataLoader loader;
    EXPECT_TRUE(loader.is_supported_image("test.jpg"));
    EXPECT_TRUE(loader.is_supported_image("test.jpeg"));
    EXPECT_TRUE(loader.is_supported_image("test.png"));

    // Test that is_supported_image returns false for unsupported image files.
    EXPECT_FALSE(loader.is_supported_image("test.txt"));
    EXPECT_FALSE(loader.is_supported_image("test.pdf"));
    EXPECT_FALSE(loader.is_supported_image("test.doc"));
}

TEST_F(DataLoaderTest, test_is_supported_video)
{
    // Test that is_supported_video returns true for supported video files.
    DataLoader loader;
    EXPECT_TRUE(loader.is_supported_video("test.mp4"));
    EXPECT_TRUE(loader.is_supported_video("test.avi"));
    EXPECT_TRUE(loader.is_supported_video("test.mov"));
    EXPECT_TRUE(loader.is_supported_video("test.mkv"));

    // Test that is_supported_video returns false for unsupported video files.
    EXPECT_FALSE(loader.is_supported_video("test.txt"));
    EXPECT_FALSE(loader.is_supported_video("test.pdf"));
    EXPECT_FALSE(loader.is_supported_video("test.doc"));
}