class Solution {
 public:
  int numTimesAllBlue(vector<int>& flips) {
    int ans = 0;
    int rightmost = 0;

    for (int i = 0; i < flips.size(); ++i) {
      rightmost = max(rightmost, flips[i]);
      // max(flips[0..i]) = rightmost = i + 1,
      // so flips[0..i] is a permutation of 1, 2, ..., i + 1.
      if (rightmost == i + 1)
        ++ans;
    }

    return ans;
  }
};
