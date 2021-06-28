#include <iostream>
#include <ctime>

void PrintGameIntroduction()
{
    std::cout << "\n\nAn evil sorcerer has enslaved your village to work in the nearby\n"; 
    std::cout << "mines where precious and powerful gems are abundant.\n";
    std::cout << "You sought out the Sorcerer's tower to save your village.\n";
}

void PrintLevelIntroduction(int Difficulty)
{
    std::cout << "\nDirectly in front of you is vault Level " << Difficulty;
    std::cout << "\nEnter the correct code to claim the mystical gems within.\n";
}

bool PlayGame(int Difficulty)
{
    PrintLevelIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std:: cout << "\n+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
   
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    // Check if player's guess is correct
    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n**Correct! You loot the vault and climb to the next floor.**";
        return true;
    } 
    else 
    {
        std::cout << "\n**Wrong! You check the corridor behind you and try again.**";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //Create new random sequence based on the time of day
    PrintGameIntroduction();
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loop the game until all levels complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //CLears any errors
        std::cin.ignore();//Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\n\nWith the help of the power-infused gems you vanquish the Sorcerer";
    std::cout << "\nbut your new power is intoxicating and you can't help but want... more.";
    std::cout << "\n\n***THE END***";

    return 0;
}