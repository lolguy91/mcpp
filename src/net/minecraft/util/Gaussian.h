#ifndef __GAUSSIAN_H__
#define __GAUSSIAN_H__

class Gaussian {
    double nextNextGaussian;
    bool haveNextNextGaussian;

    Gaussian(){}

    void reset();

    double MknextGaussian(double random1,double random2);
};
#endif // __GAUSSIAN_H__