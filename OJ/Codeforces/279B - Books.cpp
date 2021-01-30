#include<bits/stdc++.h>
using namespace std;
int v[100000];
int boo (int v[],int n,int t,int N){
  int soma=0,i,j;
  for(i=0;i<n;i++){
    soma = soma + v[i];
  }
  j=n;
  i=0;
  while (soma > t){
    if (j==N)
      return (0);
    soma = soma -v[i] + v[j];
    i++;j++;
  }
  return (1);
}
int bb(int v[],int n,int t){
  int i,ini,fim;
  ini=0;fim =n;
  while(fim>=ini){
    i= (ini + fim)/2;
    if (boo(v,i,t,n)==1 && boo(v,i+1,t,n)==0||boo(v,i,t,n)==1 &&i==n)
      return (i);
    if(boo(v,i,t,n)==1)
      ini=i+1;
    if (boo(v,i,t,n)==0)
      fim = i-1;
  }
  return (0);
}
int main(){
  int t,i,n;
  scanf("%d",&n);
  scanf("%d",&t);
  for (i=0;i<n;i++){
    scanf ("%d",&v[i]);
  }
  i=bb(v,n,t);
  printf ("%d\n",i);
  return(0);
}
