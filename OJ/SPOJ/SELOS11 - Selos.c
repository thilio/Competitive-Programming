#include<stdio.h>
int primo(long int n){
  long int i=2;
  if (n%i==0)
    return(1);
  i=3;
  while (i*i<=n){
    if (n%i==0)
      return (1);
    i=i+2;
  }
  return(0);
}

int main(){
  long int x;
  int l;
  scanf("%ld",&x);
  l= primo (x);
  if (l==0){
    printf("N");
  }
  else{
    printf ("S");
  }
  return (0);
}
