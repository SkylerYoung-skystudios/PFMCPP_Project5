#include <iostream>
#include "Clothing.h"

Clothing::Clothing(){}
Clothing::~Clothing()
{
    if (vansBeingWorn)
    {
        std::cout << "Shoe being worn is vans\n";
    }
    else
    {
        std::cout << "Shoe being worn is blazer\n";
    }
}

void Clothing::switchShoes()
{
    if (blazer.beingWorn == true)
    {
        blazer.beingWorn = false;
        vans.beingWorn = true;
    }
    else
    {
        blazer.beingWorn = true;
    }
}

void Clothing::changeSize(int amount)
{
    blazer.size += amount;
    vans.size += amount;
}
