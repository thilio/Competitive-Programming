#include<stdio.h>
int min (int a, int b){
  if (a>b)
    return (b);
  return(a);
}
int bb (int V[],int inic, int maxi, int x,int n){
  int meio;
  meio=(inic + maxi)/2;
  if (inic>maxi)
    return (n);
  if (inic==maxi && V[inic]!= x)
    return (n);
  if (V[meio]==x)
    return (min(meio,bb(V,inic,meio-1,x,n)));
  if (V[meio]>x)
    return(bb(V,inic,meio - 1,x,n));
  if (V[meio]<x)
    return (bb(V,meio + 1,maxi,x,n));
}
int main (){
  int n,V[100000],q,i,x,aux;
  scanf ("%d",&n);
  scanf ("%d",&q);
  for (i=0;i<n;i++){
    scanf ("%d",&V[i]);
  }
  for (i=0;i<q;i++){
    scanf ("%d",&x);
    aux=bb(V,0,n-1,x,n);
    if (aux==n)
      printf ("-1\n");
    if (aux<n)
      printf ("%d\n",aux);
  }
  return(0);
}
