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

map< pair<pll, pll>, vector<pair<ll, pll>> > M;

vector<ll> x;
vector<ll> y;
vector<ll> weight;

int n;

pll simp(pll x){

	ll g = __gcd(x.fst, x.snd);
	x = {x.fst/g, x.snd/g};
	if(x.snd < 0){
		x.fst *= -1;
		x.snd *= -1;
	}
	return x;
}

void build(int i, int j){
	pll angular, linear;

	if(x[i] == x[j]){
		angular = {0, 1};
		linear = {y[i] + y[j], 2};
		linear = simp(linear);
	}
	else if(y[i] == y[j]){
		angular = {1, 0};
		linear = {x[i] + x[j], 2};
		linear = simp(linear);
	}
	else{
		angular = {(y[i] - y[j]), (x[i] - x[j])};
		angular = {angular.snd, angular.fst};
		angular.fst *= -1;
		angular = simp(angular);

		linear = {(y[i] + y[j])*angular.snd - (x[i] + x[j])*angular.fst, 2*angular.snd};
		linear = simp(linear);
	}

	pll mid = {x[i] + x[j], y[i] + y[j]};

	ll W = weight[i] + weight[j];

	//dbg(W);

	M[{angular, linear}].pb({W, mid});
}

int main(){

	fastio;

	cin >> n;
	x.resize(n); weight.resize(n); y.resize(n);
	fr(i, n){
		cin >> x[i] >> y[i];
		cin >> weight[i];
	}

	fr(i, n){
		for(int j = i + 1; j < n; j++){
			build(i, j);
		}
	}

	for(auto &x : M) sort(all(x.snd));
	for(auto &x : M) reverse(all(x.snd));

	ll best = -1;

	for(auto &x: M){
		for(auto &y : x.snd){
			if(y.snd != x.snd[0].snd){
				best = max(best, y.fst + x.snd[0].fst);
			}
		}
	}

	cout << best << endl;
}
