#include "LeakedObjectDetector.h"
#include <iostream>

struct ElectricBass
{
    int numStrings = 4;
    std::string pickup = "precision";
    std::string brand = "fender";
    std::string model = "precision";
    int yearMade = 1974;
    int output = 23;
    int cost = 1544;
    int timeSinceRestrung = 13;
    bool timeToRestring = false;
    int tuning = 442;
    
    ElectricBass();
    ~ElectricBass();

    void play ( int note =  18 );
    void sold ( int price = 1200 );
    void restring ( bool restring = true );
    void checkStrings (int timesPlayed);
    void print() FIXME see instruction 5)
    {
        std::cout << "This Bass costs $" << this->cost << std::endl;
    }

    JUCE_LEAK_DETECTOR(ElectricBass)
};
