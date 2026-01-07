#include <iostream>
#include <string>
using namespace std;

// ---------- Single Level ----------
class SingleLevel {
    string files[10]; int n=0;
public:
    void create(string f){ files[n++] = f; }
    void show(){ cout<<"Single Level: "; for(int i=0;i<n;i++) cout<<files[i]<<" "; cout<<endl; }
};

// ---------- Two Level ----------
class TwoLevel {
    string user[5][10]; int cnt[5]={0};
public:
    void create(int u,string f){ user[u][cnt[u]++] = f; }
    void show(int u){ cout<<"User "<<u<<": "; for(int i=0;i<cnt[u];i++) cout<<user[u][i]<<" "; cout<<endl; }
};

// ---------- Hierarchical ----------
struct Node {
    string name; bool isFile; Node* child[5]; int c=0;
    Node(string n,bool f):name(n),isFile(f){}
};
class Hierarchical {
    Node* root = new Node("root",0);
public:
    Node* getRoot(){ return root; }
    void add(Node* d,string n,bool f){ d->child[d->c++] = new Node(n,f); }
    void show(Node* d,int sp=0){
        for(int i=0;i<sp;i++) cout<<"  ";
        cout<<(d->isFile?"File: ":"Dir: ")<<d->name<<endl;
        for(int i=0;i<d->c;i++) show(d->child[i],sp+1);
    }
};

// ---------- Main ----------
int main(){
    SingleLevel s; TwoLevel t; Hierarchical h;

    s.create("a.txt"); s.create("b.txt"); s.show();
    t.create(0,"file1"); t.create(0,"file2"); t.show(0);
    Node* root=h.getRoot();
    h.add(root,"dir1",0); h.add(root,"fileA",1);
    h.add(root->child[0],"fileB",1);
    h.show(root);
}
