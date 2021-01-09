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
	string s;
	getline(cin,s);

	s.pb('$');
	int n = s.size();
	vector<int> p(n), c(n);

	vector<pair<char,int>> a(n);
	fr(i,n) a[i] = {s[i],i};
	sort(all(a));

	fr(i,n) p[i] = a[i].snd;
	c[p[0]] = 0;

	frr(i,n-1){
		c[p[i]] = c[p[i - 1]];
		if(a[i].fst != a[i-1].fst) c[p[i]]++;
	}

	int k = 0;
	while((1 << k) < n){
		vector<pair<pii,int>> b(n);
		fr(i,n) b[i] = { {c[i], c[(i + (1 << k))%n]}, i};
		sort(all(b));

		fr(i,n) p[i] = b[i].snd;
		c[p[0]] = 0;

		frr(i,n - 1){
			c[p[i]] = c[p[i - 1]];
			if(b[i].fst != b[i-1].fst) c[p[i]]++;
		}
		k++;
	}

	fr(i,n){
		cout << p[i] << ' ';
	}
	gnl;


}
