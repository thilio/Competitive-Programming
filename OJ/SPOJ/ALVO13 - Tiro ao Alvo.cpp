#include<bits/stdc++.h>
using namespace std;
int bb (long long C[], long long x,long long y,int n){
  int ini,fim,meio,best=n;
  ini=0;fim=n-1;
  while (fim>=ini){
    meio = (ini + fim)/2;
    if (C[meio]*C[meio]>= (x*x + y*y)){
      best=meio;
      fim=meio-1;
    }
    else{
      ini=meio+1;
    }
  }
  return (best);
}
int main(){
  int nc,i;
  long long pontos=0,tirox=0,tiroy=0,C[100000],nt;
  scanf ("%d",&nc);scanf ("%lld",&nt);
  for (i=0;i<nc;i++){
    scanf ("%lld",&C[i]);
  }
  for (i=0;i<nt;i++){
    scanf ("%lld %lld",&tirox,&tiroy);
    pontos = pontos + nc - bb(C,tirox,tiroy,nc);
  }
  printf ("%lld\n",pontos);
  return (0);
}
