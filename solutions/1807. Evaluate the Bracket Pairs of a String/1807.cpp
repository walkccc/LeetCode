class Solution {
 public:
  string evaluate(string s, vector<vector<string>>& knowledge) {
    string ans;
    unordered_map<string, string> map;

    for (const auto& list : knowledge)
      map["(" + list[0] + ")"] = list[1];

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (c == '(') {
        const int j = s.find_first_of(')', i);
        const string& key = s.substr(i, j - i + 1);
        ans += map.count(key) ? map[key] : "?";
        i = j;
      } else {
        ans += c;
      }
    }

    return ans;
  }
};
