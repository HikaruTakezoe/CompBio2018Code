#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 50
 int main(void){
  int a[N],aa[N];
  int i,t,r1,r2,r,k,T,TT,A,B;
  srand(time(NULL));
  k=40;
  TT=0;
  B=0;

for(T=0;T<1000;T++){
  for(i=0;i<k;i++){
   a[i]=0;
  }
  for(i=k;i<N;i++){
  a[i]=1;
  }

for(t=1;t<100;t++){
    for(i=0;i<N;i++){
  r1=rand()%N;
  r2=rand()%N;
  r=rand()%2;

    if(r==0){
      aa[i]=a[r1];
    }
    if(r==1){
      aa[i]=a[r2];
    }
  }
  for(i=0;i<N;i++){
  a[i]=aa[i];
  }
A=0;
  for(i=0;i<N;i++){
   A=A+a[i];
  }
  if(A==0){
   B=B+1;
   TT=TT+t;
   break;
 }
}
if(B==100){
 printf("%d\n",TT/100);
 break;
}
}
 return 0;
}
