#ifndef VISUALIZER_TOOLS_H
#define VISUALIZER_TOOLS_H

#include <shared/frame.h>

namespace sfm {
namespace visualizer {
void drawKeypoints(std::shared_ptr<Frame> frame);
}  // namespace visualizer
}  // namespace sfm
#endif  // VISUALIZER_TOOLS_H