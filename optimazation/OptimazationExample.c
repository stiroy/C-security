#include <stdio.h>
#include <stdint.h>


int main(){
    // volatile on float's
    // https://stackoverflow.com/questions/61370485/is-it-a-gcc-o2-optimization-bug-different-result-from-o1
    uint32_t A[4] = { 1, 2, 3, 4 };
    float B[4] = { 0, 0, 0, 0 };
    float C[4] = { 5, 6, 7, 8 };
    int i;

    // convert integer A to float B
    for (i = 0; i < 4; i++) 
        B[i] = (float)A[i];

    // memory copy from B to C
    uint32_t *src = (uint32_t*)(B);
    uint32_t *dst = (uint32_t*)(C);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];

    // print C, C should be [1.0, 2.0, 3.0, 4.0]
    for (i = 0; i < 4; i++) 
        printf("%d ", A[i]);
    printf("\n");
    for (i = 0; i < 4; i++) 
        printf("%f ", B[i]);
    printf("\n");
    for (i = 0; i < 4; i++) 
        printf("%f ", C[i]);
    printf("\n");

    return 0;
}