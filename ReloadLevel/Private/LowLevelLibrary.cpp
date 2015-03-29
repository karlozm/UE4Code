// Fill out your copyright notice in the Description page of Project Settings.

#include "Monkeyscape.h"
#include "LowLevelLibrary.h"

#pragma mark - Class Methods

AGameMode* GetGameModeForWorldContextObject(class UObject* WorldContextObject)
{
    UWorld* const CurrentWorld = GEngine->GetWorldFromContextObject(WorldContextObject);
    check(CurrentWorld);
    
    AGameMode* const CurrentGameMode = CurrentWorld->GetAuthGameMode<AGameMode>();
    
    return CurrentGameMode;
}

#pragma mark - Public Methods

FString ULowLevelLibrary::CurrentLevelName(class UObject* WorldContextObject)
{
    //    APlayerController* LocalPlayerController = GEngine->GetFirstLocalPlayerController(GEngine->GetWorldFromContextObject(WorldContextObject));
    return GEngine->GetWorldFromContextObject(WorldContextObject)->GetMapName();
}

FName ULowLevelLibrary::PersistentLevelName(class UObject* WorldContextObject)
{
    return GEngine->GetWorldFromContextObject(WorldContextObject)->CommittedPersistentLevelName;
}

FString ULowLevelLibrary::StreamingLevelsPrefix(class UObject* WorldContextObject)
{
    return GEngine->GetWorldFromContextObject(WorldContextObject)->StreamingLevelsPrefix;
}

FString ULowLevelLibrary::ValueForOptionsKey(class UObject* WorldContextObject, FString KeyName)
{
    AGameMode* const CurrentGameMode = GetGameModeForWorldContextObject(WorldContextObject);
    FString KeyValue = FString("");
    
    if (CurrentGameMode)
    {
        FString OptionsString = CurrentGameMode->OptionsString;
        KeyValue = CurrentGameMode->ParseOption(OptionsString, KeyName);
    }
    
    return KeyValue;
}

FString ULowLevelLibrary::NextSequentialLevelName(FString FromLevelName)
{
    // WARNING: for this project i'm assuming that all levels are prefixed 'Level_'
    
    // remove prefix
    FString LevelNumberString = FromLevelName.Replace(TEXT("Level_"), TEXT(""));
    
    // convert to number & increment
    int32 LevelNumber = FCString::Atoi(*LevelNumberString);
    LevelNumber++;
    
    FString SequenceString = FString::FromInt(LevelNumber);
    if (SequenceString.Len() < 2)
    {
        SequenceString = FString("0") + SequenceString;
    }
    
    FString NextLevelName = FString("Level_") + SequenceString;
    
    return NextLevelName;
}
