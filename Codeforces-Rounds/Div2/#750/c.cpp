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

int n;
string s;


int f(char c){
	int p = 0;
	int q = n - 1;
	int ct = 0;

	while(p < q){
		if(s[p] != s[q]){
			if(s[p] == c){
				ct++;
				p++;
			}
			else if(s[q] == c){
				ct++;
				q--;
			}
			else return INF;
		}
		else{
			p++; q--;
		}
	}
	return ct;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		cin >> s;

		int ans = INF;

		for(char i = 'a'; i <= 'z'; i++){
			ans = min(ans, f(i));
		}

		if(ans == INF) ans = -1;
		cout << ans << endl;
	}

}
