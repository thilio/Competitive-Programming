#include<stdio.h>
int main(){
  int cont=0,n,i,x, V[1000001];
  scanf("%d",&n);
  for(i=0;i<1000001;i++){
    V[i]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d",&x);
    V[x]=1;
  }
  for(i=0;i<1000001;i++){
    if (V[i]!=0)
      cont++;
  }
  printf ("%d",cont);
  return(0);
}
