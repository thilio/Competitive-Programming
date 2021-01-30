#include<bits/stdc++.h>
using namespace std;
#define MAX 2500
int bb2(int v[], int x,int n){
  int i,f,m,best=-1;
  i=0;f=n-1;
  while (f>=i){
    m=(i+f)/2;
    if (v[m]==x){
      best=m;
      i=m+1;
    }
    if (v[m]<x)
      i=m+1;
    if (v[m]>x)
      f=m-1;
  }
  return (best);
}
int bb1(int v[], int x,int n){
  int i,f,m,best=-1;
  i=0;f=n-1;
  while (f>=i){
    m=(i+f)/2;
    if (v[m]==x){
      best=m;
      f=m-1;
    }
    if (v[m]<x)
      i=m+1;
    if (v[m]>x)
      f=m-1;
  }
  return (best);
}
void soma (int v[],int vl[], int r[],int n){
  int i,j,cont=0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      r[cont]=v[i] + vl[j];
      cont++;
    }
  }
}
int main (){
  int A[MAX],B[MAX],C[MAX],D[MAX],*E,*F,n,i,cont=0;
  scanf ("%d",&n);
  E = (int*)malloc(n*n*sizeof(int));
  F = (int*)malloc(n*n*sizeof(int));
  for (i=0;i<n;i++){
    scanf ("%d",&A[i]);
    scanf ("%d",&B[i]);
    scanf ("%d",&C[i]);
    scanf ("%d",&D[i]);
  }
  soma (A,B,F,n);
  soma (C,D,E,n);
  sort (F,F+n*n);
  for (i=0;i<n*n;i++){
    if (bb1(F,-E[i],n*n)!=-1)
      cont=cont + bb2(F,-E[i],n*n)-bb1(F,-E[i],n*n)+1;
  }
  printf ("%d\n",cont);
  return (0);
}
