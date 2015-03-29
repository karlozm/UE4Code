// Fill out your copyright notice in the Description page of Project Settings.

/*
 LowLevelLibrary, Monkeyscape Blueprint Library
 Winter 2014
 */


#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "LowLevelLibrary.generated.h"

/*
 Note:
 All comments that begin with '->' mean that they are just acting as a proxy, and exposing/calling directly
 the method of the same name.
 */

/**
 * 
 */
UCLASS()
class MONKEYSCAPE_API ULowLevelLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
public:
    /*
     Nodes available everywhere (don't requier to specify a "self" context to call upon)
     */
    
    // CurrentLevelName
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", FriendlyName = "Current Level Name", Keywords = "level level"), Category = Game)
    static FString CurrentLevelName(class UObject* WorldContextObject);
    
    // PersistentLevelName
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", FriendlyName = "Persistent Level Name", Keywords = "level"), Category = Game)
    static FName PersistentLevelName(class UObject* WorldContextObject);
    
    // ->StreamingLevelsPrefix
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", FriendlyName = "Streaming Levels Prefix", Keywords = "streaming level"), Category = Game)
    static FString StreamingLevelsPrefix(class UObject* WorldContextObject);
    
    // ValueForOptionsKey - Pass a key and return its value by searching in the "Options" string
    UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", FriendlyName = "Value For Options Key", Keywords = "options key value"), Category = Game)
    static FString ValueForOptionsKey(class UObject* WorldContextObject, FString KeyName);
    
    // NextSequentialLevelName
    UFUNCTION(BlueprintPure, meta = (FriendlyName = "Next Sequential Level Name", Keywords = "sequential level"), Category = Game)
    static FString NextSequentialLevelName(FString FromLevelName);
	
};
