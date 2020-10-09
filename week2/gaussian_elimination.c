#include<stdio.h>

int main (){
  int matrix[3][3];
  int a[3][3];
  int I = 1, J = 1, i = 0, j = 0;

  printf("a11 a12 a13   x1   b1\na21 a22 a23 * x2 = b2\na31 a32 a33   x3   b3\n");

  for(int R = 0;R < 9;R++){
    printf("a%d%d:", I, J);
    scanf("%d",&matrix[i][j]);
    while(matrix[i][j] == '\n')
      scanf("%d",&matrix[i][j]);
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
    //if(i >= 2 && j == 2) break;
  }
  for(i = 0;i < 3;i++){
    a[i][0] = matrix[i][0];
    a[i][1] = matrix[i][1];
    a[i][2] = matrix[i][2];
  }
  printf("%d\n", a[1][1]);
    i = 0;
    j = 0;
    I = 1;
    J = 1;
  for(int r = 0;r < 9;r++){
    //i = 0, j = 0, I = 1, J = 1;
    printf("a%d%d : %d", I, J, matrix[i][j]);
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
  return 0;
}
