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
int n,k;
double v[303000];
double temp[300300];
double mn[300300];

bool ok(double x){

	frr(i,n){
		temp[i] = temp[i-1] + v[i] - x;
	}
	//mn[0] = (double)INF;
	frr(i,n){
		mn[i] = min(mn[i-1],temp[i]);
	}

	frr(j,n){
		int i = j -k;
		if(i < 0) continue;
		if(temp[j] > mn[i]) return true;
	}

	return false;

}

int main(){

	fastio;
	cin >> n >> k;
	cout.precision(9);
	cout << fixed;
	frr(i,n) cin >> v[i];

	double l = 1.0;
	double r = 1000000.0;

	double best = 1.0;

	fr(i,50){
		double x = (l + r)/2;
		if(ok(x)){
			l = x;
			best = x;
		}
		else r = x;
	}

	cout << best << endl;

}
