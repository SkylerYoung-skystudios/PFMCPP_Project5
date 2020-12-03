#pragma once
#include "Wurlitzer.h"
#include "ElectricBass.h"
#include "LeakedObjectDetector.h"
#include <iostream>


struct Band
{
    Wurlitzer keys;
    ElectricBass bass;
    int members = 2;

    void tune();
    void turnDown(int amount);
    void print();
    
    Band();
    ~Band();

    JUCE_LEAK_DETECTOR(Band)
};
