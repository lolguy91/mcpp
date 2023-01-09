#ifndef __MATH_H__
#define __MATH_H__

#include <vector>

float Sin(float input);
float Cos(float input);
float Sqrt(float input);
int Floor(float input);
int Floor(double input);
int Floor_Fast(float input);
long long Lfloor(float input);
int AbsFloor(double input);
float Abs(float input);
int Abs(int input);
int Ceil(float input);
int Ceil(double input);
char Clamp(char input, char ch2, char max);
int Clamp(int input, int min, int max);
long Clamp(long input, long min, long max);
float Clamp(float input, float min, float max);
double Clamp(double input, double min, double max);
double clampedLerp(double input, double min, double max);
float clampedLerp(float input, float min, float max);
double absMax(double d, double d2);
int nextInt(int min, int max);
float nextFloat(float min, float max);
double nextDouble(double min, double max);
double average(std::vector<long> input);

#endif // __MATH_H__