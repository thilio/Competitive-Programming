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
	int n,m;
	int v[300100],t[300100];

	cin>> n;
	fr(i,n) cin >> v[i];
	cin >> m;
	fr(i,m) cin >> t[i];

	int p,q;
	p = q = 0;

	ll sum = 0;
	fr(i,n) sum += v[i];
	fr(i,m) sum -= t[i];

	if(sum != 0){
		cout << -1 << endl;
		return 0;
	}

	ll suma,sumb;
	suma = 0;
	sumb = 0;
	ll res = 0;

	while(p < n && q < m){

		if(suma == sumb && suma != 0){
			res++;
			suma = sumb = 0;
			continue; 
		}

		if(suma > sumb){
			sumb += t[q];
			q++;
		}
		else{
			suma += v[p];
			p++;
		}

	}

	res++;

	cout << res << endl;


}
