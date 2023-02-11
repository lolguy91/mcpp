#ifndef __USER_H__
#define __USER_H__
#include <iostream>

enum UserType{
    LEGACY,
    MOJANG,
    MSA
};

struct User {
    std::string name;
    std::string uuid;
    std::string accessToken;
    std::string xuid;
    std::string clientId;
    UserType type;
    User(){}
    User(std::string _name, std::string _uuid, std::string _accessToken, UserType _type, std::string _xuid = "", std::string _clientId = "") {
        name = _name;
        uuid = _uuid;
        accessToken = _accessToken;
        xuid = _xuid;
        clientId = _clientId;
        type = _type;
    }

    std::string getSessionId() {
        return "token:" + accessToken + ":" + uuid;
    }

    //GameProfile getGameProfile() {
    //    try {
    //        UUID uUID = UUIDTypeAdapter.fromstd::string((std::string)getUuid());
    //        return new GameProfile(uUID, getName());
    //    }
    //    catch (IllegalArgumentException illegalArgumentException) {
    //        return new GameProfile(null, getName());
    //    }
    //}

};

#endif // __USER_H__