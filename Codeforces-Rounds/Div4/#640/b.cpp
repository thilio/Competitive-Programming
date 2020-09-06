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
		int n,k;
		cin >> n >> k;


		if(n < k){
			cout << "NO\n";
			continue;
		}

		if(n%2 == 1){
			if(k%2 == 0){
				cout << "NO\n";
			}
			else{
				cout << "YES\n";
				fr(i,k-1) cout << '1' << ' ';
				cout << n -k + 1 << endl;
			}
		}
		else{
			if(k%2 == 0){
				cout << "YES\n";
				fr(i,k-1) cout << '1' << ' ';
				cout << n -k + 1 << endl;
			}
			else{
				if(n < 2*k) cout << "NO\n";
				else{
					cout << "YES\n";
					fr(i,k-1) cout << '2' << ' ';
					cout << n - 2*(k-1)<< endl;
				}
			}
		}
	}

}
