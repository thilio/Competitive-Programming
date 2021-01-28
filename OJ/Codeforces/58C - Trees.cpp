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

int v[100100];
map<int,int> m;
int mx = 0;

int main(){

	fastio;
	int n;
	cin >> n;

	fr(i,n) cin >> v[i];

	fr(i,(n+1)/2){
		if(v[i] <= i) continue;
		//olar;
		m[v[0] + i - v[i]]++;
		if(m[v[0] + i - v[i]] > mx){
			mx = m[v[0] + i - v[i]];
		}

	}

	for(int i = n -1; i >= (n+1)/2;i--){

		int j = n -1 - i;

		if(v[i] <= j) continue;

		m[v[0] + j - v[i]]++;
		if(m[v[0] + j - v[i]] > mx){
			mx = m[v[0] + j - v[i]];
		}
	}

	cout << n - mx << endl;


}
