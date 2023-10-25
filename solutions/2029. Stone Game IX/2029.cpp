class Solution {
 public:
  bool stoneGameIX(vector<int>& stones) {
    vector<int> count(3);

    for (const int stone : stones)
      ++count[stone % 3];

    if (count[0] % 2 == 0)
      return min(count[1], count[2]) > 0;
    return abs(count[1] - count[2]) > 2;
  }
};
