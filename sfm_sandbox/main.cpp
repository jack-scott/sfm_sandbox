#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


int main(int argc, char** argv) {
    cv::Mat img = cv::imread(argv[1], cv::IMREAD_COLOR);
    cv::namedWindow("Example 1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example 1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example 1");
    return 0;
}


