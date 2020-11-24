#include<stdio.h>

double calc(double x)
{
  //return x*x*x*x - 2*x*x*x + x*x - 3*x +1;
  return 1/x;
}

int main(){
  double y, delta_x, a, b, c, ans, mid = 0, n, xn = 0;
  

  /*
  printf("積分範囲は？\n");
  printf("上b:");
  scanf("%lf", &b);
  printf("下a:");
  scanf("%lf", &a);
  */

  /*--積分区間:a下端,b上端--------------------------------------*/
  //a = 0;
  //b = 3;
  a = 1;
  b = 2;

  c = b - a;//積分範囲

  /*--等分nを決める入力------------------------*/
  printf("積分区間は%fです.\n何等分しますか.\n", c);
  scanf("%lf", &n);

  /*---⊿xを決める------------------------------------------*/
  delta_x = c/n;
  printf("delta_x = %f\n", delta_x);
  xn = a;

  /*---台形法の計算-------------------------*/
  for(int i = 0; i <= n; i++){
    if(i == 0){
      y = calc(a);
    }else if(i == n){
      y = calc(b); 
    }else{
      y = 2 * calc(xn);
    }
    mid += y;
    xn += delta_x;
  }
  ans = delta_x * mid / 2;

  /*---結果表示------------------------------*/
  printf("ans is %f\n", ans);

  return 0;
}


