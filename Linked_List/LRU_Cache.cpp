//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class Node{
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key, int val){
            this->key=key;
            this->val=val;
            next=NULL;
            prev=NULL;
        }
};

class LRUCache
{
    private:

    public:
    unordered_map<int,Node*> m;
    int size;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    LRUCache(int cap){
        size=cap;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node* p){
        // tail->prev=node->prev;
        // node->prev->next=tail;
        Node*pre=p->prev;
        Node*nex=p->next;
        pre->next=nex;
        nex->prev=pre;

    }
    void addNode(Node *newnode){
        Node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }

    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(m.find(key)!=m.end()){
            Node* resnode=m[key];
            int res=resnode->val;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key]=head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here   
        if(m.find(key)!=m.end()){
            Node * existingNode=m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if(m.size()==size){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        m[key]=head->next;
        
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends