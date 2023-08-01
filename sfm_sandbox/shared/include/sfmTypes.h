#ifndef SFM_TYPES_H
#define SFM_TYPES_H

enum class DistortionModel
{
    RADTAN,
    EQUIDISTANT
};

enum class CameraModel
{
    PINHOLE,
    KANNALA_BRANDT  //Unsupported
};

#endif // SFM_TYPES_H