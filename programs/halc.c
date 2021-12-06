#include "../os.h"
#include "programs.h"

void halc() {
    int op1=0,op2=0,result=0;
    char optr=0;
    titleBar("HALCULATOR");
    printf("NOTE: You can only input two NATURAL numbers at max (for now)\n\n>>> ");

    do {
        scanf("%i %c %i",&op1,&optr,&op2);
        if(op1==9 && optr=='+' && op2==10) printf("21 ? you stoopid.\njust kidding here's the real result\n");
        switch(optr) {
            case '+': result=op1+op2; break;
            case '-': result=op1-op2; break;
            case '*': result=op1*op2; break;
            case 'x': result=op1*op2; break;
            case '/': result=op1/op2; break;
            default: printf("ayo wtf\n>>> "); continue;
        }
        printf("= %i\n\n>>> ",result);
    } while(1);
}
