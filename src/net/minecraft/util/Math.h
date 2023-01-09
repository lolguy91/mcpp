#ifndef __MATH_H__
#define __MATH_H__

#include <vector>

float                   Sin(float input);
float                   Cos(float input);
float                   Sqrt(float input);
int                     Floor(float input);
int                     Floor(double input);
int                     Floor_Fast(float input);
long long               Lfloor(float input);
int                     AbsFloor(double input);
float                   Abs(float input);
int                     Abs(int input);
int                     Ceil(float input);
int                     Ceil(double input);
char                    Clamp(char input, char ch2, char max);
int                     Clamp(int input, int min, int max);
long                    Clamp(long input, long min, long max);
float                   Clamp(float input, float min, float max);
double                  Clamp(double input, double min, double max);
double                  ClampedLerp(double input, double min, double max);
float                   ClampedLerp(float input, float min, float max);
double                  AbsMax(double d, double d2);
int                     NextInt(int min, int max);
float                   NextFloat(float min, float max);
double                  NextDouble(double min, double max);
double                  Average(std::vector<long> input);
bool                    Equal(float f, float f2);
bool                    Equal(double d, double d2);
int                     PositiveModulo(int n, int n2);
float                   PositiveModulo(float f, float f2);
double                  PositiveModulo(double d, double d2);
static int              wrapDegrees(int n);
float                   wrapDegrees(float f);
double                  wrapDegrees(double d);
float                   degreesDifference(float f, float f2);
float                   degreesDifferenceAbs(float f, float f2);
float                   rotateIfNecessary(float f, float f2, float f3);
float                   approach(float f, float f2, float f3);
float                   approachDegrees(float f, float f2, float f3);
int                     smallestEncompassingPowerOfTwo(int n);
bool                    isPowerOfTwo(int n);
int                     ceillog2(int n);
int                     log2(int n);
int                     color(float f, float f2, float f3);
int                     color(int n, int n2, int n3);
int                     colorMultiply(int n, int n2);
int                     colorMultiply(int n, float f, float f2, float f3);
float                   frac(float f);
double                  frac(double d);
long                    getSeed(int n, int n2, int n3);
double                  inverseLerp(double d, double d2, double d3);
float                   inverseLerp(float f, float f2, float f3);
double                  atan2(double d, double d2);
float                   fastInvSqrt(float f);
double                  fastInvSqrt(double d);
float                   fastInvCubeRoot(float f);
int                     hsvToRgb(float f, float f2, float f3);
int                     murmurHash3Mixer(int n);
long                    murmurHash3Mixer(long l);
std::vector<double>     cumulativeSum(std::vector<double> arrd);
int                     getRandomForDistributionIntegral(std::vector<double> arrd);
int                     max(int input, int max);
std::vector<double>     binNormalDistribution(double d, double d2, double d3, int n, int n2);
std::vector<double>     binBiModalNormalDistribution(double d, double d2, double d3, double d4, double d5, double d6, int n, int n2);
std::vector<double>     binLogDistribution(double d, double d2, int n, int n2);
float                   Lerp(float f, float f2, float f3);
double                  Lerp(double d, double d2, double d3);
double                  Lerp2(double d, double d2, double d3, double d4, double d5, double d6);
double                  Lerp3(double d, double d2, double d3, double d4, double d5, double d6, double d7, double d8, double d9, double d10, double d11);
float                   catmullrom(float f, float f2, float f3, float f4, float f5);
double                  smoothstep(double d);
double                  smoothstepDerivative(double d);
int                     sign(double d);

#endif // __MATH_H__