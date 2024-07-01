class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    int ans = 0;
    unordered_set<char> jewelsSet(jewels.begin(), jewels.end());

    for (const char stone : stones)
      if (jewelsSet.count(stone))
        ++ans;

    return ans;
  }
};
