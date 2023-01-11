#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <chrono>
#include <string>
#include <src/net/minecraft/util/Gaussian.h>

class RandomSource;

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

class PositionalRandomFactory {
        public:
        long seed;

        PositionalRandomFactory(long _seed);

        RandomSource at(int x, int y, int z);

        RandomSource fromHashOf(std::string tohash);

    };

class RandomSource{
    public:
    int  MODULUS_BITS = 48;
    long MODULUS_MASK = 0xFFFFFFFFFFFFL;
    long MULTIPLIER = 25214903917L;
    long INCREMENT = 11L;
    long seed;
    Gaussian gaussianSource;

    int nextInt();

    int nextInt(int n);

    long nextLong();

    bool nextBoolean();

    float nextFloat();

    double nextDouble();

    RandomSource(long l);

    RandomSource fork();

    PositionalRandomFactory forkPositional();

    void setSeed(long l);

    int next(int n);

    double nextGaussian();

};
#endif // __RANDOM_H__