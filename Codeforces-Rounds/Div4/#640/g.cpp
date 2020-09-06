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

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		int k = n/4 - 1;

		if(k  < 0){
			cout << -1 << endl;
			continue;
		}

		fr(i,k){
			cout << 4*i + 2;
			cout << ' ';
			cout << 4*i + 4;
			cout << ' ';
			cout << 4*i + 1;
			cout << ' ';
			cout << 4*i + 3;
			cout << ' ';
		}

		int l = n - 4*k;

		if(l == 4){
			cout << 4*k + 2;
			cout << ' ';
			cout << 4*k + 4;
			cout << ' ';
			cout << 4*k + 1;
			cout << ' ';
			cout << 4*k + 3;
			cout << endl;
		}
		if(l == 5){
			cout << 4*k + 2;
			cout << ' ';
			cout << 4*k + 4;
			cout << ' ';
			cout << 4*k + 1;
			cout << ' ';
			cout << 4*k + 3;
			cout << ' ';
			cout << 4*k + 5;
			cout << endl;
		}
		if(l == 6){
			cout << 4*k + 2;
			cout << ' ';
			cout << 4*k + 6;
			cout << ' ';
			cout << 4*k + 4;
			cout << ' ';
			cout << 4*k + 1;
			cout << ' ';
			cout << 4*k + 3;
			cout << ' ';
			cout << 4*k + 5;
			cout << endl;
		}
		if(l == 7){
			cout << 4*k + 2;
			cout << ' ';
			cout << 4*k + 6;
			cout << ' ';
			cout << 4*k + 4;
			cout << ' ';
			cout << 4*k + 1;
			cout << ' ';
			cout << 4*k + 3;
			cout << ' ';
			cout << 4*k + 5;
			cout << ' ';
			cout << 4*k + 7;
			cout << endl;
		}
	}

}
