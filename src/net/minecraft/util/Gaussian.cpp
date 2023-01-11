#include <src/net/minecraft/util/Gaussian.h>
#include <math.h>

void Gaussian::reset() {
    haveNextNextGaussian = false;
}

double Gaussian::MknextGaussian(double random1,double random2) {
    double d;
    double d2;
    double d3;
    if (haveNextNextGaussian) {
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    do {
        d2 = 2.0 * random1 - 1.0;
        d = 2.0 * random2 - 1.0;
    } while ((d3 = (d2 *d2) + (d * d)) >= 1.0 || d3 == 0.0);
    double d4 = sqrt(-2.0 * log(d3) / d3);
    nextNextGaussian = d * d4;
    haveNextNextGaussian = true;
    return d2 * d4;
}