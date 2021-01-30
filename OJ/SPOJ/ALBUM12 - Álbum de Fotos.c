#include<bits/stdc++.h>
int ma(int a ,int b){
  if (a>b)
    return (a);
  return (b);
}
int mi (int a,int b){
  return (a+b-ma(a,b));
}
int main(){
    int x,y,l1,l2,h1,h2,boo=1,aux;
    scanf ("%d",&x);
    scanf ("%d",&y);
    scanf ("%d",&l1);
    scanf ("%d",&h1);
    scanf ("%d",&l2);
    scanf ("%d",&h2);
    /*if ((l1>x && l1>y)||(l2>x && l2>y)||(h1>x && h1>y)||(h2>x && h2>y))
      boo=1;
    */
    if (l1 + l2 <= x && h1<=y && h2<=y)
      boo=0;
    if (h1 + h2 <=x && l1<=y && l2<=y)
      boo=0;
    if (l1 + h2 <=x && h1<=y && l2<=y)
      boo=0;
    if (h1 + l2<=x && h2<=y && l1<=y)
      boo=0;
    aux=x;
    x=y;
    y=aux;
    if (l1 + l2 <= x && h1<=y && h2<=y)
      boo=0;
    if (h1 + h2 <=x && l1<=y && l2<=y)
      boo=0;
    if (l1 + h2 <=x && h1<=y && l2<=y)
      boo=0;
    if (h1 + l2<=x && h2<=y && l1<=y)
      boo=0;
    if (boo==0){
      printf ("S\n");
    }
    else{
      printf ("N\n");
    }
    return(0);
}
