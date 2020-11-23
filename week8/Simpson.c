#include<stdio.h>
#include<unistd.h>

double calc(double x)
{
  return x*x*x*x - 2*x*x*x + x*x - 3*x +1;
  //return x*x + 2*x - 1;
}

int main(){
  int n;
  double y, delta_x, a, b, c, ans, mid, xn = 0;

  printf("積分範囲は？\n");
  printf("上b:");
  scanf("%lf", &b);
  printf("下a:");
  scanf("%lf", &a);

  c = b - a;

  printf("積分区間は%fです.\n何等分しますか.(nは2倍されます)\n", c);
  scanf("%d", &n);

  n *= 2;
  printf("%d\n", n);//deleat
  sleep(2);//deleat

  delta_x =(double) c / n;

  for(int i = 0; i <= n; i++){
    if(i == 0){
      y = calc(a);
      printf("start\n");
    }else if(i == n){
      y = calc(b);
      printf("end\n");
    }else if(i % 2 == 0){
      y = 2 * calc(xn);
      printf("偶数\n");
    }else{
      y = 4 * calc(xn);
      printf("奇数\n");
    }

    mid += y;
    printf("%d%f\n", i, mid);
    xn += delta_x;
  }
  
  ans = delta_x * mid / 3;

  printf("ans is %f\n", ans);

  return 0;
}

