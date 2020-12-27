/*
   1*1の正方形に内接する円を考える。
   →円の半径は r = 0.5, 中心座標は(0.5, 0.5)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double point_where(double x, double y)
{
  return (x - 0.5)*(x - 0.5) + (y - 0.5)*(y - 0.5);
}

int main(){
  int within_range=0, total=0;
  double radius=0.5/*半径*/, x=0.0, y=0.0, circle_area=0.0, pi=0.0, where = 0.0, range, tem_area;

  srand( (unsigned)time(NULL) );

  range = radius*radius;

  printf("試行回数を入力:");
  scanf("%d", &total);

  for(int i = 0; i < total; i++){
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;

    //printf("x = %lf, y = %lf\n", x, y);

    where = point_where(x, y);

    if(where <= range)
      within_range++;
    
    tem_area = (double)within_range/(double)(i+1);
    //printf("%d: area = %lf\n", i+1, tem_area);
  }

  circle_area = (double)within_range/(double)total;

  pi = circle_area/range;

  printf("pi = %10lf\n", pi);

  return 0;
}
