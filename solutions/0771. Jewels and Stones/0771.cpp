class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    int ans = 0;
    unordered_set<char> jewels(begin(J), end(J));

    for (const char s : S)
      if (jewels.count(s))
        ++ans;

    return ans;
  }
};
