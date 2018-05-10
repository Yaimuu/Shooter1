#include "complex.h"

float argument(float r1, float i1)
{
    float arg = 0;
    float dist;
    std::complex<float> z1 = std::complex<float>(r1,i1);
    //std::complex<float> z2 = std::complex<float>(r2,i2);

    dist = sqrt(pow(z1.real(),2) + pow(z1.imag(),2));
    arg = 2*atan(z1.imag()/(z1.real()+dist));

    return arg;
}

float argument2(float r1, float i1, float r2, float i2)
{
    float arg = 0;
    float dist;
    std::complex<float> z1 = std::complex<float>(r1,i1);
    std::complex<float> z2 = std::complex<float>(r2,i2);

    dist = sqrt(pow(z2.real() - z1.real(),2) + pow(z2.imag() - z1.imag(),2));
    arg = 2*atan((z2.imag() - z1.imag())/(z2.real() - z1.real()+dist));

    return arg;
}
