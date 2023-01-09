#include <src/com/mojang/math/Constants.h>
#include <src/net/minecraft/util/Math.h>
#include <math.h>
#include <array>
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

double clampedLerp(double input, double min, double max) {
    if (max < 0.0) {
        return input;
    }
    if (max > 1.0) {
        return min;
    }
    return lerp(max, input, min);
}

float clampedLerp(float input, float min, float max) {
    if (max < 0.0f) {
        return input;
    }
    if (max > 1.0f) {
        return min;
    }
    return lerp(max, input, min);
}
double absMax(double d, double d2) {
    if (d < 0.0) {
        d = -d;
    }
    if (d2 < 0.0) {
        d2 = -d2;
    }
    return d > d2 ? d : d2;
}
int nextInt(int min, int max) {
    if (n >= max) {
        return min;
    }
    return rand() * (max - min) + min;
}

float nextFloat(float min, float max) {
    if (min >= max) {
        return min;
    }
    return rand() * (max - min) + min;
}

double nextDouble(double min, double max) {
    if (min >= max) {
        return min;
    }
    return rand() * (max - min) + min;
}