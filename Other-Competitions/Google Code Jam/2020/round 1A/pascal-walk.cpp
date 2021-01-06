//Only works for 2 test sets

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

int g = 1;

int main(){

	fastio;

	int T;
	cin >> T;

	while(T--){
		int n;
		cin >> n;
		cout << "Case #" << g++ << ":" << endl;

		cout << "1 1\n";

		if(n == 1){
			continue;
		}

		int k = 1;
		int sum = 1;
		while(sum + k <= n){
			cout << k + 1 << ' ' << k << endl;
			sum += k;
			k++;
		}


		if(sum == n) continue;

		else{
			cout << k << ' ' << k << endl;
			sum++;

			while(sum!=n){
				cout << k + 1 << ' ' << k + 1 << endl;
				k++;
				sum++;
			} 
		}


	}

}
