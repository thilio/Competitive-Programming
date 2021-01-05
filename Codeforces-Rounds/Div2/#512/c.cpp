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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
int n,v[1000];


int da(int val){
	int i = 0;
	int sum = 0;
	while(i<n){
		sum += v[i];
		i++;
		if(sum > val) return (0);
		if (sum == val) sum = 0;
	}

	return(1);

}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    
 	

 	cin >> n;
 	string s;

 	getline(cin,s);
 	getline(cin,s);
 	
 	fr(i,n)
 		v[i] = s[i] - '0';

 	int sum = 0;

 	fr(i,n)
 		sum += v[i];

 	int ans = 0;
 	//dbg(sum);

 	for (int i = 2; i<= n;i++){
 		if (sum%i == 0){
 			ans = da(sum/i);
 			//cout << i <<' ' << ans<<endl;
 		}
 		if (ans) break;
 	}

 	if(ans) cout << "YES";
 	else cout << "NO";
 	gnl;

}