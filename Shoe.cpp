#include <iostream>
#include "Shoe.h"

Shoe::Shoe(){}
Shoe::~Shoe()
{
    std::cout << "Shoe Destroyed\n";
}

void Shoe::putOn(std::string firstShoe, bool leftFirst) 
{
    if (leftFirst)
    {
        firstShoe = "L";
    }
}

void Shoe::takeOff(std::string firstShoe, bool leftFirst) 
{
    if (leftFirst)
    {
        firstShoe = "L";
    }
}

void Shoe::throwAway(bool donate) 
{
    if (condition == "good")
    {
        donate = true;
    }
    
}

void Shoe::wearDown(int timesWorn)
{
    for (int i = 0; i <= timesWorn; i += 1)
    {
        percentOfSoleLeft -= 0.2;
    }

    std::cout << "Sole percent left " << percentOfSoleLeft << std::endl;
}
