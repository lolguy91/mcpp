#include <src/net/minecraft/util/Random.h>

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