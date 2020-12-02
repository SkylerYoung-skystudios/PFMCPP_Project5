#pragma once
#include "Shoe.h"
#include "LeakedObjectDetector.h"


struct Clothing
{
    Shoe blazer;
    Shoe vans;
    bool vansBeingWorn = false;
    void switchShoes();

    void changeSize(int amount);

    Clothing();
    ~Clothing();

    JUCE_LEAK_DETECTOR(Clothing)
};
