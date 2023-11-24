class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    ranges::sort(piles);

    int ans = 0;

    // piles = [L M L M L M S S S], pick all the M.
    for (int i = piles.size() / 3; i < piles.size(); i += 2)
      ans += piles[i * 2 + 1];

    return ans;
  }
};
