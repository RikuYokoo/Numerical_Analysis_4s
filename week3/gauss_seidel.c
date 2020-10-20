#include<stdio.h>
//double x1_error_calc(double, double);
//double x2_error_calc(double, double);
//double x3_error_calc(double, double);
//#include"gauss.h"
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
}
*/

int main()
{
  double x1, x2, x3, b_x1, b_x2, b_x3, diff_x1, diff_x2, diff_x3, a11, a22, a33, e = 0.0000000001;
  double Smatrix[3][3], matrix[3], ab1row[4], ab2row[4], ab3row[4];
  int i = 0, q, I = 1, J = 1, j = 0, brow = 1;

  printf("強制終了の回数を入力してください");
  scanf("%d", &q);

  printf("a11 a12 a13   x1   b1\na21 a22 a23 * x2 = b2\na31 a32 a33   x3   b3\n");//式を表示
/*--a11~a33までの入力　始まり------------------------------------------------------------------*/
  for(int R = 0;R < 9;R++){
    printf("a%d%d:", I, J);
    scanf("%lf",&Smatrix[i][j]);
    //printf("a%d%d\n", i, j);
    J++;
    j++;
    if(j == 3){
      j = 0;
      i++;
    }
    if(J == 4){
      J = 1;
      I++;
    }
  }
  /*--a11~a33の入力　終わり--------------------------------------------------------------------*/
  /*--b1~b3入力　始まり-----------------------------------------------------------------------*/
  for(int i = 0;i < 3;i++){
    printf("b%d1 : ", brow);
    scanf("%lf", &matrix[i]);
    brow++;
  }
  /*--b入力　終わり-----------------------------------------------------------------------*/
  /*--a,b表示始まり-----------------------------------------------------------------------*/
  printf("\n");
  i = 0, j = 0;
  for(int R = 0;R < 9;R++){
    printf("%f\t", Smatrix[i][j]);
    j++;
    if(j == 3){
      j = 0;
      i++;
    }
    if(R == 2){
      printf("\tx1\t\t%.f\n", matrix[0]);
    }
    if(R == 5){
      printf("*\tx2\t=\t%.f\n", matrix[1]);
    }
    if(R == 8){
      printf("\tx3\t\t%.f\n", matrix[2]);
    }
  }
  /*--a,b表示終わり-----------------------------------------------------------------------*/

  //a11,a22,a33に対角成分代入 
  a11 = Smatrix[0][0];
  a22 = Smatrix[1][1];
  a33 = Smatrix[2][2];
    /*--1~3行目を代入する。--------------------------------------------------------------*/
  for(i = 0;i < 3;i++){
    ab1row[i] = Smatrix[0][i];
    ab2row[i] = Smatrix[1][i];
    ab3row[i] = Smatrix[2][i];
  }
  ab1row[3] = matrix[0];
  ab2row[3] = matrix[1];
  ab3row[3] = matrix[2];
  /*--代入終わり。----------------------------------------------------------------------*/

  printf("初期値を決めてください\n");
  printf("x1:"); scanf("%lf", &x1);
  printf("x2:"); scanf("%lf", &x2);
  printf("x3:"); scanf("%lf", &x3);
  
  //x1 = x2 = x3 = 1.0;
  i = 0;
  while(1)
  {
    b_x1 = x1;//1個前のx1をb_x1に代入
    b_x2 = x2;//1個前のx2をb_x2に代入
    b_x3 = x3;//1個前のx2をb_x2に代入
    x1 = (double) ((ab1row[3] - ab1row[1] * x2 -ab1row[2] * x3) / a11);
    x2 = (double) ((ab2row[3] - ab2row[0] * x1 -ab2row[2] * x3) / a22);
    x3 = (double) ((ab3row[3] - ab3row[0] * x1 -ab3row[1] * x2) / a33);

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

    if(diff_x1 <= e && diff_x2 <= e && diff_x3 <= e)//誤差の条件
    {
      printf("Answer:x1 = %.3f x2 = %.3f x3 = %.3f\n", x1, x2, x3);
      break;
    }

    i++;
    //強制終了
    if(i == q)
    {
      printf("試行回数が少ないか解は出ません。\n");
      break;
    }
  }
  return 0;
}

/*double x1_error_calc(double b_x1, double x1)
{
  double diff_x1;

  if(b_x1 >= x1) //x1の誤差の計算
  {
    diff_x1 = b_x1 - x1;
  }
  else if(b_x1 < x1)
  {
    diff_x1 = x1 - b_x1;
  }
  return diff_x1;
}

double x2_error_calc(double b_x2, double x2)
{
  double diff_x2;

  if(b_x2 >= x2) //x2の誤差の計算
  {
    diff_x2 = b_x2 - x2;
  }
  else if(b_x2 < x2)
  {
    diff_x2 = x2 - b_x2;
  }
  return diff_x2;
}

double x3_error_calc(double b_x3, double x3)
{
  double diff_x3;

  if(b_x3 >= x3) //x3の誤差の計算
  {
    diff_x3 = b_x3 - x3;
  }
  else if(b_x3 < x3)
  {
    diff_x3 = x3 - b_x3;
  }
  return diff_x3;
}
*/
