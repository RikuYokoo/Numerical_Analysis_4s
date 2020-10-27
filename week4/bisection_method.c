#include<stdio.h>
#include<math.h>

double calc_x_cosx(double x)
{
  return x + cos(x);
}

int main(){
  double x, m_x, a, b, c, f_x, f_a, f_b, f_c, kakeru_ab, kakeru_ac, kakeru_bc, f_ac, f_bc, ans, diff_ab, e = 0.000001;
  printf("初期値を入力してください\n");

  printf("a:");
  scanf("%lf", &a);

  printf("b:");
  scanf("%lf", &b);

  f_a = calc_x_cosx(a);
  f_b = calc_x_cosx(b);

  kakeru_ab = f_a * f_b;

  while(kakeru_ab > 0){
    printf("異なる初期値a, bを設定してください\n");
    printf("a:"); scanf("%lf", &a);
    printf("b:"); scanf("%lf", &b);

    f_a = calc_x_cosx(a);
    f_b = calc_x_cosx(b);

    kakeru_ab = f_a * f_b;
  }
  while(1){

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

  if(diff_ab < e){
    ans = a;
    break;
  }
  }

  printf("ans = %f\n", ans);

  return 0;
}
