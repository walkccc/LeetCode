class Solution {
 public:
  vector<int> diStringMatch(string s) {
    vector<int> ans;
    int mn = 0;
    int mx = s.length();

    for (const char c : s)
      ans.push_back(c == 'I' ? mn++ : mx--);
    ans.push_back(mn);

    return ans;
  }
};
