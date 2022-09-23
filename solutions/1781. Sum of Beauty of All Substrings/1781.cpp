class Solution {
 public:
  int beautySum(string s) {
    int ans = 0;

    for (int i = 0; i < s.length(); ++i) {
      vector<int> count(26);
      for (int j = i; j < s.length(); ++j) {
        ++count[s[j] - 'a'];
        ans += *max_element(begin(count), end(count)) - getMin(count);
      }
    }

    return ans;
  }

 private:
  int getMin(const vector<int>& count) {
    int mini = INT_MAX;
    for (const int c : count)
      if (c > 0)
        mini = min(mini, c);
    return mini;
  }
};
