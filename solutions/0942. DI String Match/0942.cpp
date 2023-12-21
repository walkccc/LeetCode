class Solution {
 public:
  vector<int> diStringMatch(string s) {
    vector<int> ans;
    int min = 0;
    int max = s.length();

    for (const char c : s)
      ans.push_back(c == 'I' ? min++ : max--);
    ans.push_back(min);

    return ans;
  }
};
