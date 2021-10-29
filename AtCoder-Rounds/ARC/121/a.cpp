#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

vector<pair<int,int>> v;
vector<pii> points;
int n;

void find_ini(){
	int distx = max(abs(v[0].fst - v[n - 1].fst), abs(v[0].snd - v[n - 1].snd));
	pii ax = v[0];
	pii bx = v[n - 1];

	for(auto &x: v) swap(x.fst, x.snd);

	sort(all(v));


	int disty = max(abs(v[0].fst - v[n - 1].fst), abs(v[0].snd - v[n - 1].snd));
	pii ay = v[0];
	pii by = v[n - 1];

	for(auto &x: v) swap(x.fst, x.snd);

	swap(ay.fst, ay.snd);
	swap(by.fst, by.snd);

	sort(all(v));
	
	if(disty >= distx){
		points.pb(ay);
		points.pb(by);
	}
	if(distx >= disty){
		points.pb(ax);
		points.pb(bx);
	}
}


int find(vector<pii> &w){
	int distx = max(abs(w[0].fst - w[n - 2].fst), abs(w[0].snd - w[n - 2].snd));

	for(auto &x: w) swap(x.fst, x.snd);

	sort(all(w));

	int disty = max(abs(w[0].fst - w[n - 2].fst), abs(w[0].snd - w[n - 2].snd));

	
	return max(distx, disty);
}

int main(){

	fastio;
	cin >> n;

	fr(i, n){
		pii x;
		cin >> x.fst >> x.snd;
		v.pb(x);
	}

	sort(all(v));

	find_ini();

	//for(auto x: points) cout << x.fst << ' ' << x.snd << endl;


	int ans = 0; 
	for(auto x: points){
		vector<pii> nw;
		nw.clear();

		bool ja = false;
		for(auto y: v){
			if(y == x && !ja) ja = true;
			else nw.pb(y);
		}
		ans = max(ans, find(nw));
	}

	cout << ans << endl;
}
