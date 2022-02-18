#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define endl '\n'
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

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
const int MAXN = 9400000; 

int en;

struct trie{
    int m[2];
    int id;
    trie(){
        id = m[0] = m[1] = -1;
    }
    
}t[MAXN];

int new_node(){  
    t[en].id = t[en].m[0] = t[en].m[1] = -1;
    return en++;
}

void init(){
    en = 0;
    new_node();
}

void add(int node, int num, int name,int i){ // Add string to trie
    if(i < 0){
        t[node].id = name;
        return;
    }
    int val = ((num&(1 << i)) ? 1 : 0);
    if(t[node].m[val] == -1){
        t[node].m[val] = new_node();
    }
    add(t[node].m[val], num, name, i - 1);
}

int n, k;

map<int, vector<array<int, 2>>> M;

array<int, 2> mx(int node, int num, int i){
    if(i < 0){
        return {0, t[node].id};
    }
    int val = ((num&(1 << i)) ? 1 : 0);
    if(t[node].m[1 - val] != -1){
        int ans = 1 << i;
        array<int, 2> foo = mx(t[node].m[1 - val], num, i - 1);
        return {foo[0] + ans, foo[1]};
    }
    else{
        return mx(t[node].m[val], num, i - 1);
    }

}

int main(){

    fastio;
    cin >> n >> k;

    if(k == 0){
        cout << n << endl;
        frr(i, n) cout << i << ' ';
        gnl;
        return 0;
    }

    int pot = 1;
    while(pot <= k) pot *= 2;
    pot /= 2;

    frr(i, n){
        int x;
        cin >> x;

        M[x/pot].pb({x, i});
    }

    vi ans;

    for(auto y: M){
        int x = y.fst;
        if(M.count(x^1) && ((x^1) < x)) continue;
        if(M.count(x^1)){
            init();
            for(auto l: y.snd) add(0, l[0], l[1], 29);
            bool ok = false;
            for(auto z: M[x^1]){
                array<int, 2> foo = mx(0, z[0], 29);
                if(foo[0] >= k){
                    ans.pb(z[1]);
                    ans.pb(foo[1]);
                    ok = true;
                    break;
                }
            }
            if(!ok) ans.pb(M[x^1][0][1]);
        }
        else{
            ans.pb(y.snd[0][1]);
        }
    }

    if(ans.size() <= 1){
        cout << -1 << endl;
    }
    else{
        cout << ans.size() << endl;
        for(auto x: ans)
            cout << x << ' ';
        gnl;
    }
}