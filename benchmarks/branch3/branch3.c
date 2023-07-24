#include <stdio.h>
#include <annot.h>
int main(){
    int a,b,c,d,f;
    a = 1;
    if(a > 0) 
        b = 3;
    else if(a == 0)
        c = 4;
    else if(a < 0)
        f = 10;
    d = 5;
    int i;
    if(d > 2){
       for(i = 1;i <= 6;i++){
           ANNOT_MAXITER(6);
           a = 7;
           d = 8;
       }
    }
    else b = 9;
    return 0;
}