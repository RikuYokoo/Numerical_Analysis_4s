#include<stdio.h>
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
  FILE *progress;
  double x, delta_x, fx, diff_fx, eps = 0.0000000001;
  int i = 0, n = 100;

  printf("初期値を入力してください。\nx:");
  scanf("%lf", &x);
  
  progress = fopen("Newton_Raphson.txt", "w");

  do{
    fx = x_cosx(x);
    diff_fx = diff_x_cos(x);

    delta_x = -fx / diff_fx;

    x += delta_x;
    
    printf("%d\t:%.10f\n", i+1, x);

    fprintf(progress, "%.10f\t%.10f\n", x, fx);

    i++;
  }while(fabs(delta_x) > eps && i <= n);

  printf("ans = %.10f\n", x);

  fclose(progress);

  return 0;
}
