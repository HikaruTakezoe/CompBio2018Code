#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
 int r,M,N,x,i,i1,i5,i10,i100,i1000;
 srand(time(NULL));
 M=1,N=6,x=0;
 int k,ave5;
 int a10=0;
 int a100=0;
 int a1000=0;
int a[1000];
for(k=1;k<=1000;){
 for(i=0;i<100;i++){
  r=rand()%(N-M+1)+M;
  x=x+r;
  if(x>=100){
    //printf("%d ",i);
    a[k]=i;
    break;
 }
 }
 x=0;
 k++;
}
i5=(a[1]+a[2]+a[3]+a[4]+a[5])/5;
printf("1:%d\naverage(5):%d \n",a[1],i5);

for(k=1;k<=10;k++){
  a10=a10+a[k];
}
i10=a10/10;
printf("average(10):%d\n",i10);

for(k=1;k<=100;k++){
  a100=a100+a[k];
}
i100=a100/100;
printf("average(100):%d\n",i100);

for(k=1;k<=1000;k++){
  a1000=a1000+a[k];
}
i1000=a1000/1000;
printf("average(1000):%d\n",i1000);

 return 0;
}
