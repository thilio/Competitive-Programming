#define MAX 1000
#include<bits/stdc++.h>
using namespace std;
int main()
{ int n, l,lamp[MAX], i;
  double d, aux;
  scanf("%d", &n);
  scanf("%d", &l);
  for (i= 0; i< n; i++){
      scanf("%d", &lamp[i]);
  }
  sort(lamp, lamp + n);
  d = lamp[0];
  for(i = 0; i < (n-1); i++){
     aux = (lamp[i + 1] - lamp[i]);
	aux=aux/2;
     if(aux > d)
        d = aux;
  }
  if(d < l- lamp[n-1])
     d= l - lamp[n-1];
  printf("%.10f\n", d);
  return 0;
}
