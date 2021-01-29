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

ll a,b,t,ta,tb;
ll c;
vector<pll> v;
vector<ll> compre;

ll freq[300150];

map<ll,ll> m,mr;

int main(){

	fastio;

	cin >> a >> b >> t >> ta >> tb;
	cin >> c;

	fr(i,c){
		pll l;
		cin >> l.fst >> l.snd;
		v.pb(l);
		compre.pb(l.fst);
		compre.pb(l.snd);
	}

	sort(all(compre));

	ll ct = 1;
	fr(i,compre.size()){
		ll x = compre[i];
		if(m[x] == 0){
			m[x] = ct++;
			mr[ct - 1] = x;
		}
	}

	fr(i,c){
		v[i].fst = m[v[i].fst];
		v[i].snd = m[v[i].snd];
	}

	sort(all(v));

	int prev = 300100;

	ll ans = 0;
	ll best = 0;

	fr(i,c){
		pii tent;
		ll at = mr[v[i].fst]; 
		ll preco = 0;
		if(at > a) preco += (at - a)*ta;

		if(preco > t) continue;
		tent.fst = at;
		tent.snd = b + (t - preco)/tb;

		//dbg(tent.fst);
		//dbg(tent.snd);

		if(m[tent.snd] == 0){
			auto it = lower_bound(all(compre),tent.snd);
			if(it == compre.begin()){
				tent.snd = 0;
			}
			else{
				it--;
				tent.snd = *(it);
			}

		}
		

		tent.fst = m[tent.fst];
		tent.snd = m[tent.snd];

		if((v[i].snd) <= tent.snd){
			freq[v[i].snd]++;
			ans++;
		}

		for(int j = tent.snd + 1; j <= prev;j++){
			ans-=freq[j];
		}

		prev = tent.snd;

		best = max(best,ans);

	}

	cout << best << endl;



}
