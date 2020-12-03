#pragma once
#include "Band.h"
#include "Clothing.h"

struct ShoeWrapper
{
    ShoeWrapper(Shoe* shoePtr) : theShoe(shoePtr) { }  FIXME see instruction 5)
    ~ShoeWrapper() { delete theShoe; }  FIXME see instruction 5)
    Shoe* theShoe = nullptr;
};

struct WurlitzerWrapper
{
    WurlitzerWrapper(Wurlitzer* wurlitzerPtr) : theWurli(wurlitzerPtr) { }  FIXME see instruction 5)
    ~WurlitzerWrapper() { delete theWurli; }  FIXME see instruction 5) 
    Wurlitzer* theWurli = nullptr;
};

struct BassWrapper
{
    BassWrapper(ElectricBass* bassPtr) : theBass(bassPtr) { }  FIXME see instruction 5)
    ~BassWrapper() { delete theBass; }  FIXME see instruction 5)
    ElectricBass* theBass = nullptr;
};

struct BandWrapper
{
    BandWrapper(Band* bandPtr) : theBand(bandPtr) { }  FIXME see instruction 5)
    ~BandWrapper() { delete theBand; }  FIXME see instruction 5)
    Band* theBand = nullptr;
};

struct ClothingWrapper
{
    ClothingWrapper(Clothing* clothesPtr) : theClothes(clothesPtr) { }  FIXME see instruction 5)
    ~ClothingWrapper() { delete theClothes; }  FIXME see instruction 5)
    Clothing* theClothes = nullptr;
};
