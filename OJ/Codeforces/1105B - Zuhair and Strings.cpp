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

int main(){

	fastio;
	int n,k;
	cin >> n >> k;
	string s;
	getline(cin,s);
	getline(cin,s);

	map<char,int> m;

	if(k == 1){
		fr(i,n) m[s[i]]++;

		int mx = -1;

		for(char a ='a' ;a <= 'z';a++){
			mx = max(mx,m[a]);
		}

		cout << mx << endl;
	}
	else{
		int aux = 1;
		fr(i,n-1){
			if(s[i] == s[i+1]){
				aux++;
				if(aux == k){
					m[s[i]]++;
					aux = 1;
					i++;
				}
			}
			else aux = 1;
		}

		int mx = -1;

		for(char a ='a' ;a <= 'z';a++){
			mx = max(mx,m[a]);
		}

		cout << mx << endl;


	}

}
