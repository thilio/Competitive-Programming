#include<stdio.h>
int main(){
  int i,n,voo=0, v[26];
  char c;
  scanf ("%d",&n);
  for (i=0;i<26;i++){
    v[i]=0;
  }
  for(i=0;i<n;i++){
    scanf ("%c",&c);
    if (c<'A'||c>'z'){
      i--;
    }
    else{
      if (c<='Z'){
        v[c-'A']=1;
      }
      else{
        v[c-'a']=1;
      }
    }
  }
  for (i=0;i<26;i++){
    if (v[i]==0){
      voo=1;
    }
  }
  if (voo==1){
    printf ("NO");
  }
  else{
    printf ("YES");
  }
  return(0);
}
