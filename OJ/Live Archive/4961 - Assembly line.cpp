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
int n;
map<char,int> m;
map<int,char> mr;
string s;
int custo[30][30];
int res[30][30];
vii mevira[30];
vi ans;
int nn;
int memo[300][300][30];

void pd(){

	fr(i,nn){
		fr(j,nn){
			frr(k,n){
				if(i > j)
					memo[i][j][k] = INF;
				if(i==j){
					if(ans[i] == k) memo[i][j][k] = 0;
					else memo[i][j][k] = INF;
				}
			}
		}
	}

	for(int i = 1;i<nn;i++){
		for(int d = 0; d< nn - i;d++){
			frr(quero,n){
				memo[d][d+i][quero]= INF;
				for(int k = d; k < d + i;k++){
					fr(ct,mevira[quero].size()){
						pii aux = mevira[quero][ct];
						memo[d][d+i][quero] = min(memo[d][d+i][quero],memo[d][k][aux.fst] + memo[k+1][d+i][aux.snd] + custo[aux.fst][aux.snd]);
					}

				}
				
			}
		}
	}

	

}

int main(){

	fastio;
	bool ok = true;
	while(cin >> n){
		if(n == 0) break;

		if(ok == false){
			gnl;
		}

		ok = false;

		ans.clear();

		fr(i,30) mevira[i].clear();

		getline(cin,s);
		frr(i,n){
			char c;
			cin >> c;
			m[c] = i;
			mr[i] = c;
		}
		getline(cin,s);

		int a;
		char c;

		frr(i,n){
			frr(j,n){
				cin >> a;
				custo[i][j] = a;
				cin >> c;
				cin >> c;
				res[i][j] = m[c];
			}
			getline(cin,s);
		}

		frr(i,n){
			frr(j,n){
				mevira[res[i][j]].pb(mp(i,j));
			}
		}

		int q;
		cin >> q;
		getline(cin,s);

		fr(i,q){
			ans.clear();
			getline(cin,s);

			fr(i,s.size())
				ans.pb(m[s[i]]);

			nn = ans.size();


			pd();
			pii pri = mp(INF,INF);

			int tam = s.size();

			frr(i,n){
				if(pri > mp(memo[0][tam-1][i],i))
					pri = mp(memo[0][tam-1][i],i);
				
			}

			cout << pri.fst << '-' << mr[pri.snd] << endl;
		}



	}

	
}
