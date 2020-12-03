#include <iostream>
#include "Band.h"

void Band::tune()
{
    keys.tuning = bass.tuning;   
}

void Band::turnDown(int amount)
{
    keys.output -= amount;
    bass.output -= amount;  
}

void Band::print()
{
    std::cout << "There are " << this->members << " members in the band" << std::endl;
}

Band::Band(){}
Band::~Band()
{
    if (keys.on)
    {
        std::cout << "Turn off Wurlitzer\n";
    }
}

