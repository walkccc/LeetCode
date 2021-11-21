class Solution {
 public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> ans;

    for (int i = 0; i + 1 < s.length(); ++i)
      if (s[i] == '+' && s[i + 1] == '+')
        ans.push_back(s.substr(0, i) + "--" + s.substr(i + 2));

    return ans;
  }
};
