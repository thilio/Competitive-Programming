#include<stdio.h>
int main()
{
  int d,l,v1,v2;
  double res;
  scanf("%d",&d);
  scanf("%d",&l);
  scanf("%d",&v1);
  scanf("%d",&v2);
  res=(double)(l-d)/(v1+v2);
  printf("%10.8f\n",res);
  return 0;
}