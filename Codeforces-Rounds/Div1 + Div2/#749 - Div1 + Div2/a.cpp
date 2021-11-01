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

int n, sum;
int odd;

bool prime(ll sum){
	if(sum == 1) return 0;
	if(sum == 2) return 1;

	for(ll i = 2; i*i <= sum; i++){
		if(sum % i == 0) return false;
	}

	return true;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		sum = odd = 0;

		frr(i, n){
			int x;
			cin >> x;
			sum += x;
			if(x%2 == 1) odd = i;
		}

		if(!prime(sum)){
			cout << n << endl;
			frr(i, n) cout << i << ' ';
			gnl;
		}
		else{
			cout << n - 1 << endl;

			frr(i, n) if(i != odd) cout << i << ' ';
			gnl;
		}
	}

}
