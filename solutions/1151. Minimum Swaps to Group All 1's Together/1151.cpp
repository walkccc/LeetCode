class Solution {
 public:
  int minSwaps(vector<int>& data) {
    const int k = ranges::count(data, 1);
    int ones = 0;     // the number of ones in the window
    int maxOnes = 0;  // the maximum number of ones in the window

    for (int i = 0; i < data.size(); ++i) {
      if (i >= k && data[i - k])
        --ones;
      if (data[i])
        ++ones;
      maxOnes = max(maxOnes, ones);
    }

    return k - maxOnes;
  }
};
