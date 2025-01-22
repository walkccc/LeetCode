class Solution {
 public:
  vector<string> shortestSubstrings(vector<string>& arr) {
    vector<string> ans;
    unordered_map<string, int> count;

    for (const string& s : arr) {
      add(s, count);
    }

    for (const string& s : arr) {
      remove(s, count);
      ans.push_back(getMinSub(s, count));
      add(s, count);
    }

    return ans;
  }

 private:
  vector<string> getSubstrings(const string& s) {
    vector<string> substrings;
    for (int i = 0; i < s.length(); ++i)
      for (int j = i + 1; j <= s.length(); ++j)
        substrings.push_back(s.substr(i, j - i));
    return substrings;
  }

  void add(const string& s, unordered_map<string, int>& count) {
    for (const string& sub : getSubstrings(s))
      ++count[sub];
  }

  void remove(const string& s, unordered_map<string, int>& count) {
    for (const string& sub : getSubstrings(s))
      --count[sub];
  }

  string getMinSub(const string& s, const unordered_map<string, int>& count) {
    string minSub;
    for (const string& sub : getSubstrings(s)) {
      if (count.at(sub) > 0)
        continue;
      if (minSub.empty() || sub.length() < minSub.length() ||
          sub.length() == minSub.length() && sub < minSub)
        minSub = sub;
    }
    return minSub;
  }
};
