#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <chrono>

struct Seed128bit {
    long seedLo;
    long seedHi;
    Seed128bit(long _seedLo,long _seedHi){
        seedLo = _seedLo;
        seedHi = _seedHi;
    }
};

class Random {
    long SEED_UNIQUIFIER = 8682522807148012L;

    Seed128bit mkSeed128bit(long seed);
    long NewSeed();
};
#endif // __RANDOM_H__