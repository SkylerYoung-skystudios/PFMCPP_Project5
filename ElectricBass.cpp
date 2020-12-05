#include <iostream>
#include "ElectricBass.h"

ElectricBass::ElectricBass(){}
ElectricBass::~ElectricBass()
{
    std::cout << "ElectricBass Destroyed\n";
}

void ElectricBass::play( int note ) 
{
    output = note;
}

void ElectricBass::sold( int price ) 
{
    cost = price;
    std::cout << "This Bass was sold for $" << price << "\n";
}

void ElectricBass::restring( bool restring ) 
{
    if (restring)
    {
        timeSinceRestrung = 0;
    }
}

void ElectricBass::print()
{
    std::cout << "This Bass costs $" << this->cost << std::endl;
}

void ElectricBass::checkStrings (int timesPlayed)
{
    for (int i = 0; i <= timesPlayed; i += 1)
    {
        timeSinceRestrung += 1; 
    }

    if (timeSinceRestrung > 60)
    {
        timeToRestring = true;
        std::cout << "Time to change strings!" << std::endl;
    }
    else
    {
        std::cout << "Strings are still good!" << std::endl;
    }
} 
