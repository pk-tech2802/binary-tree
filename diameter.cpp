#include <bits/stdc++.h>
using namespace std;
#define fo(i, s, e) for (int i = s; i < e; i++)
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
#define ff first
#define ss second
#define in insert
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define pb push_back
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;
ll mod = 1e10+19 ;
#define add(a,b) (((a%mod)+(b%mod))%mod)
#define mul(a,b) (((a%mod)*(b%mod))%mod)
#define sub(a,b) (((a%mod)-(b%mod)+mod)%mod)


struct node{
    node *left , *right ; 
    int val ; 
    node(int v){
        this->val = v ; 
        this->left = NULL ;
        this->right = NULL ;
    }
} ;


int height(node * root , int&diameter){
    if(!root){
        return 0;
    }
    int l = height(root->left,diameter);
    int r = height(root->right,diameter);
    diameter = max(diameter,l+r);
    return 1 + max(l,r);
}

int main()
{   
    node* root = new node(1) ;
    root->left = new node(2) ;
    root->right = new node(3) ;
    root->left->left = new node(4); 
    root->left->right = new node(5); 

    int diameter = 0 ;
    height(root,diameter);
    cout<<"diameter "<<diameter<<"\n";
    return 0;
}

// . . . .

