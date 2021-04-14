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
#define endl '\n'

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
		string s;
		cin >> n; 
		cin >> s;
		int one, zero;
		one = zero = 0;

		for(auto x: s){
			if(x == '0') zero++;
			if(x == '1') one++;
		}

		if(one%2 || zero%2){
			cout << "NO" << endl;
			continue;
		}
		if(s[0] == '0' || s[n - 1] == '0'){
			cout << "NO" << endl;
			continue;
		}

		string t1, t2;

		int ct1, ct0;
		ct1 = ct0 = 0;

		for(auto x: s){
			if(x == '0'){
				ct0++;
				if(ct0%2){
					t1.pb('(');
					t2.pb(')');
				}
				else{
					t1.pb(')');
					t2.pb('(');
				}
			}
			if(x == '1'){
				ct1++;
				if(ct1 <= one/2){
					t1.pb('(');
					t2.pb('(');
				}
				else{
					t1.pb(')');
					t2.pb(')');
				}
			}
		}

		cout << "YES" << endl;
		cout << t1 << endl << t2 << endl;

	}

}
