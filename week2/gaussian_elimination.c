#include<stdio.h>

int main (){
  int Smatrix[3][3];
  int matrix[3][1];
  int a[3][3];
  int b[3][1];
  double temporary_ab1row[4];//1行目の中継
  double temporary_ab2row[4];//2行目の中継
  double temporary_ab3row[4];//3行目の中継
  double new_ab1row[4];//新しい1行目
  double new_ab2row[4];//新しい2行目
  double new_ab3row[4];//新しい3行目
  int I = 1, J = 1, i = 0, j = 0, brow = 1, a11, a22, a33;//I,J:aの添字  i,j 配列の添字

  printf("a11 a12 a13   x1   b1\na21 a22 a23 * x2 = b2\na31 a32 a33   x3   b3\n");//式を表示
/*a11~a33までの入力　始まり*/
  for(int R = 0;R < 9;R++){
    printf("a%d%d:", I, J);
    scanf("%d",&Smatrix[i][j]);
    printf("a%d%d\n", i, j);
    while(Smatrix[i][j] == '\n')
      scanf("%d",&Smatrix[i][j]);
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
  printf("\n");
  //b output start
  brow = 1;
  for(i = 0;i < 3;i++){
    printf("b%d1 : %d ", brow++, matrix[i][0]);
  }
  printf("\n");
  //計算記述開始
  //a11,a22,a33に代入
  a11 = Smatrix[0][0];
  a22 = Smatrix[1][1];
  a33 = Smatrix[2][2];
  //1:a11を1にするために1行目を/a11する。
    //1行目を代入する。
  for(i = 0;i < 3;i++){
    temporary_ab1row[i] = Smatrix[0][i];
  }
  temporary_ab1row[3] = matrix[0][0];
    //1行目を代入する。終わり
  for(i = 0;i < 4;i++){
    new_ab1row[i] =(double) temporary_ab1row[i] / a11;
  }
  //確認用
     for(i = 0;i < 4;i++){
  printf("%f\n",new_ab1row[i]);
  }
  //2:a21,a31を0にするために2行目-1行目*a21, 3行目-1行目*a31をする。
  //3:a22を1にするために2行目を/a22する。
  //4:a12,a32を0にするために1行目-2行目*a12, 3行目-2行目*a32をする。
  //5:a33を1にするために3行目を/a33する。
  //6:a13,a23を0にするために1行目-3行目*a13, 2行目-3行目*a23をする。
  return 0;
}
