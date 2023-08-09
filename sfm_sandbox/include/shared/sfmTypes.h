#ifndef SFM_TYPES_H
#define SFM_TYPES_H

enum class DistortionModel
{
    NONE,
    RADTAN,
    EQUIDISTANT
};

enum class CameraModel
{
    PINHOLE,
    KANNALA_BRANDT  //Unsupported
};

enum class ImageType
{
    RGB,
    DEPTH,
    MASK
};



#endif // SFM_TYPES_H