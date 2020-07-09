#include <iostream> // importing separate library
#include <ctime>

void PrintIntroduction(int Difficulty)
{
     // introduction section
    std::cout << "\nAh...Here we are! You are a member of Anonymous group.\n";
    std::cout << "Yopu're task is to crack the and hack in to a govermental system, and expose the corruption!\n";
    std::cout << "GOOD LUCK!! PEOPLE ARE COUNTING ON YOU!!!\n\n";
    std::cout << "You are on LEVEL " << Difficulty << std::endl;

}

bool PlayGame(int Difficulty,int Try, int Limit)
{
    PrintIntroduction(Difficulty);

    //declaring the variables needed for the code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    int TriesLeft = Limit - Try;

    //creating the sum and product values
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //streaming the results to the user
    std::cout << std::endl;
    std::cout << "There are THREE numbers in the code!";
    std::cout << "\nThe SUM of these numbers are: " << CodeSum;
    std::cout << "\nThe PRODUCT of that three number is: " << CodeProduct  << std::endl;

    //Declaring and taking in the input from user for the main loop of the game
    int PlayerGuessA, PlayerGuessB, PlayerGuessC;

    std::cin >> PlayerGuessA;
    std::cin >> PlayerGuessB;
    std::cin >> PlayerGuessC;

    //Creating the values that will be checked for progression in the game

    int GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    int GuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    //creating the check condition and action based on the results
    if (GuessSum == CodeSum)
    {
        std::cout << "\nCONGRATS! You have Passed the Level!\n";
        return true;
    }
    if (Try == Limit)
    {
        std::cout << "\nYou have ran out of TRIES!!!!!";
        return 0;
    }
    else
    {
        std::cout << "\nThat wasn't the correct anwser! Please try again!\n";
        std::cout << "\nYou have " << TriesLeft << " left!!!";
        return false;
    }
    
}

int main()      // start of the main function
{   
    srand(time(NULL));
    int LevelDifficulty = 1;
    int CurrentTry = 0;
    const int MaxLevel = 5;
    const int MaxTry = 5;


    while (LevelDifficulty <= MaxLevel)    //keeps looping till all game levels are complete
    {   

        bool bLevelComplete = PlayGame(LevelDifficulty, CurrentTry, MaxTry);
        std::cin.clear(); //Clears any errors 
        std::cin.ignore(); // Clears out the buffer

        if (bLevelComplete)
        {   
            ++LevelDifficulty; 
        }
        if (CurrentTry == MaxTry)
        {
            return 0;
        }
        else
        {
            ++CurrentTry; 
        }
         
    }
    std::cout << "\nYou made it! The files have been copied and will be securely uploaded! Get out of there ;)";
    return 0;
}