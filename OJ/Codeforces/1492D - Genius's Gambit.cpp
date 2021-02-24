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

	int a,b,k;
	cin >> a >> b >> k;

	if(k == 0){
		cout << "Yes" << endl;
		fr(i,b) cout << 1;
		fr(i,a) cout << 0;
		gnl;
		fr(i,b) cout << 1;
		fr(i,a) cout << 0;
		gnl;
		return 0;
	}

	if(b == 1 || a == 0){
		cout << "No" << endl;
		return 0;
	}
	
	if(k >= a + b - 1) cout << "No" << endl;
	else{
		if(k <= b - 1){
			cout << "Yes" << endl;
			cout << 1;
			fr(i,a - 1) cout << 0;
			fr(i,k) cout << 1;
			cout << 0;
			fr(i,b - 1 - k) cout << 1;
			gnl;
			cout << 1;
			fr(i,a) cout << 0;
			fr(i, b - 1) cout << 1;
			gnl;
		}
		else{
			cout << "Yes" << endl;
			cout << 1;
			fr(i, a + b - k - 2) cout << 0;
			cout << 1;
			fr(i,k-b+1) cout << 0;
			fr(i,b - 2) cout << 1;
			cout << 0;
			gnl;
			cout << 1;
			fr(i,a) cout << 0;
			fr(i, b - 1) cout << 1;
			gnl;
		}
	}

}
