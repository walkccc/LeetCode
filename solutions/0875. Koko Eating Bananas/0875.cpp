class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int H) {
    int l = 1;
    int r = *max_element(begin(piles), end(piles)) + 1;

    while (l < r) {
      int m = l + (r - l) / 2;
      int hour = 0;
      for (int pile : piles) hour += (pile - 1) / m + 1;
      if (hour > H)
        l = m + 1;
      else
        r = m;
    }

    return l;
  }
};