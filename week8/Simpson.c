#include<stdio.h>

double calc(double x)
{
  //return x*x*x*x - 2*x*x*x + x*x - 3*x +1;
  //return x*x + 2*x - 1;
  return 1 / x;
}

int main(){
  int n;
  double y, delta_x, a, b, c, ans, mid, xn = 0;

  /*
  printf("積分範囲は？\n");
  printf("上b:");
  scanf("%lf", &b);
  printf("下a:");
  scanf("%lf", &a);
  */
  /*--積分区間:a下端,b上端--------------------------------------*/
  //b = 3;
  //a = 0;
  a = 1;
  b = 2;

  c = b - a;

  /*--等分nを決める入力------------------------*/
  printf("積分区間は%fです.\n何等分しますか.(nは2倍されます)\n", c);
  scanf("%d", &n);

  n *= 2;

  /*---⊿xを決める------------------------------------------*/
  delta_x =(double) c / n;
  printf("delta_x = %f\n", delta_x);

  /*---シンプソン法の計算-----------------------------------*/
  xn = a;
  for(int i = 0; i <= n; i++){
    if(i == 0){
      y = calc(a);
    }else if(i == n){
      y = calc(b);
    }else if(i % 2 == 0){
      y = 2 * calc(xn);
    }else{
      y = 4 * calc(xn);
    }

    mid += y;
    xn += delta_x;
  }
  
  ans = delta_x * mid / 3;

  /*---結果の表示-----------------------------------------------*/
  printf("ans is %f\n", ans);

  return 0;
}

