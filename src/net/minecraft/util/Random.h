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

    int nextInt() {
        return next(32);
    }

    int nextInt(int n) {
        int n2;
        int n3;
        if (n <= 0) {
            __glibcxx_assert(false);
        }
        if ((n & n - 1) == 0) {
            return (int)((long)n * (long)next(31) >> 31);
        }
        while ((n3 = next(31)) - (n2 = n3 % n) + (n - 1) < 0) {
        }
        return n2;
    }

    long nextLong() {
        int n = next(32);
        int n2 = next(32);
        long l = (long)n << 32;
        return l + (long)n2;
    }

    bool nextBoolean() {
        return next(1) != 0;
    }

    float nextFloat() {
        return (float)next(24) * 5.9604645E-8f;
    }

    double nextDouble() {
        int n = next(26);
        int n2 = next(27);
        long l = ((long)n << 27) + (long)n2;
        return (double)l * (double)1.110223E-16f;
    }

    RandomSource(long l) {
        setSeed(l);
    }

    RandomSource fork() {
        return RandomSource(nextLong());
    }

    PositionalRandomFactory forkPositional() {
        return PositionalRandomFactory(nextLong());
    }

    void setSeed(long l) {
        seed = (l ^ 0x5DEECE66DL) & 0xFFFFFFFFFFFFL;
        gaussianSource.reset();
    }

    int next(int n) {
        long l;
        l = seed * 25214903917L + 11L & 0xFFFFFFFFFFFFL;
        return (int)(l >> 48 - n);
    }

    double nextGaussian() {
        return gaussianSource.MknextGaussian(nextDouble(),nextDouble());
    }

};
#endif // __RANDOM_H__