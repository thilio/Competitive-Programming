#include<stdio.h>
int main()
{
  int n,m;
  scanf("%d",&n);
  scanf("%d",&m);
  if(n%(m+1)==0){
    printf("Carlos");
  }
  else{
    printf("Paula");
  }
  return(0);
}
     