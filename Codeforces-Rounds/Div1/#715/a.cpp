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
bool ok;
string s[3];

int freq[3][2];


void solve(int i, int j, bool flip){
	//dbg(i);
	//dbg(j);
	ok = true;
	if(flip){
		fr(k, 2*n){
			s[i][k] = '1' + '0' - s[i][k];
			s[j][k] = '1' + '0' - s[j][k];
		}
		swap(freq[i][0], freq[i][1]);
		swap(freq[j][0], freq[j][1]);
	}

	int p = 0;
	int q = 0;
	string t;

	while(p < 2*n && q < 2*n){
		if(s[i][p] == s[j][q]){
			if(s[i][p] == '1'){
				t.pb('1');
				p++;
				q++;
			}
			else{
				t.pb('0');
				p++;
				q++;
				
			}
		}
		else if(s[i][p] == '0'){
			t.pb('0');
			p++;
		}
		else{
			t.pb('0');
			q++;
		}
	}
	while(p < 2*n){
		t.pb(s[i][p]);
		p++;
	}
	while(q < 2*n){
		t.pb(s[j][q]);
		q++;
	}

	if(flip){
		fr(i, t.size()) t[i] = '1' + '0' - t[i];
		fr(k, 2*n){
			s[i][k] = '1' + '0' - s[i][k];
			s[j][k] = '1' + '0' - s[j][k];
		}
		swap(freq[i][0], freq[i][1]);
		swap(freq[j][0], freq[j][1]);
	}

	cout << t << endl;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		cin >> s[0] >> s[1] >> s[2];

		ms(freq, 0);

		fr(i, 3){
			for(auto x: s[i]) freq[i][x - '0']++;
		}

		ok = false;

		fr(i, 3){
			fr(j, 3){
				if(i == j || ok) continue;
				if(freq[i][1] >= n && freq[j][1] >= n) solve(i, j, false);
				else if(freq[i][0] >= n && freq[j][0] >= n) solve(i, j, true);
			}
		}
	}

}
