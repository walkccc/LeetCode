class Solution {
 public:
  int minSwaps(vector<int>& data) {
    const int k = ranges::count(data, 1);
    int ones = 0;     // Ones in window
    int maxOnes = 0;  // Max ones in window

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
