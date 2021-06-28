// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
    
    PrintLine(TEXT("The Hidden Word is: %s."), *HiddenWord);//Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else //Check PlayerGuess
    {
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    //Welcome the player
    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cakes"); 
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine(TEXT("You have %i lives."), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue..."));//Prompt player for Guess

    const TCHAR HiddenWordArray[] = TEXT("cakes");
    PrintLine(TEXT("Character 1 of the hidden word is: %c"), HiddenWordArray[0]);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    ClearScreen();
    PrintLine(TEXT("Wrong. \nYou have no lives left."));
    PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
    PrintLine(TEXT("Press Enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
        bGameOver = true;
        PrintLine(TEXT("Press Enter to play again."));
        return;
    } 
    
    //Check right number of characters
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The Hidden Word is %i characters long."), HiddenWord.Len());
        PrintLine(TEXT("Guess again and press enter."));
        return;
    }      

    //Check if isogram
    if(IsIsogram(Guess) == false)
    {
        PrintLine(TEXT("No repeating letters, guess again."));
        return;
    }
    
     //Remove a life
    PrintLine(TEXT("Wrong. \nYou now have %i lives left."), --Lives);
    
    if (Lives <= 0)
    {
        EndGame();
        return;
    } 
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    for(int32 i = 0; i <= Word.Len(); i++)
    {
        if(Word[i] == Word[i+1])
        {
            return false;
        }
    }
    return true;
}