#include <stdio.h>
int main (){
  int cont,i,j,max,atual,n;
  atual=max=1;
  scanf ("%d",&n);
  scanf ("%d",&i);
  for(cont=1;cont<n;cont++){
    scanf ("%d",&j);
    if (j>=i){
      atual++;
    }
    else{
      if (atual>max){
        max=atual;
      }
      atual=1;
    }
    i=j;
  }
  if (atual>max){
    max=atual;
  }
  printf ("%d",max);
  return(0);
}
