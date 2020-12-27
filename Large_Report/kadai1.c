#include<stdio.h>

int main(){
  FILE *rp, *wp;
  char str;

  rp = fopen("gousei.txt", "r");
  wp = fopen("henkan.txt", "w");

  if(rp == NULL){
    printf("file open error\n");
    return -1;
  }
  if(wp == NULL){
    printf("file open error\n");
    return -1;
  }

  while((str = fgetc(rp)) != EOF){
    if(str >= 'a' && str <= 'z' || str >= 'A' && str <= 'Z'){
      putchar(str);
      fputc(str, wp);
    }else if(str == ' ' || str == '\n'){
      putchar(str);
      fputc(str, wp);
    }else{
      str = ' ';
      putchar(str);
      fputc(str, wp);
    }
  }

    fclose(rp);
    fclose(wp);

    return 0;
  }

