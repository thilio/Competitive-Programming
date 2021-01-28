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

int where[100100];
int v[100100];
int vic[100100];
int main(){

	fastio;
	int n;
	cin >> n;
	frr(i,n){
		cin >> v[i];
		where[v[i]] = i;
	}

	for(int i = n; i > 0; i--){
		int pos = where[i];

		int fr = pos + i;

		while(fr <= n){
			if(vic[fr] == 0 && v[fr] > i) vic[pos] = 1;
			fr += i;
		}

		int bac = pos - i;

		while(bac > 0){
			if(vic[bac] == 0 && v[bac] > i) vic[pos] = 1;
			bac -= i;
		}
	}

	frr(i,n){
		if(vic[i]) cout << 'A';
		else cout << 'B';
	}

	gnl;


}
