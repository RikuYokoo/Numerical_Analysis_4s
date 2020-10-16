#include<stdio.h>
#include"gauss.h"
/*double get_x1(double x2, double x3)
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
}*/

int main()
{
  double x1, x2, x3;
  int i;

  x1 = x2 = x3 = 1.0;

  for( i=0; i<20; i++)
  {
    x1 = get_x1(x2, x3);
    x2 = get_x2(x1, x3);
    x3 = get_x3(x1, x2);
    printf("[i=%d] x1 = %f, x2 = %f, x3 = %f\n", i+1, x1, x2, x3 );
  }

  return 0;
}

