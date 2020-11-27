#include<stdio.h>

int main(){
  FILE *wp;
  char str, mid, r[27] = {'a'}, R[27] = {'A'}, alpha = 'a', Alpha = 'A';
  int a[27] = {0}, i, tmp;
  
  /*---配列r[i],R[i]にそれぞれ小文字、大文字をa~zまで代入-----------------------------*/
  for(int i = 0; i < 26; i++){
    r[i] = alpha;
    R[i] = Alpha;
    alpha++;
    Alpha++;
  }
  r[26] = ' ';
  R[26] = ' ';
  

  /*--ファイルを開く-------------------------------------------*/
  wp = fopen("henkan.txt", "r");

  /*--ファイルが開かなかったときに終了する------------------------*/
  if(wp == NULL){
    printf("file open error\n");
    return -1;
  }

  /*--ファイルからアルファベットの数を数える---------------------------------------*/
  while((str = fgetc(wp)) != EOF){
    if(str >= 'a' && str <= 'z' || str >= 'A' && str <= 'Z' || str == ' '){
      for(int i = 0; i < 27; i++){
        if(str == r[i] || str == R[i]){
          a[i]++;
        }
      }
    }
  }
/*--aから順に出てきた数の出力-----------------*/
  for(int i = 0; i < 27; i++){
    printf("%c:%d\n", r[i], a[i]);
  }
  /*--多い順に並び替え------------------------*/
  for(i = 0; i < 27; i++){
    for(int j = i+1; j < 27; j++){
      if(a[i] < a[j]){
        tmp = a[i];
        mid = r[i];
        a[i] = a[j];
        r[i] = r[j];
        a[j] = tmp;
        r[j] = mid;
      }
    }
  }
  printf("narabekae\n");
  for(i = 0; i < 27; i++){
    printf("%c:%d\n", r[i], a[i]);
  }

    fclose(wp);
    return 0;
  }

