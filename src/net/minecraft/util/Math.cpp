#include <src/com/mojang/math/Constants.h>
#include <src/net/minecraft/util/Math.h>
#include <src/net/minecraft/util/Random.h>
#include <math.h>
#include <random>
#include <iostream>

float Sin(float input){
    return sin(input);
}

float Cos(float input){
    return cos(input);
}
float Sqrt(float input){
    return sqrt(input);
}
int Floor(float input){
    int inputround = (int)input;
    return input < (float)inputround ? inputround - 1 : inputround;
}
int Floor(double input){
    int inputround = (int)input;
    return input < (float)inputround ? inputround - 1 : inputround;
}
int Floor_Fast(float input){
    return (int)(input + BIG_INT) - BIG_INT;
}
long long Lfloor(float input){
    long inputround = (long)input;
    return input < (double)inputround ? inputround - 1L : inputround;
}

int AbsFloor(double input) {
    return (int)(input >= 0.0 ? input : -input + 1.0);
}

float Abs(float input) {
    return abs(input);
}

int Abs(int input) {
    return abs(input);
}

int Ceil(float input) {
    int inputround = (int)input;
    return input > (float)inputround ? inputround + 1 : inputround;
}

int Ceil(double input) {
    int inputround = (int)input;
    return input > (double)inputround ? inputround + 1 : inputround;
}

char Clamp(char input, char ch2, char max) {
    if (input < ch2) {
        return ch2;
    }
    if (input > max) {
        return max;
    }
    return input;
}

int Clamp(int input, int min, int max) {
    if (input < min) {
        return min;
    }
    if (input > max) {
        return max;
    }
    return input;
}

long Clamp(long input, long min, long max) {
    if (input < min) {
        return min;
    }
    if (input > max) {
        return max;
    }
    return input;
}

float Clamp(float input, float min, float max) {
    if (input < min) {
        return min;
    }
    if (input > max) {
        return max;
    }
    return input;
}

double Clamp(double input, double min, double max) {
    if (input < min) {
        return min;
    }
    if (input > max) {
        return max;
    }
    return input;
}

double ClampedLerp(double input, double min, double max) {
    if (max < 0.0) {
        return input;
    }
    if (max > 1.0) {
        return min;
    }
    return Lerp(max, input, min);
}

float ClampedLerp(float input, float min, float max) {
    if (max < 0.0f) {
        return input;
    }
    if (max > 1.0f) {
        return min;
    }
    return Lerp(max, input, min);
}
double AbsMax(double d, double d2) {
    if (d < 0.0) {
        d = -d;
    }
    if (d2 < 0.0) {
        d2 = -d2;
    }
    return d > d2 ? d : d2;
}
int NextInt(RandomSource randomSource,int min, int max) {
    if (min >= max) {
        return min;
    }
    return randomSource.nextInt(max - min + 1) + min;
}

float NextFloat(RandomSource randomSource,float min, float max) {
    if (min >= max) {
        return min;
    }
    return randomSource.nextFloat() + min;
}

double NextDouble(RandomSource randomSource,double min, double max) {
    if (min >= max) {
        return min;
    }
    return randomSource.nextDouble() * (max - min + 1) + min;
}
 double Average(std::vector<long> input) {
    long sum = 0L;

    for (size_t i = 0; i < input.size(); i++)
    {
        sum += input[i];
    }

    return (double)sum / (double)input.size();
}
bool Equal(float f, float f2) {
    return abs(f2 - f) < 1.0E-5f;
}

bool Equal(double d, double d2) {
    return abs(d2 - d) < (double)1.0E-5f;
}

int PositiveModulo(int n, int n2) {
    return n % n2;
}

float PositiveModulo(float f, float f2) {
    return modf((modf(f,&f2) + f2), &f2);
}

double PositiveModulo(double d, double d2) {
    return modf((modf(d,&d2) + d2), &d2);
}

static int wrapDegrees(int n) {
    int n2 = n % 360;
    if (n2 >= 180) {
        n2 -= 360;
    }
    if (n2 < -180) {
        n2 += 360;
    }
    return n2;
}

float wrapDegrees(float f) {
    float tsy = 360.0f;
    float f2 = modf(f,&tsy);
    if (f2 >= 180.0f) {
        f2 -= 360.0f;
    }
    if (f2 < -180.0f) {
        f2 += 360.0f;
    }
    return f2;
}

double wrapDegrees(double d) {
    double tsy = 360.0f;
    double d2 = modf(d,&tsy);
    if (d2 >= 180.0) {
        d2 -= 360.0;
    }
    if (d2 < -180.0) {
        d2 += 360.0;
    }
    return d2;
}
float degreesDifference(float f, float f2) {
    return wrapDegrees(f2 - f);
}
float degreesDifferenceAbs(float f, float f2) {
    return abs(degreesDifference(f, f2));
}
float rotateIfNecessary(float f, float f2, float f3) {
    float f4 = degreesDifference(f, f2);
    float f5 = Clamp(f4, -f3, f3);
    return f2 - f5;
}

float approach(float f, float f2, float f3) {
    f3 = abs(f3);
    if (f < f2) {
        return Clamp(f + f3, f, f2);
    }
    return Clamp(f - f3, f2, f);
}

float approachDegrees(float f, float f2, float f3) {
    float f4 = degreesDifference(f, f2);
    return approach(f, f + f4, f3);
}

int smallestEncompassingPowerOfTwo(int n) {
    int n2 = n - 1;
    n2 |= n2 >> 1;
    n2 |= n2 >> 2;
    n2 |= n2 >> 4;
    n2 |= n2 >> 8;
    n2 |= n2 >> 16;
    return n2 + 1;
}

bool isPowerOfTwo(int n) {
    return n != 0 && (n & n - 1) == 0;
}

int ceillog2(int n) {
    n = isPowerOfTwo(n) ? n : smallestEncompassingPowerOfTwo(n);
    return MULTIPLY_DE_BRUIJN_BIT_POSITION[(int)((long)n * 125613361L >> 27) & 0x1F];
}

int log2(int n) {
    return ceillog2(n) - (isPowerOfTwo(n) ? 0 : 1);
}

int color(float f, float f2, float f3) {
    return color(Floor(f * 255.0f),Floor(f2 * 255.0f),Floor(f3 * 255.0f));
}

int color(int n, int n2, int n3) {
    int n4 = n;
    n4 = (n4 << 8) + n2;
    n4 = (n4 << 8) + n3;
    return n4;
}

int colorMultiply(int n, int n2) {
    int n3 = (n & 0xFF0000) >> 16;
    int n4 = (n2 & 0xFF0000) >> 16;
    int n5 = (n & 0xFF00) >> 8;
    int n6 = (n2 & 0xFF00) >> 8;
    int n7 = (n & 0xFF) >> 0;
    int n8 = (n2 & 0xFF) >> 0;
    int n9 = (int)((float)n3 * (float)n4 / 255.0f);
    int n10 = (int)((float)n5 * (float)n6 / 255.0f);
    int n11 = (int)((float)n7 * (float)n8 / 255.0f);
    return n & 0xFF000000 | n9 << 16 | n10 << 8 | n11;
}

int colorMultiply(int n, float f, float f2, float f3) {
    int n2 = (n & 0xFF0000) >> 16;
    int n3 = (n & 0xFF00) >> 8;
    int n4 = (n & 0xFF) >> 0;
    int n5 = (int)((float)n2 * f);
    int n6 = (int)((float)n3 * f2);
    int n7 = (int)((float)n4 * f3);
    return n & 0xFF000000 | n5 << 16 | n6 << 8 | n7;
}

float frac(float f) {
    return f - (float)Floor(f);
}

double frac(double d) {
    return d - (double)Lfloor(d);
}

long getSeed(int n, int n2, int n3) {
    long l = (long)(n * 3129871) ^ (long)n3 * 116129781L ^ (long)n2;
    l = l * l * 42317861L + l * 11L;
    return l >> 16;
}

double inverseLerp(double d, double d2, double d3) {
    return (d - d2) / (d3 - d2);
}

float inverseLerp(float f, float f2, float f3) {
    return (f - f2) / (f3 - f2);
}
//bool rayIntersectsAABB(Vec3 vec3, Vec3 vec32, AABB aABB) {
//    double d = (aABB.minX + aABB.maxX) * 0.5;
//    double d2 = (aABB.maxX - aABB.minX) * 0.5;
//    double d3 = vec3.x - d;
//    if (Math.abs(d3) > d2 && d3 * vec32.x >= 0.0) {
//        return false;
//    }
//    double d4 = (aABB.minY + aABB.maxY) * 0.5;
//    double d5 = (aABB.maxY - aABB.minY) * 0.5;
//    double d6 = vec3.y - d4;
//    if (Math.abs(d6) > d5 && d6 * vec32.y >= 0.0) {
//        return false;
//    }
//    double d7 = (aABB.minZ + aABB.maxZ) * 0.5;
//    double d8 = (aABB.maxZ - aABB.minZ) * 0.5;
//    double d9 = vec3.z - d7;
//    if (Math.abs(d9) > d8 && d9 * vec32.z >= 0.0) {
//        return false;
//    }
//    double d10 = Math.abs(vec32.x);
//    double d11 = Math.abs(vec32.y);
//    double d12 = Math.abs(vec32.z);
//    double d13 = vec32.y * d9 - vec32.z * d6;
//    if (Math.abs(d13) > d5 * d12 + d8 * d11) {
//        return false;
//    }
//    d13 = vec32.z * d3 - vec32.x * d9;
//    if (Math.abs(d13) > d2 * d12 + d8 * d10) {
//        return false;
//    }
//    d13 = vec32.x * d6 - vec32.y * d3;
//    return Math.abs(d13) < d2 * d11 + d5 * d10;
//}

float fastInvSqrt(float f) {
    float f2 = 0.5f * f;
    int n =  *((int*)&f);
    n = 1597463007 - (n >> 1);
    f =  *((float*)&n);
    f *= 1.5f - f2 * f * f;
    return f;
}
double fastInvSqrt(double d) {
    double d2 = 0.5 * d;
    long l = *((long*)&d);
    l = 6910469410427058090L - (l >> 1);
    d = *((double*)&l);
    d *= 1.5 - d2 * d * d;
    return d;
}
float fastInvCubeRoot(float f) {
    int n = *((int*)&f);
    n = 1419967116 - n / 3;
    float f2 = *((float*)&n);
    f2 = 0.6666667f * f2 + 1.0f / (3.0f * f2 * f2 * f);
    f2 = 0.6666667f * f2 + 1.0f / (3.0f * f2 * f2 * f);
    return f2;
}

int hsvToRgb(float f, float f2, float f3) {
    float f4;
    float f5;
    int n = (int)(f * 6.0f) % 6;
    float f6 = f * 6.0f - (float)n;
    float f7 = f3 * (1.0f - f2);
    float f8 = f3 * (1.0f - f6 * f2);
    float f9 = f3 * (1.0f - (1.0f - f6) * f2);
    float f10 = 0;
    switch (n) {
        case 0:
            f5 = f3;
            f4 = f9;
            f10 = f7;
            break;
        
        case 1:
            f5 = f8;
            f4 = f3;
            f10 = f7;
            break;
        
        case 2:
            f5 = f7;
            f4 = f3;
            f10 = f9;
            break;
        
        case 3:
            f5 = f7;
            f4 = f8;
            f10 = f3;
            break;
        
        case 4:
            f5 = f9;
            f4 = f7;
            f10 = f3;
            break;
        
        case 5:
            f5 = f3;
            f4 = f7;
            f10 = f8;
            break;
        
        default :
        std::cout << "ERROR: Something went wrong when converting from HSV to RGB. Input was " << f << ", " << f2 << ", " << f3;
        __glibcxx_assert(true);
    };
    int n2 = Clamp((int)(f5 * 255.0f), 0, 255);
    int n3 = Clamp((int)(f4 * 255.0f), 0, 255);
    int n4 = Clamp((int)(f10 * 255.0f), 0, 255);
    return n2 << 16 | n3 << 8 | n4;
}

int murmurHash3Mixer(int n) {
    n ^= n >> 16;
    n *= -2048144789;
    n ^= n >> 13;
    n *= -1028477387;
    n ^= n >> 16;
    return n;
}

long murmurHash3Mixer(long l) {
    l ^= l >> 33;
    l *= -49064778989728563L;
    l ^= l >> 33;
    l *= -4265267296055464877L;
    l ^= l >> 33;
    return l;
}

std::vector<double> cumulativeSum(std::vector<double> arrd) {
    double d = 0.0;
    for (double d2 : arrd) {
        d += d2;
    }
    int n = 0;
    while (n < arrd.size()) {
        int n2 = n++;
        arrd[n2] = arrd[n2] / d;
    }
    for (n = 0; n < arrd.size(); ++n) {
        arrd[n] = (n == 0 ? 0.0 : arrd[n - 1]) + arrd[n];
    }
    return arrd;
}

 int getRandomForDistributionIntegral(RandomSource randomSource,std::vector<double> arrd) {
    double d = randomSource.nextDouble();
    for (int i = 0; i < arrd.size(); ++i) {
        if (!(d < arrd[i])) continue;
        return i;
    }
    return arrd.size();
}

int max(int input, int max) {
    if (input > max) {
        return max;
    }
    return input;
}

std::vector<double> binNormalDistribution(double d, double d2, double d3, int n, int n2) {
    std::vector<double> arrd = std::vector<double>(n2 - n + 1);
    int n3 = 0;
    for (int i = n; i <= n2; ++i) {
        arrd[n3] = max(0.0, d * exp(-((double)i - d3) * ((double)i - d3) / (2.0 * d2 * d2)));
        ++n3;
    }
    return arrd;
}

std::vector<double> binBiModalNormalDistribution(double d, double d2, double d3, double d4, double d5, double d6, int n, int n2) {
    std::vector<double> arrd = std::vector<double>(n2 - n + 1);
    int n3 = 0;
    for (int i = n; i <= n2; ++i) {
        arrd[n3] = max(0.0, d * exp(-((double)i - d3) * ((double)i - d3) / (2.0 * d2 * d2)) + d4 * exp(-((double)i - d6) * ((double)i - d6) / (2.0 * d5 * d5)));
        ++n3;
    }
    return arrd;
}
std::vector<double> binLogDistribution(double d, double d2, int n, int n2) {
    std::vector<double> arrd = std::vector<double>(n2 - n + 1);
    int n3 = 0;
    for (int i = n; i <= n2; ++i) {
        arrd[n3] = max(d * log(i) + d2, 0.0);
        ++n3;
    }
    return arrd;
}

//int binarySearch(int n, int n2, IntPredicate intPredicate) {
//    int n3 = n2 - n;
//    while (n3 > 0) {
//        int n4 = n3 / 2;
//        int n5 = n + n4;
//        if (intPredicate.test(n5)) {
//            n3 = n4;
//            continue;
//        }
//        n = n5 + 1;
//        n3 -= n4 + 1;
//    }
//    return n;
//}

float Lerp(float f, float f2, float f3) {
    return f2 + f * (f3 - f2);
}

double Lerp(double d, double d2, double d3) {
    return d2 + d * (d3 - d2);
}

double Lerp2(double d, double d2, double d3, double d4, double d5, double d6) {
    return Lerp(d2, Lerp(d, d3, d4), Lerp(d, d5, d6));
}

double Lerp3(double d, double d2, double d3, double d4, double d5, double d6, double d7, double d8, double d9, double d10, double d11) {
    return Lerp(d3, Lerp2(d, d2, d4, d5, d6, d7), Lerp2(d, d2, d8, d9, d10, d11));
}

float catmullrom(float f, float f2, float f3, float f4, float f5) {
    return 0.5f * (2.0f * f3 + (f4 - f2) * f + (2.0f * f2 - 5.0f * f3 + 4.0f * f4 - f5) * f * f + (3.0f * f3 - f2 - 3.0f * f4 + f5) * f * f * f);
}

double smoothstep(double d) {
    return d * d * d * (d * (d * 6.0 - 15.0) + 10.0);
}

double smoothstepDerivative(double d) {
    return 30.0 * d * d * (d - 1.0) * (d - 1.0);
}

int sign(double d) {
    if (d == 0.0) {
        return 0;
    }
    return d > 0.0 ? 1 : -1;
}

float rotLerp(float f, float f2, float f3) {
        return f2 + f * wrapDegrees(f3 - f2);
}

int min(int input, int min) {
    if (input < min) {
        return min;
    }
    return input;
}

float diffuseLight(float f, float f2, float f3) {
    return min(f * f * 0.6f + f2 * f2 * ((3.0f + f2) / 4.0f) + f3 * f3 * 0.8f, 1.0f);
}
float rotlerp(float f, float f2, float f3) {
    float f4;
    for (f4 = f2 - f; f4 < -180.0f; f4 += 360.0f) {
    }
    while (f4 >= 180.0f) {
        f4 -= 360.0f;
    }
    return f + f3 * f4;
}
float rotWrap(double d) {
    while (d >= 180.0) {
        d -= 360.0;
    }
    while (d < -180.0) {
        d += 360.0;
    }
    return (float)d;
}
float triangleWave(float f, float f2) {
    return (abs(modf(f,&f2) - f2 * 0.5f) - f2 * 0.25f) / (f2 * 0.25f);
}

double clampedMap(double d, double d2, double d3, double d4, double d5) {
    return ClampedLerp(d4, d5, inverseLerp(d, d2, d3));
}

float clampedMap(float f, float f2, float f3, float f4, float f5) {
    return ClampedLerp(f4, f5, inverseLerp(f, f2, f3));
}

double map(double d, double d2, double d3, double d4, double d5) {
    return Lerp(inverseLerp(d, d2, d3), d4, d5);
}

float map(float f, float f2, float f3, float f4, float f5) {
    return Lerp(inverseLerp(f, f2, f3), f4, f5);
}

double wobble(double d) {
    return d + (2.0 * RandomSource(floor(d * 3000.0)).nextDouble() - 1.0) * 1.0E-7 / 2.0;
}

int roundToward(int n, int n2) {
    return positiveCeilDiv(n, n2) * n2;
}

int positiveCeilDiv(int n, int n2) {
    return -Floor((float)(-n / n2));
}

int randomBetweenInclusive(RandomSource randomSource,int n, int n2) {
    return randomSource.nextInt(n2 - n + 1) + n;
}

float randomBetween(RandomSource randomSource,float f, float f2) {
    return randomSource.nextFloat() * (f2 - f) + f;
}

float normal(RandomSource randomSource,float f, float f2) {
    return f + (float)randomSource.nextGaussian() * f2;
}

double lengthSquared(double d, double d2) {
    return d * d + d2 * d2;
}

double length(double d, double d2) {
    return sqrt(lengthSquared(d, d2));
}
double lengthSquared(double d, double d2, double d3) {
    return d * d + d2 * d2 + d3 * d3;
}
double length(double d, double d2, double d3) {
    return sqrt(lengthSquared(d, d2, d3));
}

int quantize(double d, int n) {
    return floor(d / (double)n) * n;
}
//IntStream outFromOrigin(int n, int n2, int n3) {
//    return outFromOrigin(n, n2, n3, 1);
//}
//IntStream outFromOrigin(int n, int n2, int n3, int n6) {
//    if (n2 > n3) {
//        throw new IllegalArgumentException("upperbound %d expected to be > lowerBound %d".formatted(new Object[]{n3, n2}));
//    }
//    if (n6 < 1) {
//        throw new IllegalArgumentException("steps expected to be >= 1, was %d".formatted(new Object[]{n6}));
//    }
//    if (n < n2 || n > n3) {
//        return IntStream.empty();
//    }
//    return IntStream.iterate(n, n4 -> {
//        int n5 = Math.abs(n - n4);
//        return n - n5 >= n2 || n + n5 <= n3;
//    }, n5 -> {
//        int n6;
//        boolean bl;
//        boolean bl2 = n5 <= n;
//        int n7 = Math.abs(n - n5);
//        boolean bl3 = bl = n + n7 + n6 <= n3;
//        if (!(bl2 && bl || (n6 = n - n7 - (bl2 ? n6 : 0)) < n2)) {
//            return n6;
//        }
//        return n + n7 + n6;
//    });
//}
//
//static {
//    for (int i = 0; i < 257; ++i) {
//        double d = (double)i / 256.0;
//        double d2 = Math.asin(d);
//        Mth.COS_TAB[i] = Math.cos(d2);
//        Mth.ASIN_TAB[i] = d2;
//    }
//}