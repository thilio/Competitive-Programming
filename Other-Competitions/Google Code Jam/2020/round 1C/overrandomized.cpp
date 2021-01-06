//Only works for 1 test set

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

vector<pair<int,string>> q;

int main(){

	fastio;

	

	int T;
	cin >> T;
	int g = 1;
	while(T--){
		int m;
		int u;
		cin >> u;
		string t;
		string s;

		
		set<char> S;
		S.clear();
		set<char> Q;
		Q.clear();
		vector<char> let;
		map<char,int> M;

		
		fr(i,10000){
			cin >> m;
			t.clear();
			s.clear();
			getline(cin,t);
			fr(i,t.size()){
				if(t[i] >= 'A' && t[i] <= 'Z'){
					if(s.size() == 0) Q.insert(t[i]);
					s.pb(t[i]);
					if(S.find(t[i]) == S.end()){
						S.insert(t[i]);
						let.pb(t[i]);
						M[t[i]] = let.size() - 1;
					}
				}
			}

			q.pb(mp(m,s));

		}

		vector<char> perm;
		for(char c  = '0' ; c <= '9';c++) perm.pb(c);

		bool ok = true;

		while(ok){

			bool f = false;
			fr(i,10){
				if(perm[i] == '0'){
					if(Q.find(let[i]) != Q.end()){
						ok = next_permutation(all(perm));
						f =true;
						break;
					}
				}
			}

			if(!f){

			bool tent = true;
			fr(i,q.size()){
				string k;
				fr(j,q[i].snd.size()){
					k.pb(perm[M[q[i].snd[j]]]);
				}
				if(stoi(k) > q[i].fst){
					tent = false;
					break;
				}
			}
			if(tent) break;
			ok = next_permutation(all(perm));
			}
		}

		char ans[10];


		fr(j,10){
			fr(i,10){
				if(perm[i] == '0' + j){
					ans[j] = let[i];
				}
			}
		}





		cout << "Case #" << g++ << ": ";
		//cout << c0;
		fr(i,10) cout << ans[i];
		gnl;
		//gnl;
			
		
	}

}
