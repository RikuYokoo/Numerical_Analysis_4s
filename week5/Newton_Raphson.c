#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double non_linear(double x)
{
  //return x*x*x - 3*x*x + 9*x -8;
  return x + cos(x);
  //return x + exp(x);
  //return cos(x) + sin(x);
}

double diff_non_linear(double x)
{
  //return 3*x*x - 6*x + 9;
  return 1 - sin(x);
  //return 1 + exp(x);
  //return -sin(x) + cos(x);
}

int main(){
  double x, delta_x, fx, diff_fx, eps = 0.0000000001;
  int i = 0, n = 100;
  char str;
  
  printf("初期値を入力してください。\nx:");
  scanf("%lf", &x);
  
  do{
    fx = non_linear(x);
    diff_fx = diff_non_linear(x);

    delta_x = -fx / diff_fx;

    x += delta_x;
    
    printf("%d\t:%.10f\n", i+1, x);
    i++;

    if(i == n){
      printf("%d回繰り返しましたが、解が求まりませんでした。\n終了する場合は'e'を続行する場合は'c'を初期値を再入力する場合は'r'を入力してください。", n);
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
        n += 100;
        continue;
      }else{
        printf("終了します。\n");
        exit(0);
      }

    }
  }while(fabs(delta_x) > eps /*&& i<= n*/);

  printf("%d回目で解が求まりました。\n", i);
  printf("ans = %.10f\n", x);

  return 0;
}
