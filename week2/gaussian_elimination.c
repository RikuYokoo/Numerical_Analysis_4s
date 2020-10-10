#include<stdio.h>

int main (){
  int Smatrix[3][3];
  int matrix[3][1];
  int a[3][3];
  int b[3][1];
  int I = 1, J = 1, i = 0, j = 0, brow = 1;//I,J:aの添字  i,j 配列の添字

  printf("a11 a12 a13   x1   b1\na21 a22 a23 * x2 = b2\na31 a32 a33   x3   b3\n");//式を表示
/*a11~a33までの入力　始まり*/
  for(int R = 0;R < 9;R++){
    printf("a%d%d:", I, J);
    scanf("%d",&Smatrix[i][j]);
    while(Smatrix[i][j] == '\n')
      scanf("%d",&Smatrix[i][j]);
    J++;
    if(j == 2){
      j = 0;
      i++;
    }
    if(J == 4){
      J = 1;
      I++;
    }
    j++;
  }
  //ここまで
  //b input start
  for(int i = 0;i < 3;i++){
    printf("b%d1 : ", brow);
    scanf("%d", &matrix[i][0]);
    while(matrix[i][0] == '\n')
      scanf("%d", &matrix[i][0]);
    brow++;
  }
//aに代入
  for(i = 0;i < 3;i++){
    a[i][0] = Smatrix[i][0];
    a[i][1] = Smatrix[i][1];
    a[i][2] = Smatrix[i][2];
  }
  printf("%d\n", a[1][1]);
  //a output start
    i = 0, j = 0, I = 1, J = 1;
  for(int r = 0;r < 9;r++){
    printf("a%d%d : %d\t", I, J, Smatrix[i][j]);
    J++;
    if(j == 2){
      j = 0;
      i++;
    }
    if(J == 4){
      J = 1;
      I++;
    }
    j++;
  }
  printf("\n");
  //b output start
  brow = 1;
  for(i = 0;i < 3;i++){
    printf("b%d1 : %d ", brow++, matrix[i][0]);
  }
  printf("\n");
  return 0;
}
