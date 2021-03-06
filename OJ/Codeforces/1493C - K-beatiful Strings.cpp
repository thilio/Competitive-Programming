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

int n,k;
int freq[30];
string s;
int falta[30];

void clear(){
	ms(freq, 0);
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		clear();
		cin >> n >> k;
		cin >> s;

		for(auto x: s){
			freq[x - 'a']++;
		}

		bool certa = true;

		fr(i, 26){
			if(freq[i]%k != 0) certa = false;
		}

		if(certa){
			cout << s << endl;
			continue;
		}

		bool deu = false;

		for(int i = s.size() - 1; i>= 0 && !deu; i--){
			freq[s[i] - 'a']--;
			int tenho = s.size() - i - 1;
			//dbg(tenho);
			for(char c = s[i] + 1; c <= 'z' && !deu; c++){
				freq[c - 'a']++;
				ms(falta, 0);
				int sum = 0;
				fr(j,26){
					falta[j] = k*((freq[j] + k - 1)/k) - freq[j];
					sum += falta[j];
				}

				if(tenho >= sum && (tenho - sum)%k == 0){
					for(int j = 0; j < i; j++) cout << s[j];
					cout << c;
					fr(j,tenho - sum) cout << 'a';
					fr(j,26){
						fr(jj, falta[j]) cout << (char) ('a' + j);
					}
					gnl;
					deu = true;
				}
				freq[c - 'a']--;
			}
		}
		if(!deu) cout << -1 << endl;
	}

}
