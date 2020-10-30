#include<stdio.h>
#include<math.h>

double calc_x_cosx(double x)//x+cos(x)を返す関数
{
  return x + cos(x);
}

int main(){
  double a, b, c, f_x, f_a, f_b, f_c, kakeru_ab, kakeru_ac, kakeru_bc, f_ac, f_bc, diff_ab, e = 0.0000000001;
  int i = 1;
  printf("初期値を入力してください\n");

  printf("a:");
  scanf("%lf", &a);

  printf("b:");
  scanf("%lf", &b);

  f_a = calc_x_cosx(a);//x+cos(x)にx=aを代入
  f_b = calc_x_cosx(b);//x+cos(x)にx=bを代入

  kakeru_ab = f_a * f_b;

  while(kakeru_ab > 0){
    printf("異なる初期値a, bを設定してください\n");
    printf("a:"); scanf("%lf", &a);
    printf("b:"); scanf("%lf", &b);

    f_a = calc_x_cosx(a);
    f_b = calc_x_cosx(b);

    kakeru_ab = f_a * f_b;
  }
  do{

  c = (a + b) / 2;//aとbの中点をcに代入

  f_c = calc_x_cosx(c);

  kakeru_ac = f_a * f_c;
  kakeru_bc = f_b * f_c;

  if(kakeru_ac < 0){
    b = c;
  } else if(kakeru_bc < 0){
    a = c;
  }
  
  f_a = calc_x_cosx(a);
  f_b = calc_x_cosx(b);

  diff_ab = fabs(a - b);

  /*
  if(diff_ab < e){
    ans = a;
    break;
  }
  */
  printf("%d\t:%.10f\n", i, a);
  i++;
  }while(diff_ab > e);

  printf("ans = %.10f\n", a);

  return 0;
}
