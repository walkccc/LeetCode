class Solution {
 public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> keyToStrings;

    for (const string& s : strings)
      keyToStrings[getKey(s)].push_back(s);

    for (const auto& [_, strings] : keyToStrings)
      ans.push_back(strings);

    return ans;
  }

 private:
  // "abc" -> "11" because diff(a, b) = 1 and diff(b, c) = 1
  string getKey(const string& s) {
    string key;

    for (int i = 1; i < s.length(); ++i) {
      const int diff = (s[i] - s[i - 1] + 26) % 26;
      key += to_string(diff) + ",";
    }

    return key;
  }
};
