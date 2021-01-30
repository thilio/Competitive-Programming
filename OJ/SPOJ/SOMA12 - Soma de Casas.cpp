#define MAX 100000
#include<bits/stdc++.h>
int bb (int V[],int inic, int maxi, int x,int n){
  int meio;
  meio=(inic + maxi)/2;
  if (inic>maxi)
    return (-1);
  if (inic==maxi && V[inic]!= x)
    return (-1);
  if (V[meio]==x)
    return (meio);
  if (V[meio]>x)
    return(bb(V,inic,meio - 1,x,n));
  if (V[meio]<x)
    return (bb(V,meio + 1,maxi,x,n));
}
int mini (int a,int b){
  if (a<b)
    return(a);
  return(b);
}
int main(){
  int k, n, v[MAX], tru=0,i,aux;
  scanf("%d", &n);
  for(i= 0; i < n; i++){
    scanf("%d", &v[i]);
  }
    scanf("%d", &k);
  for(i=0;i<(n-1) && tru ==0;i++){
    aux=bb(v,i+1,n-1,k-v[i],n);
    if (aux!= -1){
      printf ("%d %d",mini(v[aux],k-v[aux]),k-mini(v[aux],k-v[aux]));
      tru=1;
    }
  }
  return(0);
}
