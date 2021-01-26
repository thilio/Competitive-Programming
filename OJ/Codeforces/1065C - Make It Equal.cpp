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

int freq[222345];

int main(){

	fastio;
	int n,k;
	cin >> n >> k;

	int v[222345];
	fr(i,n){
		cin >> v[i];
	}

	int mn = INF;
	int mx = -1;

	fr(i,n){
		if (mn > v[i])
			mn = v[i];
		if(mx < v[i])
			mx = v[i];
	}

	fr(i,n){
		v[i] -= mn;
		freq[v[i]]++;
	}

	pii a = {0,0};

	int ans = 0;
	int aux1,aux2;

	for(int i = mx;i>0;i--){
		//dbg(a.fst);
		//dbg(a.snd);
		//dbg(i);
		if(a.fst + a.snd + freq[i] <= k){
			aux1 = a.fst + a.snd + freq[i];
			a.snd += freq[i];
			a.fst = aux1;	
		}
		else{
			ans++;
			freq[i] += a.snd;
			a.fst = 0;
			a.snd = 0;
			i++;
		}
	}

	if(a.fst + a.snd > 0) ans++;

	cout << ans << endl;
}
