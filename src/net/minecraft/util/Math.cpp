#include <src/com/mojang/math/Constants.h>
#include <src/net/minecraft/util/Math.h>
#include <math.h>
#include <random>

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
int NextInt(int min, int max) {
    if (min >= max) {
        return min;
    }
    return rand() * (max - min) + min;
}

float NextFloat(float min, float max) {
    if (min >= max) {
        return min;
    }
    return rand() * (max - min) + min;
}

double NextDouble(double min, double max) {
    if (min >= max) {
        return min;
    }
    return rand() * (max - min) + min;
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