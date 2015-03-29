# ReloadLevel

As of UE4.7 Blueprints still don't expose a node to read the current level name.

This code will add nodes to get the current level name and some other related utility functions.

Methods:
    FString CurrentLevelName
    FName PersistentLevelName
    FString StreamingLevelsPrefix
    FString ValueForOptionsKey
    FString NextSequentialLevelName
    

These nodes don't require you to pass an Actor object to work.

**Related Thread:**
    https://answers.unrealengine.com/questions/122415/how-to-get-map-name-in-bp.html

As additionally contributed by "SND R Keene", my code would not suit your needs if you're dealing with tiles.