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
int q[100100];

int query(int p){
	if(p == 0) return INF;
	if(p > n) return INF;
	if(q[p] != 0) return q[p];
	cout << '?' << ' ' << p << endl;
	cin >> q[p];
	return q[p];
}

int solve(int m){
	int mid = query(m);
	int left = query(m - 1);

	if(left < mid) return 2;

	int right = query(m + 1);
	if (right > mid) return 1;

	return 3;
}

void ans(int x){
	cout << '!' << ' ' << x << endl;
}

int main(){

	fastio;

	
	cin >> n;

	int l = 1;
	int r = n;

	while(l <= r){
		int m = (l + r)/2;

		int x = solve(m);
		if(x == 1){
			ans(m);
			break;
		}	
		if(x == 2){
			r = m - 1;
		}
		if(x == 3){
			l = m + 1;
		}
	}

}
