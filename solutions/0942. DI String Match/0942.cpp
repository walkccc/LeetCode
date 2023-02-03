class Solution {
 public:
  vector<int> diStringMatch(string S) {
    vector<int> ans;
    int min = 0;
    int max = S.length();

    for (const char c : S)
      ans.push_back(c == 'I' ? min++ : max--);
    ans.push_back(min);

    return ans;
  }
};
