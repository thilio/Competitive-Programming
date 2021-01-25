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

string s;
bool shr[100100];
bool shl[100100];
bool lgl[100100];
bool lgr[100100];
int main(){

	fastio;
	int T;
	cin >> T;
	getline(cin,s);

	while(T--){
		getline(cin,s);
		int n = s.size();
		reverse(all(s));

		fr(i,n){
			shr[i] = lgr[i] = lgl[i] = shl[i] = false; 
		}

		for(int i = 0; i < n - 1; i++){
			if(s[i] == s[i + 1]){
				shr[i] =  true;
				shl[i + 1] = true;
			}
		}
		for(int i =0 ; i < n - 2; i++){
			if(s[i] == s[i + 2]){
				lgr[i] = true;
				lgl[i + 2] = true;
			}
		}

		int ans = 0;

		fr(i,n){
			if(shl[i] || lgl[i]){
				ans++;
				shl[i + 1] = false;
				lgl[i + 2] = false;
			}
		}

		cout << ans << endl;

	}

}
