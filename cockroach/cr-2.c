//駆除するバージョン！
#include <stdio.h>

int main(void){ //1年だけ考える
 int m[180]; //オス
 int f0[180]; //卵を持っていないメス　= インターバル中
 int f1[180]; //卵を持っているメス
 int e[180]; //卵
 int l[180]; //幼虫
 int d=0; //5月スタート 180日目までいく 配列は0～179

 FILE *fp;
 fp = fopen("cr_2.csv","w");
 m[0]=20;
 f0[0]=2;
 f1[0]=18;
 e[0]=0;
 l[0]=0;

m[d]=m[0]; f0[d]=f0[0]; f1[d]=f1[0]; e[d]=e[0]; l[d]=l[0];

/*for(d=0; d<=18; d++){ //in general 産卵開始20日
 m[d]=m[0]; f0[d]=f0[0]; f1[d]=f1[0]; e[d]=e[0]; l[d]=l[0];
 fprintf(fp,"%d,%d,%d,%d,%d,%d\n",d,m[d],f0[d],f1[d],e[d],l[d]);
}*/

int event = 5 ; //駆除

for(d=1; d<=event-1; d++){
 m[d] = m[d-1] + 0.5*l[d-1]/150 - m[d-1]/180;
 //羽化の半分はオス,成虫寿命180日からの死亡率
 f0[d] = f0[d-1] + 0.5*l[d-1]/150 + 0.1*f1[d-1] - 0.1*f0[d-1] - f0[d-1]/180;
 //羽化したもの半分足す,インターバルを終えるもの引く,また妊娠を引く,死亡率
 f1[d] = f1[d-1] - 0.1*f1[d-1] + 0.1*f0[d-1] - f1[d-1]/180;
 // 産卵したばかりのもの(インタに移行)を引く, インタ終わり(また妊娠)を足す,死亡率
 e[d] = e[d-1] - e[d-1]/50 + 0.1*f1[d-1]*25; //孵化したもの引く、産卵されたもの足す
 l[d] = l[d-1] + e[d-1]/50 - l[d-1]/150 ;  //孵化したもの足す、羽化したたもの引く

  fprintf(fp,"%d,%d,%d,%d,%d,%d\n",d,m[d],f0[d],f1[d],e[d],l[d]);
}

//event日
m[d]=m[d-1]*0.5;
f0[d]=f0[d-1]*0.5;
f1[d]=f1[d-1]*0.5;
e[d]=e[d-1];
l[d]=l[d-1]*0.5;
  fprintf(fp,"%d,%d,%d,%d,%d,%d\n",event,m[event],f0[event],f1[event],e[event],l[event]);

for(d=event+1; d<=179; d++){
 m[d] = m[d-1] + 0.5*l[d-1]/150 - m[d-1]/180;
 f0[d] = f0[d-1] + 0.5*l[d-1]/150 + 0.1*f1[d-1] - 0.1*f0[d-1] - f0[d-1]/180;
 f1[d] = f1[d-1] - 0.1*f1[d-1] + 0.1*f0[d-1] - f1[d-1]/180;
 e[d] = e[d-1] - e[d-1]/50 + 0.1*f1[d-1]*25;
 l[d] = l[d-1] + e[d-1]/50 - l[d-1]/150 ;

  fprintf(fp,"%d,%d,%d,%d,%d,%d\n",d,m[d],f0[d],f1[d],e[d],l[d]);
}
 fclose(fp);
 return 0;
}