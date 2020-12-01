#include <iostream>
#include "Wurlitzer.h"

Wurlitzer::Wurlitzer() :
volumeLevel ( 6 ),
vibratoAmount ( .5 ),
model ( "200a" ),
condition ( "good" ),
numKeys ( 49 ),
output ( 23 ),
on ( false )
{
}

Wurlitzer::~Wurlitzer()
{
    std::cout << "Wurlitzer Destroyed\n";
}

void Wurlitzer::changeVolume( int knobPosition ) 
{
    volumeLevel = knobPosition;
    std::cout << "Knob Position is: " << knobPosition << "\n";
}

void Wurlitzer::play( int note ) 
{
    output = note;
}

void Wurlitzer::power( bool switchPosition ) 
{
    on = switchPosition;
}

void Wurlitzer::printCondition()
{
    std::cout << "This Wutlizer is in " << condition << " condition\n"; 
}

int Wurlitzer::swellVolume(int amount, int time)
{
    int swell = 0;
    for (int i = 0; i <= time ; i += 1)
    {
        swell += 20;
        if (swell >= amount)
        {
            std::cout << "Swell finished" << std::endl;
            return swell;
        }
    }
    return swell;
}
