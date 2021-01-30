#include<bits/stdc++.h>
int maxi (int v[],int n){
  int max,i;
  max=v[0];
  for(i=0;i<n;i++){
    if (v[i]>max)
      max=v[i];
  }
  return (max);
}
int mini (int v[],int n){
  int max,i;
  max=v[0];
  for(i=0;i<n;i++){
    if (v[i]<max)
      max=v[i];
  }
  return (max);
}
int main(){
  int contaglob=1,x[20000],y[20000],u[20000],v[20000],n,i;
  scanf("%d",&n);
  while(n!=0){
    for(i=0;i<n;i++){
      scanf ("%d",&x[i]);
      scanf ("%d",&y[i]);
      scanf ("%d",&u[i]);
      scanf ("%d",&v[i]);
    }
    printf ("Teste %d\n",contaglob);
    contaglob++;
    if (maxi(x,n) < mini(u,n) && mini(y,n)>maxi(v,n)){
      printf ("%d %d %d %d\n",maxi(x,n),mini(y,n),mini(u,n),maxi(v,n));
    }
    else{
      printf ("nenhum\n");
    }
    printf ("\n");
    scanf("%d",&n);
  }
  return(0);
}
