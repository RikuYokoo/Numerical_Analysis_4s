#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){
  FILE *wp;
  char str, moji;
  int i=0, tmp, count=0, ran, j=0, max=100/*出力する文字数を格納*/;

  srand((unsigned int)time(NULL));

  /*file open-------------------------*/
  wp = fopen("henkan.txt", "r");

  /*--ファイルが開かなかったときに終了する------------------------*/
  if(wp == NULL){
    printf("file open error\n");
    return -1;
  }

  /*--ファイルの文字数を数える------------------------*/
  while((str = fgetc(wp)) != EOF){
    i++;
  }

  count = i;
  printf("count = %d\n", count);
/*--ランダムに文字生成-----------------*/
  for(i = 0; i < max; i++){
    rewind(wp);
    ran = rand() % count;
    //printf("\nran = %d\n", ran);
    while((str = fgetc(wp)) != EOF){
      if(j == ran){
        printf("%c", str);
        //printf("%d:%c", i, str);
      }
      j++;
    }
    j=0;
  }


  printf("\n");
    fclose(wp);
    return 0;
  }
