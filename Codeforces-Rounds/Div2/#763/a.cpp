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

int main(){

	fastio;

	int n, m, rr, cr, rd, cd;

	int T;
	cin >> T;
	while(T--){
		cin >> n >> m >> rr >> cr >> rd >> cd;

		int opt_1;

		if(rr <= rd){
			opt_1 = rd - rr;
		}
		else{
			opt_1 = n - rr + (n - rd); 
		}

		int opt_2;

		if(cr <= cd){
			opt_2 = cd - cr;
		}
		else{
			opt_2 = m - cr + m - cd;
		}

		cout << min(opt_1, opt_2) << endl;
	}

}
