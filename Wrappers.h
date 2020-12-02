#pragma once
#include "Band.h"
#include "Clothing.h"

struct ShoeWrapper
{
    ShoeWrapper(Shoe* shoePtr) : theShoe(shoePtr) { }
    ~ShoeWrapper() { delete theShoe; }
    Shoe* theShoe = nullptr;
};

struct WurlitzerWrapper
{
    WurlitzerWrapper(Wurlitzer* wurlitzerPtr) : theWurli(wurlitzerPtr) { }
    ~WurlitzerWrapper() { delete theWurli; }
    Wurlitzer* theWurli = nullptr;
};

struct BassWrapper
{
    BassWrapper(ElectricBass* bassPtr) : theBass(bassPtr) { }
    ~BassWrapper() { delete theBass; }
    ElectricBass* theBass = nullptr;
};

struct BandWrapper
{
    BandWrapper(Band* bandPtr) : theBand(bandPtr) { }
    ~BandWrapper() { delete theBand; }
    Band* theBand = nullptr;
};

struct ClothingWrapper
{
    ClothingWrapper(Clothing* clothesPtr) : theClothes(clothesPtr) { }
    ~ClothingWrapper() { delete theClothes; }
    Clothing* theClothes = nullptr;
};
