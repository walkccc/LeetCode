class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = ranges::max(piles);

    while (l < r) {
      const int m = (l + r) / 2;
      if (eatHours(piles, m) <= h)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  // Returns the hours to eat all the piles with speed m.
  int eatHours(const vector<int>& piles, int m) {
    return accumulate(piles.begin(), piles.end(), 0,
                      [&](int subtotal, int pile) {
      return subtotal + (pile - 1) / m + 1;  // ceil(pile / m)
    });
  }
};
