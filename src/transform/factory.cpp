#include <string>

#include "transform.hpp"

#include "ycocg.hpp"
//#include "yc1c2.hpp"
#include "bounds.hpp"
#include "colorbuckets.hpp"
#include "palette.hpp"
#include "palette_A.hpp"
#include "palette_C.hpp"
#include "frameshape.hpp"
#include "framedup.hpp"
#include "framecombine.hpp"

template <typename IO>
std::unique_ptr<Transform<IO>> create_transform(std::string desc) {
    if (desc == "YCoCg")
        return make_unique<TransformYCoCg<IO>>();
// use this if you just want to quickly try YC1C2
//        return new TransformYCC<IO>();
    if (desc == "Bounds")
        return make_unique<TransformBounds<IO>>();
    if (desc == "Color_Buckets")
        return make_unique<TransformCB<IO>>();
    if (desc == "Palette")
        return make_unique<TransformPalette<IO>>();
    if (desc == "Palette_Alpha")
        return make_unique<TransformPaletteA<IO>>();
    if (desc == "Channel_Compact")
        return make_unique<TransformPaletteC<IO>>();
    if (desc == "Frame_Shape")
        return make_unique<TransformFrameShape<IO>>();
    if (desc == "Duplicate_Frame")
        return make_unique<TransformFrameDup<IO>>();
    if (desc == "Frame_Lookback")
        return make_unique<TransformFrameCombine<IO>>();
    return NULL;
}

template std::unique_ptr<Transform<BufferIO>> create_transform(std::string desc);