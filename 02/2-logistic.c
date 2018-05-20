#include <stdio.h>
#include <math.h>

int main(void){
 int x,t,r,k,xx,x0;
 k=10000;
 r=1.2;
 FILE *fp;
 fp=fopen("output.dat","a");
x0=1;
x=x0+r*(1-x0/k)*x0;

fprintf(fp,"%d,%d\n",0,x0);

 for(t=0;t<300;t++){
 xx=x+r*(1-x/k)*x;

 fprintf(fp,"%d,%d\n",t, xx);
 x=xx;
 }
 fclose(fp);

return 0;
}
