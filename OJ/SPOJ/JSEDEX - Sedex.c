#include <stdio.h>
int main(){
  int a,b,c,d,voo=0;
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  scanf("%d",&d);
  if (a>b||a>c||a>d)
    voo=1;
  if (voo==1){
    printf ("N");
  }
  else{
    printf ("S");
  }
  return(0);
}
