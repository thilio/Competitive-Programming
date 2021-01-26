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

int t[312345];
int v[312345];
int freq[312345];

int main(){

	fastio;

	int n;
	cin >> n;

	fr(i,n){
		cin >> v[i];
	}

	fr(i,n){
		cin >> t[i];
	}

	int i,j,ct;
	i = 0;
	j = 0;
	while(i<n){
		//dbg(freq[t[i]]);
		if(freq[t[i]] == 1){
			cout <<"0 ";
			i++;
			continue;
		}

		ct = 0;
		
		while(v[j] != t[i]){
			freq[v[j]] = 1;
			j++;
			ct++;
		}
		freq[v[j]] = 1;
		j++;
		
		cout << ct + 1<<' ';
		i++;
	}
	gnl;

}
