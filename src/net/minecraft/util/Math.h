#ifndef __MATH_H__
#define __MATH_H__

#include <vector>

float       Sin(float input);
float       Cos(float input);
float       Sqrt(float input);
int         Floor(float input);
int         Floor(double input);
int         Floor_Fast(float input);
long long   Lfloor(float input);
int         AbsFloor(double input);
float       Abs(float input);
int         Abs(int input);
int         Ceil(float input);
int         Ceil(double input);
char        Clamp(char input, char ch2, char max);
int         Clamp(int input, int min, int max);
long        Clamp(long input, long min, long max);
float       Clamp(float input, float min, float max);
double      Clamp(double input, double min, double max);
double      ClampedLerp(double input, double min, double max);
float       ClampedLerp(float input, float min, float max);
double      AbsMax(double d, double d2);
int         NextInt(int min, int max);
float       NextFloat(float min, float max);
double      NextDouble(double min, double max);
double      Average(std::vector<long> input);

#endif // __MATH_H__