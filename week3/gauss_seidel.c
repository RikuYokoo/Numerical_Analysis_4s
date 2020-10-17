#include<stdio.h>
//#include"gauss.h"
double get_x1(double x2, double x3)
{
  return( (10.0 - x2 - x3) / 5.0 );
}

double get_x2(double x1, double x3)
{
  return( (12.0 - x1 - x3) / 4.0 );
}

double get_x3(double x1, double x2)
{
  return( (13.0 - 2.0 * x1 - x2) / 3.0);
}

int main()
{
  double x1, x2, x3, b_x1, b_x2, b_x3, diff_x1, diff_x2, diff_x3;
  int i = 0;

  x1 = x2 = x3 = 1.0;

  //for( i=0; i<20; i++)
  while(1)
  {
    b_x1 = x1;
    b_x2 = x2;
    b_x3 = x3;
    x1 = get_x1(x2, x3);
    x2 = get_x2(x1, x3);
    x3 = get_x3(x1, x2);
    if(b_x1 >= x1) //x1の誤差の計算
    {
      diff_x1 = b_x1 - x1;
    }
    else if(b_x1 < x1)
    {
      diff_x1 = x1 - b_x1;
    }

    if(b_x2 >= x2) //x2の誤差の計算
    {
      diff_x2 = b_x2 - x2;
    }
    else if(b_x2 < x2)
    {
      diff_x2 = x2 - b_x2;
    }

    if(b_x3 >= x3) //x3の誤差の計算
    {
      diff_x3 = b_x3 - x3;
    }
    else if(b_x3 < x3)
    {
      diff_x3 = x3 - b_x3;
    }

    printf("[i=%d]\tx1 = %.10f, x2 = %.10f, x3 = %.10f\n", i+1, x1, x2, x3 );

    if(diff_x1 <= 0.0000000001 && diff_x2 <= 0.0000000001 && diff_x3 <= 0.0000000001)//誤差の条件
      break;

    //強制終了
    i++;
    if(i == 100)
      break;
  }

  return 0;
}

