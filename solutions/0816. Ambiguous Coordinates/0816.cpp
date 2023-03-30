class Solution {
 public:
  vector<string> ambiguousCoordinates(string s) {
    vector<string> ans;
    s = s.substr(1, s.length() - 2);

    for (int i = 1; i < s.length(); ++i)
      for (const string& x : splits(s.substr(0, i)))
        for (const string& y : splits(s.substr(i)))
          ans.push_back('(' + x + ", " + y + ')');

    return ans;
  }

 private:
  vector<string> splits(const string& s) {
    if (s.empty() || s.length() > 1 && s.front() == '0' && s.back() == '0')
      return {};
    if (s.back() == '0')
      return {s};
    if (s.front() == '0')
      return {"0." + s.substr(1)};

    vector<string> candidates{s};
    for (int i = 1; i < s.length(); ++i)
      candidates.push_back(s.substr(0, i) + '.' + s.substr(i));
    return candidates;
  }
};
