#include<stdio.h>
#include<math.h>

double calc(double x)
{
  //return x*x*x*x - 2*x*x*x + x*x - 3*x +1;
  return 1/x;
  //return x*x + 2*x - 1;
}

int main(){
  double y, delta_x, a, b, c, ans, mid = 0, n, xn = 0;
  

  printf("積分範囲は？\n");
  printf("上b:");
  scanf("%lf", &b);
  printf("下a:");
  scanf("%lf", &a);

  c = b - a;

  printf("積分区間は%fです.\n何等分しますか.\n", c);
  scanf("%lf", &n);

  delta_x = c/n;
  printf("%f\n", delta_x);
  xn = a;

  for(int i = 0; i <= n; i++){
    if(i == 0){
      y = calc(a);
      printf("start\n");
    }else if(i == n){
      y = calc(b); 
    }else{
      y = 2 * calc(xn);
    }
    mid += y;
    printf("%d%f\n", i, mid);
    xn += delta_x;
  }
  ans = delta_x * mid / 2;

  printf("ans is %f\n", ans);

  return 0;
}


