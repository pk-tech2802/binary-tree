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

vi inorder(node *root){
    stack<node*>stk ; 
    // stk.push(root) ;
    vi inorder ; 

    while(1){
        if(root!=NULL){
            stk.push(root);
            root = root->left ;
        }
        else{
            if(stk.empty()){
                break;
            }
            root = stk.top() ;
            stk.pop() ;
            inorder.pb(root->val);
            root = root->right ;
        }
    }

    return inorder ; 
}

vi preorder(node* root){
    stack<node*>stk ;
    vi pre ; 
    while(1){
        if(root){
            stk.push(root) ; 
            pre.pb(root->val) ;
            root = root->left;
        }
        else{
            if(stk.empty())break;
            root = stk.top() ;
            stk.pop() ;
            root = root->right;
        }
    }

    return pre ;
}

void printStack(stack<node*>stk, stack<int>cnt){
    cout<<"stk ->\n";
    while(stk.size()){
        cout<<stk.top()->val<<" ->";
        stk.pop(); 
    }
    cout<<"\n";

    cout<<"cnt ->\n";
    while(cnt.size()){
        cout<<cnt.top()<<" ->";
        cnt.pop(); 
    }
    cout<<"\n\n";
}
vi postorder(node* root){
    stack<node*>stk ;
    stack<int>cnt ; 
    vi post ; 
    while(1){
        // printStack(stk,cnt);
        if(root){
            stk.push(root) ; 
            cnt.push(1) ;
            // cout<<"pushed "<<stk.top()->val<<"\n";
            root = root->left;
        }
        else{
            root = stk.top() ;
            if(cnt.top()==2){

                while(cnt.size() && cnt.top()==2){
                    post.pb(stk.top()->val) ;
                    // cout<<"popped "<<stk.top()->val<<"\n";
                    stk.pop() ;
                    cnt.pop() ;
                    
                }
                // post.push_back(root->val) ;
                // stk.pop();
                // cnt.pop();
                if(stk.empty())break;
                root = stk.top() ;
                cnt.top()++ ;
                root = root->right  ;
            }
            else{
                cnt.top()++ ;
                root = root->right;
            }
        }
    }

    return post ;
}

vi postorder2(node* root){
    stack<node*>stk1,stk2 ; 
    stk1.push(root) ;
    while(!stk1.empty()){
        root = stk1.top() ;
        stk1.pop() ;
        stk2.push(root) ;
        if(root->left){
            stk1.push(root->left);
        }
        if(root->right){
            stk1.push(root->right);
        }
    }
    vi post ; 
    while(stk2.size()){
        post.pb(stk2.top()->val);
        stk2.pop();
    }
    return post ;
}


void trav(node * root){
    if(!root){
        return;
    }
    cout<<root->val<<" ";
    trav(root->left) ;
    trav(root->right) ;
}

int main()
{   
    node* root = new node(1) ;
    root->left = new node(2) ;
    root->right = new node(3) ;
    root->left->left = new node(4); 
    root->left->right = new node(5); 

    vi ino = postorder(root) ;
    for(auto x : ino){
        cout<<x<<" ";
    }
    cout<<"\n";
    
    // trav(root) ;
    return 0;
}

// . . . .

