class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    int ans = INT_MAX;
    vector<int> count(26);

    for (char c : text)
      ++count[c - 'a'];

    for (char c : string("ban"))
      ans = min(ans, count[c - 'a']);

    for (char c : string("lo"))
      ans = min(ans, count[c - 'a'] / 2);

    return ans;
  }
};
