#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int freq[212345];
int prox[212345];
int iso[212345];

int main(){
 	int n,m;

 	cin >> n >> m;

 	pii v[212345];


 	fr(i,n+m){
 		cin >> v[i].fst;
 	}

 	fr(i,n+m){
 		cin >> v[i].snd;
 	}
 	int aux = 0;
 	int p = n + m;
 		
 	aux = m-1;
 	for(int i = n+m-1;i>=0;i--){
 		if(v[i].snd == 1){
 			prox[i] = p;
 			p = i;
 			iso[i] = aux;
 			aux--;

 		}
 	}

 	int ant = -1;
 	p = -1;

 	fr(i,n+m){
 		
 		if(v[i].snd == 0){
 			if(ant == -1 && p ==-1){
 				freq[0]++;
 				continue;
 			}
 			
 			if(p== n + m){
 				freq[iso[ant]]++;
 				continue;
 			}

 			int pos = v[i].fst;

 			if(pos - v[ant].fst <= v[p].fst - pos){
 				freq[iso[ant]]++;
 				continue;
 			}

 			else
 				freq[iso[p]]++;

 		}

 		if(v[i].snd == 1){
 			ant = i;
 			p = prox[i];
 		}

 	}

 	fr(i,m){
 		cout << freq[i] << ' ';
 	}
 	gnl;






}
