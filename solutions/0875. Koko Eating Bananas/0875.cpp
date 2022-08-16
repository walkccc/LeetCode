class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = *max_element(begin(piles), end(piles));

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
  // hours to eat all piles with speed m
  int eatHours(const vector<int>& piles, int m) {
    return accumulate(begin(piles), end(piles), 0, [&](int subtotal, int pile) {
      return subtotal + (pile - 1) / m + 1;  // ceil(pile / m)
    });
  }
};
