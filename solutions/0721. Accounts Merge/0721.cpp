class UF {
 public:
  UF(const vector<vector<string>>& accounts) {
    for (const vector<string>& account : accounts)
      for (int i = 1; i < account.size(); ++i) {
        const string& email = account[i];
        rank[email] = 0;
        parent[email] = email;
      }
  }

  void union_(const string& u, const string& v) {
    const string& pu = find(u);
    const string& pv = find(v);
    if (pu == pv) return;

    if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else if (rank[pu] > rank[pv])
      parent[pv] = pu;
    else {
      parent[pu] = pv;
      ++rank[pv];
    }
  }

  string find(const string& u) {
    if (parent[u] != u)
      parent[u] = find(parent[u]);
    return parent[u];
  }

 private:
  unordered_map<string, int> rank;
  unordered_map<string, string> parent;
};

class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ans;
    unordered_map<string, string> emailToName;
    unordered_map<string, set<string>> groups;  // {parentEmail: {emails}}
    UF uf(accounts);

    // get {email: name} mapping
    for (const vector<string>& account : accounts)
      for (int i = 1; i < account.size(); ++i)
        if (!emailToName.count(account[i]))
          emailToName[account[i]] = account[0];

    // union emails
    for (const vector<string>& account : accounts)
      for (int i = 2; i < account.size(); ++i)
        uf.union_(account[i], account[i - 1]);

    for (const vector<string>& account : accounts)
      for (int i = 1; i < account.size(); ++i) {
        const string& parentEmail = uf.find(account[i]);
        groups[parentEmail].insert(account[i]);
      }

    for (const auto& [parentEmail, emails] : groups) {
      const string& name = emailToName[parentEmail];
      vector<string> row{begin(emails), end(emails)};
      row.insert(begin(row), name);
      ans.push_back(row);
    }

    return ans;
  }
};