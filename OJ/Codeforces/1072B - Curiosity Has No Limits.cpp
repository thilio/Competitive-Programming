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
	int n;
	cin >> n;
	int a[112345],b[112345];
	
	fr(i,n-1){
		cin >> a[i];
	}

	fr(i,n-1)
		cin >> b[i];

	int ans[112345];
	ms(ans,-1);

	bool ok;
	fr(i,4){
		ans[n-1] = i;
		ok =false;
		int j;
		for(j = n-2;j>=0;j--){
			fr(k,4){
				if (((k|ans[j+1]) == a[j]) && ((k&ans[j+1]) == b[j]))
					ans[j] = k;
			}
			//dbg(ans[j]);
			if(ans[j] == -1){
				ms(ans,-1);
				break;
			}

		}
		if(j==-1)
			ok = true;
		if(ok)
			break;
	}

	if(ok){
		cout <<"YES"<<endl;
		fr(i,n)
			cout <<ans[i]<<' ';
	}
	else
		cout <<"NO";
	gnl;




}
