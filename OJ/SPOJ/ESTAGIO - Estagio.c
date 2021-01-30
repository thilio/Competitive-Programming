#include<stdio.h>
int main (){
  int codigo[2000],notas [2000],melhor,codigosm[2000],cont=0,n,i,j,contglob=1;
  scanf ("%d",&n);
  melhor=-1;
  while (n!=0){
    for(i=0;i<n;i++){
      scanf ("%d",&codigo[i]);
      scanf ("%d",&notas[i]);
    }
    for(i=0;i<n;i++){
      if (notas[i]==melhor){
        codigosm[cont]=codigo[i];
        cont++;
      }
      if (notas [i]>melhor){
        cont=0;
        codigosm[cont]=codigo[i];
        cont++;
        melhor= notas[i];
      }
    }
    printf ("Turma %d\n",contglob);
    contglob++;
    for (j=0;j<cont;j++){
      printf ("%d",codigosm[j]);
      if (j==cont-1)
        printf ("\n");
      if (j!=cont-1)
        printf (" ");
    }
    printf ("\n");
    scanf("%d",&n);
    melhor=-1;
  }
  return (0);
}
