/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */





#include <iostream>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */
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
    void print()
    {
        std::cout << "These shoes are in " << this->condition << " condition" << std::endl;
    }

    JUCE_LEAK_DETECTOR(Shoe)
};

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

struct ShoeWrapper
{
    ShoeWrapper(Shoe* shoePtr) : theShoe(shoePtr) { }
    ~ShoeWrapper() { delete theShoe; }
    Shoe* theShoe = nullptr;
};
/*
 copied UDT 2:
 */
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

struct WurlitzerWrapper
{
    WurlitzerWrapper(Wurlitzer* wurlitzerPtr) : theWurli(wurlitzerPtr) { }
    ~WurlitzerWrapper() { delete theWurli; }
    Wurlitzer* theWurli = nullptr;
};
/*
 copied UDT 3:
 */
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
    void print()
    {
        std::cout << "This Bass costs $" << this->cost << std::endl;
    }

    JUCE_LEAK_DETECTOR(ElectricBass)
};

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

struct BassWrapper
{
    BassWrapper(ElectricBass* bassPtr) : theBass(bassPtr) { }
    ~BassWrapper() { delete theBass; }
    ElectricBass* theBass = nullptr;
};
/*
 new UDT 4:
 with 2 member functions
 */
struct Band
{
    Wurlitzer keys;
    ElectricBass bass;
    int members = 2;

    void tune();
    void turnDown(int amount);
    void print()
    {
        std::cout << "There are " << this->members << " members in the band" << std::endl;
    }
    
    Band();
    ~Band();

    JUCE_LEAK_DETECTOR(Band)
};

void Band::tune()
{
    keys.tuning = bass.tuning;   
}

void Band::turnDown(int amount)
{
    keys.output -= amount;
    bass.output -= amount;  
}

Band::Band(){}
Band::~Band()
{
    if (keys.on)
    {
        std::cout << "Turn off Wurlitzer\n";
    }
}

struct BandWrapper
{
    BandWrapper(Band* bandPtr) : theBand(bandPtr) { }
    ~BandWrapper() { delete theBand; }
    Band* theBand = nullptr;
};
/*
 new UDT 5:
 with 2 member functions
 */
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

struct ClothingWrapper
{
    ClothingWrapper(Clothing* clothesPtr) : theClothes(clothesPtr) { }
    ~ClothingWrapper() { delete theClothes; }
    Clothing* theClothes = nullptr;
};
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    ShoeWrapper blazer( new Shoe ), airforce1( new Shoe );
    WurlitzerWrapper red( new Wurlitzer ), tan( new Wurlitzer );
    BassWrapper jaguar( new ElectricBass ) , precision( new ElectricBass );
    BandWrapper bar( new Band ), concert( new Band );
    ClothingWrapper chris( new Clothing );

    jaguar.theBass->play(24);
    tan.theWurli->power(true);
    blazer.theShoe->putOn("L", false);

    tan.theWurli->printCondition();

    blazer.theShoe->wearDown(47);

    precision.theBass->checkStrings(84);

    red.theWurli->output = red.theWurli->swellVolume(60, 5);

    bar.theBand->turnDown(6);

    chris.theClothes->changeSize(1);

    std::cout << "These shoes are in " << blazer.theShoe->condition << " condition" << std::endl;

    blazer.theShoe->print();

    std::cout << "The Wulitzer has " << red.theWurli->numKeys << " keys" << std::endl;

    red.theWurli->print();

    std::cout << "This Bass costs $" << jaguar.theBass->cost << std::endl;

    jaguar.theBass->print();

    std::cout << "There are " << bar.theBand->members << " members in the band" << std::endl;

    bar.theBand->print();
}
