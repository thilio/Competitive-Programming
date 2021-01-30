#include<stdio.h>
int main(){
  int x;
  long int max;
  max=1;
  scanf("%d",&x);
  while (x!=0){
    max=x*max;
    x=x-1;
  }
  printf ("%ld",max);
  return(0);
}