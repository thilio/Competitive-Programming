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
int pri[10000],ult[10000];

bool checkpos(string mx,string s){
	int i = 1;
	if(s.size() == 0) return true;
	while(i <= s.size()){
		if(mx[mx.size() - i] != s[s.size() - i]) return false;
		i++;
	}

	return true;
}

bool checkpre(string mx,string s){
	int i = 0;
	if(s.size()== 0) return true;
	while(i < s.size()){
		if(mx[i] != s[i]) return false;
		i++;
	}

	return true;
}

int main(){

	fastio;

	int T;
	cin >> T;

	while(T--){
		int n;
		cin >> n;
		cout << "Case #" << g++ << ":" << ' ';

		string ss;
		getline(cin,ss);

		string s[55];

		fr(i,n) cin >> s[i];

		string pre[55],pos[55];

		fr(i,n){
			bool foi = false;
			fr(j,s[i].size()){
				if(s[i][j] == '*' && !foi){
					pri[i] = j;
					foi = true;
				}

				if(s[i][j] == '*') ult[i] = j;
			}

		}
		

		fr(i,n){
			string k,l;
			int change = 0;
			fr(j,s[i].size()){
				if(j == pri[i]){
					change = 1;
					if(pri[i] == ult[i]) change = 2;
					continue;
				}

				if(j == ult[i]){
					change = 2;
					continue;
				}

				if(change == 0) k.pb(s[i][j]);
				if(change == 2) l.pb(s[i][j]);
			}

			pre[i] = k;
			pos[i] = l;
		}

		

		

		string mxpre = pre[0];
		string mxpos = pos[0];
		fr(i,n){
			if(pre[i].size() > mxpre.size()) mxpre = pre[i];
			if(pos[i].size() > mxpos.size()) mxpos = pos[i];
		}

		bool ok = true;

		fr(i,n){
			if(!checkpos(mxpos,pos[i])) ok = false;
			if(!checkpre(mxpre,pre[i])) ok = false;
		}

		

		if(ok){
			cout << mxpre;
			fr(i,n){
				for(int j = pri[i]; j < ult[i];j++){
					if(s[i][j] != '*') cout << s[i][j];
				}
			}
			cout << mxpos << endl;

		}

		else cout << "*\n";

	}

}
