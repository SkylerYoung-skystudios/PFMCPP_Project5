/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

#include <iostream>
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
/*
 new UDT 4:
 with 2 member functions
 */
struct Band
{
    Wurlitzer keys;
    ElectricBass bass;

    void tune();
    void turnDown(int amount);
    
    Band();
    ~Band();
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
    Shoe blazer, airforce1;
    Wurlitzer red, tan;
    ElectricBass jaguar, precision;
    Band bar, concert;
    Clothing chris;

    jaguar.play(24);
    tan.power(true);
    blazer.putOn("L", false);

    tan.printCondition();

    blazer.wearDown(47);

    precision.checkStrings(84);

    red.output = red.swellVolume(60, 5);

    bar.turnDown(6);

    chris.changeSize(1);
}
