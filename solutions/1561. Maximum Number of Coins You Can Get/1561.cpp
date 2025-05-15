class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    ranges::sort(piles);

    int ans = 0;

    // piles = [S S M L M L], pick all the M.
    for (int i = piles.size() / 3; i < piles.size(); i += 2)
      ans += piles[i];

    return ans;
  }
};
