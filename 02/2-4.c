#include <stdio.h>
#include <math.h>

int main(void){
int a, b, c;
double d, e, f;
double g, h;
a=2; b=5;
d=6.0; e=7.5;

c=a+b; f=d-e;
printf("%d %f \n", c, f);

c=a*b; f=d*e;
printf("%d %f \n", c, f);

c=a/b; f=d/e;
printf("%d %f \n", c, f);

c=b%a;
printf("%d \n",c);

f=pow(d,e);
g=log(d);
h=sqrt(e);
printf("%f %f %f \n", f, g, h);

return 0;

}
