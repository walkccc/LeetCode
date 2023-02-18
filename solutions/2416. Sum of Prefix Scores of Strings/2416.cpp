class TrieNode {
public:
    vector<TrieNode*> child;
    int availablePrefix;
};

const int CHILD_COUNT = 26;
const int nax = 1e7 + 9;
TrieNode pool[nax];
int cnt;
TrieNode *getNode() {
    auto t = &pool[cnt++];
    t->child.resize(CHILD_COUNT);
    for (int i = 0; i < CHILD_COUNT; ++i) {
        t->child[i] = nullptr;
    }
    t->availablePrefix = 0;
    return t;
}

class Solution {
public:
    TrieNode *root;
    //this would insert all the prefixes of the current string
    //in to the TRIE
    void insert(const string &word) {
        auto ptr = root;
        for (char ch: word) {
            int idx = ch - 'a';
            if (!ptr->child[idx]) {
                ptr->child[idx] = getNode();
            }
            ptr = ptr->child[idx];
            ptr->availablePrefix += 1;
        }
    }
    
    //This searches a string in TRIE and counts 
    //all the prefixes along the path
    int search (const string &word) {
        auto ptr = root;
        int prefixCount = 0;
        for (char ch: word) {
            int idx = ch - 'a';
            if (!ptr->child[idx]) {
                return prefixCount;
            }
            ptr = ptr->child[idx];
            prefixCount += ptr->availablePrefix;
        }
        return prefixCount;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        cnt = 0;
        root = getNode();
        for (const string &s: words) {
            insert(s);
        }
        vector<int> result;
        for (const string &s: words) {
            result.push_back(search(s));
        }
        return result;
    }
};
