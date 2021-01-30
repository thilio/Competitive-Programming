#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define kara cout << "karadola" << endl

typedef pair<int,int> pii;
typedef pair<long long int,long long int> pll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

int s,n,val[2200],peso[2200],memo[2200][2200];

int dp (int i, int s){
	if (s<0) return -INF;
	if (i==n) return (0);
	
	int &resp = memo[i][s];
	if (resp==-1){
		resp = max(val[i] + dp(i+1,s - peso[i]),dp(i+1,s));
	}
	return (resp);

}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);

    cin >> s >>n;
    ms(memo,-1);
    fr (i,n){
    	cin >> peso[i];
    	cin >> val[i];
    }
    cout << dp (0,s) << endl;
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<=s;j++){
            cout << memo[i][j];
        }
        cout << endl;
    }
    return (0);

}