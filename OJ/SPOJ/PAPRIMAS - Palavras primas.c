#include<bits/stdc++.h>
int primo(int n){
  int i;
  if (n==1) return(0);
  i=2;
  while (i*i<=n){
    if(n%i==0)
      return (1);
    i++;
  }
  return(0);
}
int main (){
  int i,soma,aux,v[1000],cont=0;
  char s[1000];
  while(scanf("%s",s)!=EOF){
    soma=0;
    for(i=0;s[i]!='\0';i++){
      if (s[i]<='Z'){
        soma=soma + s[i] - 'A' + 27;
      }
      else{
        soma =soma + s[i] -'a' + 1;
      }
    }
    aux=primo(soma);
    v[cont]=aux;
    cont++;
  }
  for(i=0;i<cont;i++){
    if (v[i]==0){
      printf ("It is a prime word.\n");
    }
    else{
      printf ("It is not a prime word.\n");
    }
  }
  return(0);
}
