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

int p[600];
int n;

void print(int l, int r){
	if(l == 0){
		frr(i, n) cout << p[i] << ' ';
	}
	else{
		for(int i = 1; i < l; i++){
			cout << p[i] << ' ';
		}
		for(int i = r; i >= l; i--){
			cout << p[i] << ' ';
		}
		for(int i = r + 1; i <= n; i++){
			cout << p[i] << ' ';
		}
	}
	gnl;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		
		cin >> n;

		frr(i, n) cin >> p[i];

		int fi = -1;

		frr(i, n){
			if(fi == -1 && p[i] != i) fi = i;
		}

		if(fi == -1){
			print(0, 0);
			continue;
		}

		for(int i = fi; i <= n; i++){
			if(p[i] == fi){
				print(fi, i);
			}
		}
	}

}
