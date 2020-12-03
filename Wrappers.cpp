#include "Wrappers.h"

ShoeWrapper::ShoeWrapper(Shoe* shoePtr) : theShoe(shoePtr) { }
ShoeWrapper::~ShoeWrapper() { delete theShoe; }

WurlitzerWrapper::WurlitzerWrapper(Wurlitzer* wurlitzerPtr) : theWurli(wurlitzerPtr) { }  
WurlitzerWrapper::~WurlitzerWrapper() { delete theWurli; }

BassWrapper::BassWrapper(ElectricBass* bassPtr) : theBass(bassPtr) { }
BassWrapper::~BassWrapper() { delete theBass; }

BandWrapper::BandWrapper(Band* bandPtr) : theBand(bandPtr) { }
BandWrapper::~BandWrapper() { delete theBand; }

ClothingWrapper::ClothingWrapper(Clothing* clothesPtr) : theClothes(clothesPtr) { }
ClothingWrapper::~ClothingWrapper() { delete theClothes; }
