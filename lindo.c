#include "Lin.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

Lin* Sumdo(Lin* a, Lin* b){
    if(a->length!=b->length){
        printf("Length a != Length b, rewrite one of your forms");
        return NULL;
    };
    if(a->elementSize==sizeof(int) || b->elementSize== sizeof(int)){
        printf("One of element sizes is wrong, rewrite one of your forms");
        return NULL;
    }
    Lin *C=malloc(sizeof(Lin));

    size_t l=a->length;

    size_t x;
    x= sizeof(double);
    double* iar;
    iar=malloc(x*l);
    for(int i=0;i<l;++i){
        double a1=((double *)a->coefs)[i];
        double b1=((double *)b->coefs)[i];
        iar[i]=a1+b1;
        //printf("\n%f+%f=%f\n",a1,b1,iar[i]);
    };
    C=GenerateLin(l,x,iar);
    return C;
}

Lin* Mindo(Lin* a, Lin* b){
    Revers(b);
    if(a->length!=b->length){
        printf("Length a != Length b, rewrite one of your forms");
        return NULL;
    };
    if(a->elementSize==sizeof(int) || b->elementSize== sizeof(int)){
        printf("One or two of element sizes is wrong, rewrite one of your forms");
        return NULL;
    }
    Lin *C=malloc(sizeof(Lin));

    size_t l=a->length;

    size_t x;
    x= sizeof(double);
    double* iar;
    iar=malloc(x*l);
    for(int i=0;i<l;++i){
        double a1=((double *)a->coefs)[i];
        double b1=((double *)b->coefs)[i];
        iar[i]=a1+b1;
        //printf("\n%f+%f=%f\n",a1,b1,iar[i]);
    };
    C=GenerateLin(l,x,iar);
    Revers(b);
    return C;}
	
Lin* Multdo(Lin* a, double x){
    if(a->elementSize!= sizeof(double) || sizeof (x)!= sizeof(double) ){
        printf("Wrong type of elements! Remake your form or remamake your value");
        return NULL;
    }
    Lin* C= malloc(sizeof(Lin));

    double* temp=malloc(a->length* sizeof(double));

    for(int i=0;i<a->length;++i){
        double z=((double*)a->coefs)[i];
        temp[i]=x*z;
        //printf("%1lf * %1lf = %1lf\n",((double*)a->coefs)[i],x,temp[i]);
    };
    size_t l=a->length;

    printf("\n");
    C = GenerateLin(l,sizeof(double),temp);
    return C;
}