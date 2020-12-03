#pragma once
#include "Band.h"
#include "Clothing.h"

struct ShoeWrapper
{
    ShoeWrapper(Shoe* shoePtr);
    ~ShoeWrapper();
    Shoe* theShoe = nullptr;
};

struct WurlitzerWrapper
{
    WurlitzerWrapper(Wurlitzer* wurlitzerPtr);
    ~WurlitzerWrapper();
    Wurlitzer* theWurli = nullptr;
};

struct BassWrapper
{
    BassWrapper(ElectricBass* bassPtr);
    ~BassWrapper();
    ElectricBass* theBass = nullptr;
};

struct BandWrapper
{
    BandWrapper(Band* bandPtr);
    ~BandWrapper();
    Band* theBand = nullptr;
};

struct ClothingWrapper
{
    ClothingWrapper(Clothing* clothesPtr);
    ~ClothingWrapper();
    Clothing* theClothes = nullptr;
};
