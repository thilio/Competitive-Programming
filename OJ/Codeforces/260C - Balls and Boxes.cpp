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

int main(){

	fastio;

	int n,x;
	cin >> n >> x;

	ll v[100100];
	ll mn = llINF;
	int mni = -1;
	frr(i,n){
		cin >> v[i];
		mn = min(mn,v[i]);
	}

	if(v[x] == mn){
		mni = x;
	}
	else{
		int j = x-1;
		if(j == 0) j = n;

		while(j != x){
			if(v[j] == mn){
				mni = j;
				break;
			}
			j--;
			if(j == 0) j = n;
		}
	}

	ll sum = 0ll;
	sum += mn*n;

	frr(i,n) v[i] = v[i] - mn;

	int j = x;
	while(j != mni){
		v[j]--;
		sum++;

		j--;
		if(j == 0) j = n;
	}

	v[mni] = sum;

	frr(i,n) cout << v[i] << ' ';

	gnl;



}
