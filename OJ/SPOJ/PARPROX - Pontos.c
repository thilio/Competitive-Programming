#include<bits/stdc++.h>
double caldis(int x1,int y1,int x2, int y2){
  double dx,dy;
  dx=pow(x1-x2,2);
  dy=pow(y1-y2,2);
  return (dx + dy);
}
int main(){
  int x[1000],y[1000],n,i,j;
  double aux,max;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf ("%d",&x[i]);
    scanf ("%d",&y[i]);
  }
  if (n<2){
    printf ("-1.000\n");
  }
  else{
    max=caldis(x[0],y[0],x[1],y[1]);
    for(i=0;i<n;i++){
      for (j=i+1;j<n;j++){
        /*aux=caldis(x[i],y[i],x[j],y[j]);*/
        aux=hypot(x[i]-x[j],y[i]-y[j]);
        if (aux<=max)
          max=aux;
      }
    }
    printf ("%.3f\n\n",max);
  }
  return(0);
}
