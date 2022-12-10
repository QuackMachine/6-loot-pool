// Make rng on rng
// This is for basic loot pool system...?

#include <iostream>
#include <string>
#include <random>
using namespace std;

int generate (const int from, const int to);

void rarity_Common ();              // 45% of loot pool
void rarity_Uncommon ();            // 30% of loot pool
void rarity_Rare ();                // 15% of loot pool
void rarity_Epic ();                // 8%  of loot pool
void rarity_Legendary ();           // 2%  of loot pool

int main() {
    // Variable declaration
    int lootPool;
    bool run = true;
    char answer[] = "yes";

    while (run) {
        lootPool = generate (1, 1000);      // Generate rarity pulled
        switch (lootPool) {                 // Determine rarity pulled
            case 1 ... 450:
                rarity_Common ();
                break;
    
            case 451 ... 750:
                rarity_Uncommon ();
                break;

            case 751 ... 900:
                rarity_Rare ();
                break;

            case 901 ... 980:
                rarity_Epic ();
                break;

            case 981 ... 1000:
                rarity_Legendary ();
                break;
            
            default:
                break;
        } std::cout << "Lootpool: " << lootPool << "\n";        // Debug which rarity was pulled

        std::cout << "Run again? (YES or NO): ";
        std::cin >> answer;
        for (int i = 0; i < strlen (answer); i++) { answer[i] = tolower (answer[i]); }
        if ((strcmp (answer, "yes") != 0)) { run = false; }
        std::cout << "\n";
    }
}

// Random number generator
int generate (const int from, const int to) {
    std::random_device rd;
    std::mt19937_64 gen (rd ());
    std::uniform_int_distribution <> distribution (from, to);
    return distribution (gen);
}

void rarity_Common () {
    int rng;
    rng = generate (1, 100);                          // Generate rarity ID (or something IDK)
    cout << "Common (White): " << rng << "\n";
}

void rarity_Uncommon () {
    int rng;
    rng = generate (101, 200);                        // Generate rarity ID (or something IDK)
    cout << "Uncommon (Green): " << rng << "\n"; 
}

void rarity_Rare () {
    int rng;
    rng = generate (201, 300);                        // Generate rarity ID (or something IDK)
    cout << "Rare (Blue): " << rng << "\n";
}

void rarity_Epic () {
    int rng;
    rng = generate (301, 400);                        // Generate rarity ID (or something IDK)
    cout << "Epic (Purple): " << rng << "\n";
}

void rarity_Legendary () {
    int rng;
    rng = generate (401, 500);                        // Generate rarity ID (or something IDK)
    cout << "Legendary (Yellow): " << rng << "\n";
}
