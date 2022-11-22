struct Node {
  int key;
  int value;
  Node(int key, int value) : key(key), value(value) {}
};

class LRUCache {
public:
class node{
    public:
    int key;
    int val;

    node* next;
    node* prev;

    node(int _key,int _val){
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};


    int n;
    unordered_map<int,node*>mp;

    // head and tail
    node* head = new node(0,0);
    node* tail = new node(0,0);    

    void remove(node* root){
        mp.erase(root->key);
        node* r1 = root->next;
        node* r2 = root->prev;
        r2->next = r1;
        r1->prev = r2;  
    }
    
    void insert(node* root){
        mp[root->key] = root;

        node* temp = head->next;
        head->next = root;
        root->next = temp;
        temp->prev = root;
        root->prev = head;        
    }

    LRUCache(int capacity) {
        n = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)==0){
            return -1;
        }
        node *temp = mp[key];
        remove(temp);
        insert(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
        node* temp = new node(key,value);
        if(mp.count(key)!=0){
            remove(mp[key]);
        }
        if(mp.size() == n){
            remove(tail->prev);
        }
        insert(temp);
    }
};

