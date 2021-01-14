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
int v[100];
int maxi(){
	int i = 0;
	int mx = -1;
	fr(j,26){
		if(v[j] > mx){
			mx = v[j];
			i = j;
		}
	}
	if (mx == 0) return (-1);
	return (i);

}
int main(){

	fastio;
	string s;
	int n;

	cin >> n;
	getline(cin,s);
	getline(cin,s);

	fr(i,n){
		v[s[i] - 'a']++;
	}

	fr(i,26){
		while(v[i]!=0){
			cout <<(char)('a' + i);
			v[i]--;
		}
	}

	gnl;


}
