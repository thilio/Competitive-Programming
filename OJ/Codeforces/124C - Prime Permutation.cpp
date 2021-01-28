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

map<char,int> m;
int igual[10000];

bool primo(int n){
	if(n == 1) return false;

	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}

	return true;
}

int main(){

	fastio;

	string s;
	getline(cin,s);

	int n = s.size();
	int mx = 0;

	char cool;

	fr(i,n){
		m[s[i]]++;
		if(m[s[i]] > mx){
			mx = m[s[i]];
			cool = s[i];
		}
	}

	int ig = 0;

	for(int i =2; i <= n; i++){
		bool x = primo(i);

		if(i > (n/2) && x) igual[i] = 0;
		else{
			igual[i] = 1;
			ig++;
		}
	}

	if(ig > mx) cout << "NO";
	else cout << "YES";

	gnl;
	if(ig > mx) return 0;

	char ans[1010];

	frr(i,1008) ans[i] = ')';

	frr(i,n){
		if(igual[i]){
			ans[i] = cool;
			m[cool]--;
		}
	}
	

	frr(i,n){
		if(ans[i] == ')'){
			for(char a = 'a'; a <= 'z';a++){
				if(m[a] > 0){
					ans[i] = a;
					m[a]--;
					break;
				}
			}
		}
	}

	frr(i,n) cout << ans[i];
	gnl;








}
