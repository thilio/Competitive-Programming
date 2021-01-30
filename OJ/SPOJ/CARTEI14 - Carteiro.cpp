#include<bits/stdc++.h>
using namespace std;
int bb (int v[],int x,int n){
  int i,fim,ini;
  ini=0;
  fim=n-1;
  while (fim >=ini){
    i=(fim + ini)/2;
    if (v[i]==x){
      return (i);
    }
    if (v[i]>x){
      fim=i-1;
    }
    if (v[i]<x){
      ini=i+1;
    }
  }
  return(-1);
}
int main (){
  int m,n,M[50000],N[50000],i,pos,soma;
  scanf ("%d",&n);
  scanf ("%d",&m);
  for (i=0;i<n;i++){
    scanf ("%d",&N[i]);
  }
  for (i=0;i<m;i++){
    scanf ("%d",&M[i]);
  }
  soma=0;
  pos = 0;
  for (i=0;i<m;i++){
    soma = soma + abs (bb(N,M[i],n)-pos);
    pos=bb(N,M[i],n);
  }
  printf ("%d\n",soma);
  return(0);
}
