class UF {
 public:
  UF(int n) : sz(n, 1), id(n) {
    iota(begin(id), end(id), 0);
  }

  void unionBySize(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return;
    if (sz[i] < sz[j]) {
      sz[j] += sz[i];
      id[i] = j;
    } else {
      sz[i] += sz[j];
      id[j] = i;
    }
  }

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

 private:
  vector<int> sz;
  vector<int> id;
};

class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ans;
    unordered_map<string, int> emailToIndex;        // {email: index}
    unordered_map<int, set<string>> indexToEmails;  // {index: {emails}}
    UF uf(accounts.size());

    for (int i = 0; i < accounts.size(); ++i) {
      const string name = accounts[i][0];
      for (int j = 1; j < accounts[i].size(); ++j) {
        const string email = accounts[i][j];
        const auto it = emailToIndex.find(email);
        if (it == emailToIndex.end()) {
          // only record if it's the first time we see thie email
          emailToIndex[email] = i;
        } else {
          // otherwise, union i w/ emailToIndex[index]
          uf.unionBySize(i, it->second);
        }
      }
    }

    for (const auto& [email, index] : emailToIndex)
      indexToEmails[uf.find(index)].insert(email);

    for (const auto& [index, emails] : indexToEmails) {
      const string name = accounts[index][0];
      vector<string> row{name};
      row.insert(end(row), begin(emails), end(emails));
      ans.push_back(row);
    }

    return ans;
  }
};
