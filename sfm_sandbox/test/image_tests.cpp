#include <gtest/gtest.h>
#include <image.h>
#include <filesystem>
#include <fstream>

class ImageTests : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
        // Clean up any resources allocated in SetUp().
    }
};


TEST_F(ImageTests, test_is_supported_video)
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