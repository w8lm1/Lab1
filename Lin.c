#include "Lin.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

Lin* GenerateLin(size_t l,size_t size, void* c){
    Lin *C=malloc(sizeof(Lin));
    C->length=l;
    C->elementSize=size;

    C->coefs=malloc(l*size);

    for(int i=0;i<l;i++){
        void *ptr = C->coefs+ i*size;
        memcpy(ptr, c+ i*size, size);
    };
    return C;
}

Lin* Enterdata(){
    printf("Enter your data");
    printf("\nChose integer(0) or double(1)\n");
    Lin* C;
    int u1=0;
    scanf("%d",&u1);
    int u2=0;
    printf("Chose length \n");
    scanf("%d",&u2);
    if(u1==0){
        int* x=malloc(u2*sizeof(int));
        for(int i=0; i<u2; ++i)scanf("%d",&x[i]);
        C=GenerateLin(u2,sizeof(int),x);
    }
    if(u1==1){
        double* x=malloc(u2*sizeof(double));
        for(int i=0; i<u2; ++i)scanf("%lf",&x[i]);
        C=GenerateLin(u2,sizeof(double),x);
    }
    return C;
}

Lin* Creating_random(){
    Lin* C=malloc(sizeof(Lin));
    size_t x;
    size_t y;
    scanf("%d",&x);
    scanf("%d",&y);
    if(x%2==0){
        x= sizeof(int);
        int* tmp=malloc(x*y);
        for(int i=0;i<y;i++){
            tmp[i]=rand()%100;
        }
        C=GenerateLin(y,x,tmp);
        return C;
    }
    if(x%2==1){
        x= sizeof(double);
        double* tmp=malloc(x*y);
        for(int i=0;i<y;i++){
            int z=rand()%10000;
            double o=x+0.0;
            o=o/100;
            tmp[i]=o;
        }
        C = GenerateLin(y,x,tmp);
        return C;
    };
}

void Revers(Lin* C){
    if(C->elementSize== sizeof(int)){
        for (int i=0;i<C->length;++i){
            int x=((int *)C->coefs)[i];
            ((int *)C->coefs)[i]=(-1)*x;
        }
    };
    if(C->elementSize== sizeof(double)){
        for (int i=0;i<C->length;++i){
            double x=((double *)C->coefs)[i];
            ((double *)C->coefs)[i]=(-1)*x;
        }
    };

}

void Getinfint(Lin *C){
    printf("\n---------------------------------------------\n");
    if(C==NULL){printf("This form does not exist");}
    if(C!=NULL){
        if(C->elementSize==sizeof(int)) {
            int l=C->length;
            printf("Length = %d\n",l);
            printf("Int\n");
            for(int i=0;i<l;i++){
                int x = ((int *)C->coefs)[i];
                printf("%d ",x);
            }
            printf("\n");
        }
        else {
            printf("Wrong size of data\n");
        }
        printf("\n---------------------------------------------\n");
    }}
void Getinfdouble(Lin *C){
    printf("\n---------------------------------------------\n");
    if(C==NULL){printf("\nThis form does not exist\n");}
    if(C!=NULL){
        if(C->elementSize==sizeof(double)) {
            int l=C->length;
            printf("Length = %d\n",l);
            printf("Double\n");
            for(int i=0;i<l;i++){
                double x = ((double *)C->coefs)[i];
                printf("%f ",x);
            }
            printf("\n");
        }
        else {
            printf("Wrong size of data\n");
        }
        printf("\n---------------------------------------------\n");
    }}
void InformationGiver(Lin* C) {
    if (C != NULL) {
        if (C->elementSize == sizeof(int)) { Getinfint(C); }
        else { Getinfdouble(C); }
    } else {
        printf("\nEnter data first\n");
    }
}
void Valint(Lin* C,const int* c, int l){
    if (C->elementSize== sizeof(double ) || sizeof(c[0])== sizeof(double)){
        printf("Error, wrong types. Remake your form or values");

    }
    int x=0;
    if(l>=C->length){
        for(int i=0;i<C->length;i++){
            x+=c[i]*((int *)C->coefs)[i];};

    }
    if(l<C->length){
        for(int i=0;i<l;++i){
            x+=c[i]*((int *)C->coefs)[i];
        }
    }
    printf("%d\n",x);

}
void Valdo(Lin* C,const double* c, int l){
    if (C->elementSize== sizeof(int) || sizeof(c[0])== sizeof(int)){
        printf("Error, wrong types. Remake your form or values");

    } else{
    double x=0;
    if (l>=C->length){
        for(int i=0;i<C->length;i++){x+=c[i]*((double *)C->coefs)[i];};
    }
    if (l<C->length){
        for(int i=0;i<l;i++){x+=c[i]*((double *)C->coefs)[i];};
    }
    printf("%lf\n",x);
}
}





