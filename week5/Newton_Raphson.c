#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double x_cosx(double x)
{
  return x + cos(x);
}

double diff_x_cos(double x)
{
  return 1 - sin(x);
}

int main(){
  double x, delta_x, fx, diff_fx, eps = 0.0000000001;
  int i = 0, n = 100;
  char str;
  
  printf("初期値を入力してください。\nx:");
  scanf("%lf", &x);
  
  do{
    fx = x_cosx(x);
    diff_fx = diff_x_cos(x);

    delta_x = -fx / diff_fx;

    x += delta_x;
    
    printf("%d\t:%.10f\n", i+1, x);
    i++;

    if(i == n){
      printf("解が求まりませんでした。\n終了する場合は'e'を続行する場合は'c'を初期値を再入力する場合は'r'を入力してください。");
      scanf("%c", &str);
      while(str == '\n')
        scanf("%c", &str);
      if(str == 'e'){
        printf("終了します。\n");
        exit(0);
      }
      else if(str == 'r'){
        printf("初期値をもう一度入力してください。\n");
        printf("x:"); scanf("%lf", &x);
        i = 0;
        continue;
      }else if(str == 'c'){
        continue;
      }else{
        printf("終了します。\n");
        exit(0);
      }

    }
  }while(fabs(delta_x) > eps /*&& i<= n*/);

  printf("ans = %.10f\n", x);

  return 0;
}
