class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int H) {
    int l = 1;
    int r = *max_element(begin(piles), end(piles));

    // hours to eat all piles with speed k
    auto eatHours = [&](int k) {
      int hour = 0;
      for (const int pile : piles)
        hour += (pile - 1) / k + 1;
      return hour;
    };

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (eatHours(m) <= H)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
