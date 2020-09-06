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
#define LAU cout << "LAW" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int inter(string s,int n){
	int res = 0;
	fr(i,n-1){
		bool ok = true;
		fr(j,i+1){			
			if (s[n-i+j-1] != s[j])
				ok = false;
		}
		if (ok)
			res = i+1;
	}
	return (res);
}

int main(){
	int n,k;
	int j;

	cin >> n;
	cin >> k;
	getchar();
	string s;
	getline (cin ,s);
	int x = inter (s,n);
	//dbg(x);
	fr(i,k){
		
		for (j=0;j<n -x;j++){
			cout << s[j];
		}
	}
	for (j=n-x;j<n;j++){
		cout << s[j];
	}
	gnl;

	return (0);

    
    

}