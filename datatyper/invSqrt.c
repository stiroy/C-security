#include <stdio.h>
#include <math.h>
//taken form doom3 https://github.com/id-Software/DOOM-3
float InvSqrt(float x){
    float xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i>>1);
    x = *(float*)&i;
    x = x*(1.5f - xhalf*x*x);
    return x;
}

int main(){
    float f;
    printf("enter value: ");
    scanf("%f",&f);
    printf("the 1/sqrt(%.03f) ~ %f\n", f, InvSqrt(f));
    printf("the 1/sqrt(%.03f) ~ %f\n", f, 1/sqrtf(f));

    return 0;
}