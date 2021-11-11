class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = *max_element(begin(piles), end(piles));

    // hours to eat all piles with speed k
    auto eatHours = [&](int k) {
      int hours = 0;
      for (const int pile : piles)
        hours += (pile - 1) / k + 1;  // ceil(pile / k)
      return hours;
    };

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (eatHours(m) <= h)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
