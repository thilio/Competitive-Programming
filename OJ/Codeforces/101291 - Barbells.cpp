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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);    
 	int n,m;
 	int p[15];
 	cin >> m >> n;

 	fr(i,m){
 		cin >> p[i];
 	}

 	sort(p,p+m);

 	int v[15];
 	vii per;

 	fr(i,n){
 		cin >> v[i];
 	}

 	sort(v,v+n);

 	for (int i = 0;i < (1 << n);i++){
 		int sum = 0;
 		fr(j,n){
 			int x = 1 << j;
 			if ((x&i) != 0)
 				sum += v[j];
 		}
 		per.pb(mp(sum,i));
 	}

 	sort(per.begin(),per.end());

 	set<int> ans;

 	fr(i,per.size()){
 		for(int j = i; j < per.size() ; j++){
 			if(per[i].fst == per[j].fst){
 				int x = (per[i].snd&per[j].snd);
 				if (x == 0)
 					ans.insert(per[i].fst);
 			}
 			if(per[j].fst > per[i].fst) break;
 		}
 	}

 	set<int> f;
 

 	fr(i,m){
 		for(set<int>::iterator it=ans.begin(); it!=ans.end(); ++it){
 			if (f.find(p[i] + 2*(*it)) == f.end())
 				f.insert(p[i] + 2*(*it));
 		}
 	}

 
 	for(set<int>::iterator it=f.begin(); it!=f.end(); ++it)
 		cout << *it << endl;

 	return(0);
}
