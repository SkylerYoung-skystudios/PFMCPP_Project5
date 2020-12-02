#include "LeakedObjectDetector.h"
#include <iostream>

struct Wurlitzer
{
    int volumeLevel;
    double vibratoAmount;
    std::string model;
    std::string condition;
    int numKeys;
    int output = 23;
    bool on;
    int tuning = 440;

    Wurlitzer();
    ~Wurlitzer();

    void changeVolume ( int knobPosition );
    void play ( int note = 23 );
    void power ( bool switchPosition = true );
    void printCondition();
    int swellVolume(int amount, int time);
    void print()
    {
        std::cout << "The Wulitzer has " << this->numKeys << " keys" << std::endl;
    }

    JUCE_LEAK_DETECTOR(Wurlitzer)
};
