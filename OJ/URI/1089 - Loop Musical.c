#include<stdio.h>
int main(){
  int i,n,v[10000],cont=0;
  scanf ("%d",&n);
  while(n!=0){
    for(i=0;i<n;i++){
      scanf ("%d",&v[i]);
    }
    for(i=0;i<n;i++){
      if(v[i]>v[((i+1)%n)]&&v[i]>v[(i-1+n)%n]){
        cont++;
      }
      if((v[i]<v[((i+1)%n)]) && (v[i]<v[(i-1+n)%n])){
        cont++;
      }
    }
    printf ("%d\n",cont);
    cont=0;
    scanf("%d",&n);
  }
  return(0);
}
