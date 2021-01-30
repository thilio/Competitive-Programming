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

int memo [4444];
int a,b,c,n;

int pd(int i){
	//cout << n << endl;
	if (i>n) return -INF;
	if (i==n) return 0;

	int &resp = memo[i];
	//cout << resp << endl;
	//kara;
	if (resp == -1){
		//kara;
		resp = max(1+pd(i+a),max(1+pd(i+b),1+pd(i+c)));
	}
	return (resp);

}

int main(){

	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);

	cin >> n >>a >> b >> c;
	ms(memo,-1);
	//cout << n << endl;
	cout << pd (0) <<endl;

}