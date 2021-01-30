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

int memo[2020][2020],mat[2020][2020];
string s;
int t=1 ,n;

int pd1 (int i,int j);

int pd2 (int i,int j){

    if(i>=n && j<n) return INF;
    if (i>=n && j==n) return (0);
    
    int &pdm = memo[i][j];
    
    if (pdm!=-1) return (pdm);
    
    if (pd1(j,i))    pdm = min (1+pd2(i+1,i+1),pd2(i+1,j));
    else             pdm = pd2 (i+1,j);

    return pdm;
}

int pd1 (int i, int j){
    
    if (i>=n || j>=n||i<0||j<0) return 0;
    
    int &pdm=mat[i][j];
    
    if (i==j)                   return pdm=1;
    if(j==i+1 && s[i]==s[j])    return pdm=1;
    
    if(pdm!=-1) return pdm;

    if(s[i]==s[j] && pd1(i+1,j-1) )  return pdm=1;
    else                             return pdm=0;
}

int main(){
    cin >> n;
    while (n!=0){
        getchar();
        getline (cin,s);
        ms(mat,-1);
        ms(memo,-1);
        cout << "Teste "<< t <<endl;
        t++;
        cout <<pd2(0,0)<<endl;
        gnl;
        cin >> n;
    }

	return (0);	
}
