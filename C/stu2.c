#include<stdio.h>
int main(){
    double num;
    printf("Enter a number: ");
    scanf("%lf",&num);
    if(num>0){
        printf("%.2lf is positive.\n",num);
    }else if(num<0){
        printf("%.2lf is negative.\n",num);
    }else{
        printf("%.2lf is zero.\n",num);
    }
    return 0;
}