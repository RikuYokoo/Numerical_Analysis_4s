#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int within_range=0, total=0;
  double x=0.0, y=0.0, circle_area=0.0, pi=0.0, where = 0.0, range;

  srand( (unsigned)time(NULL) );

  range = 0.25;

  total = 2000000000;

  for(int i = 0; i < total; i++){
    x = (double)rand()/RAND_MAX;
    y = (double)rand()/RAND_MAX;

    where = (x - 0.5)*(x - 0.5) + (y - 0.5)*(y - 0.5);


    if(where <= range)
      within_range++;

  circle_area = (double)within_range/(double)(i+1);

  pi = circle_area/range;
    if(i % 10000 == 0)
      printf("%d: pi = %.10lf\n", i, pi);
  }

  circle_area = (double)within_range/(double)total;

  pi = circle_area/range;

  printf("pi = %.10lf\n", pi);

  return 0;
}
