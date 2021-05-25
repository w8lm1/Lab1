#ifndef LIN_H
#define LIN_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#endif //LIN_H
typedef struct Lin Lin;
struct Lin{
    size_t elementSize;
    size_t length;
    void* coefs;
};
Lin* GenerateLin(size_t l,size_t size, void* c);
Lin* Enterdata();
Lin* Creating_random();

void Revers(Lin* C);
void Getinfint(Lin *C);
void Getinfdouble(Lin *C);
void InformationGiver(Lin* C);
void Valint(Lin* C,const int* c, int l);
void Valdo(Lin* C,const double* c, int l);
