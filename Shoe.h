#include "LeakedObjectDetector.h"
#include <iostream>

struct Shoe
{
    std::string brand { "Nike" };
    double size { 0 };
    std::string color { "white" };
    std::string condition { "good" };
    std::string securingMethod { "velcro" };
    double percentOfSoleLeft = 100;
    bool beingWorn = false;
    
    Shoe();
    ~Shoe();

    void putOn ( std::string firstShoe = "R", bool leftFirst = true);
    void takeOff ( std::string firstShoe = "R", bool leftFirst = true );
    void throwAway ( bool donate = false );
    void wearDown(int timesWorn);
    void print();

    JUCE_LEAK_DETECTOR(Shoe)
};
