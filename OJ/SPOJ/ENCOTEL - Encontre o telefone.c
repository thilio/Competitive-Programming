#include<bits/stdc++.h>
int main(){
  int i,cont=0;
  char s[1000],p[50];
  while(scanf("%s",s)!=EOF){
    for(i=0;s[i]!='\0';i++){
      cont++;
      if (s[i]>'Z'||s[i]<'A'){
        p[i]=s[i];
      }
      if (s[i]>='A'&&s[i]<='C'){
        p[i]='2';
      }
      if (s[i]>='D'&&s[i]<='F'){
        p[i]='3';
      }
      if (s[i]>='G'&&s[i]<='I'){
        p[i]='4';
      }
      if (s[i]>='J'&&s[i]<='L'){
        p[i]='5';
      }
      if (s[i]>='M'&&s[i]<='O'){
        p[i]='6';
      }
      if (s[i]>='P'&&s[i]<='S'){
        p[i]='7';
      }
      if (s[i]>='T'&&s[i]<='V'){
        p[i]='8';
      }
      if (s[i]>='W'&&s[i]<='Z'){
        p[i]='9';
      }
    }
    for(i=0;i<cont;i++){
      printf ("%c",p[i]);
    }
    printf ("\n");
    cont=0;
  }
  return(0);
}
