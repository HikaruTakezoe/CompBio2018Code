#include <stdio.h>
#include <math.h>

int main(void){
 double S,I,R;
 double dt,gamma,beta;
 int t;
 gamma=0.1;
 beta=0.002;
 double ss,ii,rr;
int i;
t=0.0;
dt=0.001;

FILE *fp;
fp = fopen("output_6-4.csv","w");
S=208;
I=2;
R=590;

fprintf(fp, "%d,%f,%f,%f\n",t,S,I,R);

for(i=1;i<=100000;i++){
 t=dt*i;
 ss=(1-beta*I*dt)*S;
 ii=(1+beta*S*dt-gamma*dt)*I;
 rr=R+gamma*I*dt;
S=ss;
I=ii;
R=rr;
 if(i%100==0){
  fprintf(fp, "%d,%f,%f,%f\n",t,S,I,R);
 }
}

fclose(fp);
return 0;
}
