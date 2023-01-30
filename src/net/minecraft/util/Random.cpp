#include <src/net/minecraft/util/Random.h>
#include <src/net/minecraft/util/Math.h>

long mixStafford13(long l) {
    l = (l ^ l >> 30) * -4658895280553007687L;
    l = (l ^ l >> 27) * -7723592293110705685L;
    return l ^ l >> 31;
}

Seed128bit Random::mkSeed128bit(long seed) {
    long l2 = seed ^ 0x6A09E667F3BCC909L;
    long l3 = l2 + -7046029254386353131L;
    return Seed128bit(mixStafford13(l2), mixStafford13(l3));
}

long Random::NewSeed() {
    return (SEED_UNIQUIFIER *= 1181783497276652981L) ^ (std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
}

//PositionalRandomFactory


PositionalRandomFactory::PositionalRandomFactory(long _seed) {
    seed = _seed;
}

RandomSource PositionalRandomFactory::at(int x, int y, int z) {
    long l = getSeed(x, y, z);
    long l2 = l ^ seed;
    return RandomSource(l2);
}

RandomSource PositionalRandomFactory::fromHashOf(std::string tohash) {
    int hash = std::hash<std::string>()(tohash);
    return RandomSource((long)hash ^ seed);
}

//RandomSource

int RandomSource::nextInt() {
    return next(32);
}

int RandomSource::nextInt(int n) {
    int n2;
    int n3;
    if (n <= 0) {
        __glibcxx_assert(true);
    }
    if ((n & n - 1) == 0) {
        return (int)((long)n * (long)next(31) >> 31);
    }
    while ((n3 = next(31)) - (n2 = n3 % n) + (n - 1) < 0) {
    }
    return n2;
}

long RandomSource::nextLong() {
    int n = next(32);
    int n2 = next(32);
    long l = (long)n << 32;
    return l + (long)n2;
}

bool RandomSource::nextBoolean() {
    return next(1) != 0;
}

float RandomSource::nextFloat() {
    return (float)next(24) * 5.9604645E-8f;
}

double RandomSource::nextDouble() {
    int n = next(26);
    int n2 = next(27);
    long l = ((long)n << 27) + (long)n2;
    return (double)l * (double)1.110223E-16f;
}

RandomSource::RandomSource(long l) {
    setSeed(l);
}

RandomSource RandomSource::fork() {
    return RandomSource(nextLong());
}

PositionalRandomFactory RandomSource::forkPositional() {
    return PositionalRandomFactory(nextLong());
}

void RandomSource::setSeed(long l) {
    seed = (l ^ 0x5DEECE66DL) & 0xFFFFFFFFFFFFL;
    gaussianSource.reset();
}

int RandomSource::next(int n) {
    long l;
    l = seed * 25214903917L + 11L & 0xFFFFFFFFFFFFL;
    return (int)(l >> 48 - n);
}

double RandomSource::nextGaussian() {
    return gaussianSource.MknextGaussian(nextDouble(),nextDouble());
}