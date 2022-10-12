class Solution {
 public:
  vector<string> ambiguousCoordinates(string S) {
    vector<string> ans;
    S = S.substr(1, S.length() - 2);

    for (int i = 1; i < S.length(); ++i)
      for (const string& x : splits(S.substr(0, i)))
        for (const string& y : splits(S.substr(i)))
          ans.push_back('(' + x + ", " + y + ')');

    return ans;
  }

 private:
  vector<string> splits(const string& S) {
    if (S.empty() || S.length() > 1 && S.front() == '0' && S.back() == '0')
      return {};
    if (S.back() == '0')
      return {S};
    if (S.front() == '0')
      return {"0." + S.substr(1)};

    vector<string> candidates{S};
    for (int i = 1; i < S.length(); ++i)
      candidates.push_back(S.substr(0, i) + '.' + S.substr(i));
    return candidates;
  }
};
