#ifndef __GAMECONFIG_H__
#define __GAMECONFIG_H__
#include <iostream>
//struct UserData {
//    User user;
//    PropertyMap userProperties;
//    PropertyMap profileProperties;
//    Proxy proxy;
//    UserData(User _user, PropertyMap _propertyMap, PropertyMap _propertyMap2, Proxy _proxy) {
//        user = user;
//        userProperties = propertyMap;
//        profileProperties = propertyMap2;
//        proxy = proxy;
//    }
//}
struct FolderData {
    std::string gameDirectory;
    std::string resourcePackDirectory;
    std::string assetDirectory;
    std::string assetIndex;
    FolderData(){}
    FolderData(std::string file, std::string file2, std::string file3,  std::string string) {
        gameDirectory = file;
        resourcePackDirectory = file2;
        assetDirectory = file3;
        assetIndex = string;
    }
    //AssetIndex getAssetIndex() {
    //    return assetIndex == null ? new DirectAssetIndex(assetDirectory) : new AssetIndex(assetDirectory, assetIndex);
    //}
};
struct GameData {
    bool demo;
    std::string launchVersion;
    std::string versionType;
    bool disableMultiplayer;
    bool disableChat;
    GameData(){
        launchVersion = "1.19";
    }
    GameData(bool bl, std::string string, std::string string2, bool bl2, bool bl3) {
        demo = bl;
        launchVersion = string;
        versionType = string2;
        disableMultiplayer = bl2;
        disableChat = bl3;
    }
};
struct ServerData {
    
    std::string hostname;
    int port;
    ServerData(){}
    ServerData(std::string string, int n) {
        hostname = string;
        port = n;
    }
};

class GameConfig {
    public:
    //UserData user;
    //DisplayData display;
    FolderData location;
    GameData game;
    ServerData server;
    GameConfig(){}
    GameConfig(/*UserData userData, DisplayData displayData,*/ FolderData folderData, GameData gameData, ServerData serverData) {
        //user = userData;
        //display = displayData;
        location = folderData;
        game = gameData;
        server = serverData;
    }

};


#endif // __GAMECONFIG_H__