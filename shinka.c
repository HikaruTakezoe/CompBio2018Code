#include <stdio.h>

int main(void){

double k,x;

k=1;
for(x=0.01;x<=0.90000;){

x=0.99*x+0.01;

k++;
}
printf("%f %f",k,x);

return 0;
}
