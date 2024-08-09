class Solution {
 public:
  int kSimilarity(string s1, string s2) {
    int ans = 0;
    queue<string> q{{s1}};
    unordered_set<string> seen{{s1}};

    while (!q.empty()) {
      for (int sz = q.size(); sz > 0; --sz) {
        string curr = q.front();
        q.pop();
        if (curr == s2)
          return ans;
        for (const string& child : getChildren(curr, s2)) {
          if (seen.contains(child))
            continue;
          q.push(child);
          seen.insert(child);
        }
      }
      ++ans;
    }

    return -1;
  }

 private:
  vector<string> getChildren(string& curr, const string& target) {
    vector<string> children;
    int i = 0;  // the first index s.t. curr[i] != target[i]
    while (curr[i] == target[i])
      ++i;

    for (int j = i + 1; j < curr.length(); ++j)
      if (curr[j] == target[i]) {
        swap(curr[i], curr[j]);
        children.push_back(curr);
        swap(curr[i], curr[j]);
      }

    return children;
  }
};
