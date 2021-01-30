#include <stdio.h>
int somo (int n){
  if (n<0)
    return(0);
  return (n);
}
int main (){
  int n,i,ant,prox,prim,soma=0;
  scanf("%d",&n);
  scanf("%d",&ant);
  prim=ant;
  for (i=1;i<n;i++){
    scanf ("%d",&prox);
    soma = soma + somo(prox-ant-10);
    ant=prox;
  }
  printf ("%d",prox-prim- soma+10);
  return(0);
}
