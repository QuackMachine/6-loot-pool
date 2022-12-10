/*
* make rng on rng
* this is for basic loot pool system...?
*/
#include <iostream>
#include <time.h>
#include <string>
#include <random>
using namespace std;

void white();             // 45% of loot pool
void green();             // 30% of loot pool
void blue();              // 15% of loot pool
void purple();            // 8%  of loot pool
void yellow();            // 2%  of loot pool

std::random_device rd;
std::mt19937_64 gen (rd ());
std::uniform_int_distribution <> distribution       (1  , 1000);
std::uniform_int_distribution <> distributionWhite  (1  , 100);
std::uniform_int_distribution <> distributionGreen  (101, 200);
std::uniform_int_distribution <> distributionBlue   (201, 300);
std::uniform_int_distribution <> distributionPurple (301, 400);
std::uniform_int_distribution <> distributionYellow (401, 500);

int main()
{
    //set variables
    int LootPool, common, uncommon, rare, epic, legendary;
    string answer;

    //initiate rng machine
    srand(time(NULL));

    //range between 1 - 1000 
    LootPool = distribution (gen);

    //for console
    cout << endl;

    //begins of rng
    if (1 <= LootPool && LootPool <= 450) {
        white();              //calls common
        cout << LootPool << endl;           //this is for me testing if it works
    }
    else if (451 <= LootPool && LootPool <= 750) {
        green();            //calls uncommon
        cout << LootPool << endl;
    }
    else if (751 <= LootPool && LootPool <= 900) {
        blue();                //calls rare
        cout << LootPool << endl;
    }
    else if (901 <= LootPool && LootPool <= 980) {
        purple();                //calls epic
        cout << LootPool << endl;
    }
    else if (981 <= LootPool && LootPool <= 1000) {
        yellow();           //calls legendary
        cout << LootPool << endl;
    }

    //just for restarting the program
    cout << "Start over?\n"
         << "'yes' or 'no'\n";
    cin >> answer;

    if (answer == "yes") {
        return main();
    }
    else if (answer == "no") {
        return 0;
    }
    else {
        return 0;
    }
}

//common
void white()
{
    //variable
    int rng;

    //more rng
    srand(time(NULL));
    rng = distributionWhite (gen);

    //display rng number
    cout << "common = " << rng << ".\n";
}

//uncommon
void green()
{
    //variable
    int rng;

    //more rng... again
    srand(time(NULL));
    rng = distributionGreen (gen);

    //display rng number
    cout << "uncommon = " << rng << ".\n"; 
}

//rare
void blue()
{
    //variable
    int rng;

    //even more rng
    srand(time(NULL));
    rng = distributionBlue (gen);

    //display rng number
    cout << "blue = " << rng << ".\n";
}

//epic
void purple()
{
    //var
    int rng;

    //...rng
    srand(time(NULL));
    rng = distributionPurple (gen);

    //dis rng #
    cout << "purple = " << rng << ".\n";
}

//legendary
void yellow()
{
    //var
    int rng;

    //last rng for this code
    srand(time(NULL));
    rng = distributionYellow (gen);

    //dis rng #
    cout << "yellow = " << rng << ".\n";
}
