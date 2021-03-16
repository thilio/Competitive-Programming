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

int n;
map<ll, int> comp;
ll julia;

ll lg[100100];

int main(){

	fastio;

	cin >> n;
	cin >> julia;

	fr(i,n - 1){
		ll x;
		cin >> x;
		comp[x]++;
	}

	for(int i = 2; i <= n; i++) lg[i] = 1 + lg[i/2];	

	priority_queue<pll> pq;
	
	for(auto x: comp){
		pq.push(mp(x.fst, x.snd));
	}

	ll ans = 0;

	while(pq.size() > 1){
		pll fir = pq.top();
		pq.pop();
		pll run = pq.top();
		pq.pop();

		//dbg(fir.snd);

		run.fst += ans;

		ll d = fir.fst - run.fst;
		ll l = lg[fir.snd];

		if(fir.fst > julia - d*l){
			pq.push(fir);
			break;
		}

		ans += d*(l + 1);

		pll new_par;
		new_par.fst = fir.fst + d*l;
		new_par.snd = fir.snd + run.snd;
		pq.push(new_par);
	}

	//olar;

	pll imp = pq.top();

	ll d = julia - imp.fst;

	//dbg(imp.snd);

	if(imp.snd == 1){
		cout << julia - imp.fst + ans << endl;
		return 0;
	}

	while(d >= lg[imp.snd]){
		ll vezes = d/(lg[imp.snd]);
		imp.fst += vezes*lg[imp.snd];
		d = julia - imp.fst; 
		ans += vezes*(lg[imp.snd] + 1);
	}

	cout << julia - imp.fst + ans<< endl;
}
