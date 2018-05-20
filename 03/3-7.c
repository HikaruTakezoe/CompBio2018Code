#include <stdio.h>
#include <math.h>
int main(void){
 int i;
double x,x0,xa,r,dt,K,xx;
x0=1.0;
x=x0;
xa=x0;
dt=0.05;
K=100;
r=1.1;

FILE *fp;
fp=fopen("3-7.dat","w");
fprintf(fp,"%f, %f, %f\n",0.0,xa,x);

for(i=1;i<200;i++){
  xa=K/(1+(K/x0-1)*exp(-r*dt*i));

  xx=x+dt*r*(1-x/K)*x;
  x=xx;

fprintf(fp,"%f, %f, %f\n",dt*i,xa,x);
}
fclose(fp);
return 0;
}
