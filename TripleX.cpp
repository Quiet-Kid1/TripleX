#include <iostream>
#include <ctime>


void PrintIntroduction(int difficulty)
{

 // Print Intro Message in Terminal
    std::cout<< "\n\nYou are a secret agent breaking into a level " << difficulty;
    std::cout<< " secure server room.. \nYou need to enter the correct codes to continue \n\n";
}


bool PlayGame(int difficulty)
{
    PrintIntroduction(difficulty);

    // declare 3 numbers
    const int CodeA = rand() % difficulty + difficulty;
    const int CodeB = rand() % difficulty + difficulty;
    const int CodeC = rand() % difficulty + difficulty;

    /*
    Multiline comment
    */

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // print sum and product in terminal
    std::cout<< "There are 3 numbers in the code";
    std::cout<< "\nThe codes add up to: " << CodeSum;
    std::cout<< "\nThe codes multiply to give: " << CodeProduct;
    std::cout<< std::endl;

    // store Plyer
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout<< "\nYou Entered: " << GuessA << GuessB << GuessC;
    
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout<< "\nGood Job Bro, you entered the right code!";
        return true;
    }else{
        std::cout<< "\nYou Entered the wrong code bro, try again!";
        return false;
    }



}



int main() 
{
    
    srand(time(NULL)); //creates new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); // Discard the buffers

        if (bLevelComplete)
        {
            /* increase the level difficulty */
            ++LevelDifficulty;

        }
        

    }
    
    std:: cout << "\nGreat Work!! you complete all the security level";
    return 0; 
}