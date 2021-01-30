#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,i,j,n,soma=0,v[100000];
  scanf("%d",&n);
  scanf("%d",&t);
  for (i=0;i<n;i++){
    scanf ("%d",&v[i]);
  }
  soma =0;
  j=0;
  i=0;
  while (j<n){
    soma = soma + v[j];
    if (soma > t){
      soma = soma - v[i];
      i++;
    }
    j++;
  }
  printf ("%d\n",j-i);
  return (0);
}
