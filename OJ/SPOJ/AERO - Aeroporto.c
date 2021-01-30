#include<bits/stdc++.h>
int maximo  (int v[],int n){
  int max,i;
  max=0;
  for(i=1;i<n+1;i++){
    if (v[i]>max)
      max=v[i];
  }
  return(max);
}
int main(){
  int a[200],V,i,A,aux,max,contaglob=1;
  scanf ("%d",&A);
  scanf("%d",&V);
  while(V!=0 || A!=0){
    for (i=0;i<A+1;i++){
      a[i]=0;
    }
    for (i=0;i<V;i++){
      scanf("%d",&aux);
      a[aux]=a[aux]+1;
      scanf("%d",&aux);
      a[aux]=a[aux]+1;
    }
    max=maximo (a,A);
    printf ("Teste %d\n",contaglob);
    contaglob++;
    for (i=1;i<A+1;i++){
      if (a[i]==max){
        printf ("%d ",i);
      }
    }
    printf ("\n\n");
    scanf ("%d",&A);
    scanf("%d",&V);
  }
  return(0);
}
