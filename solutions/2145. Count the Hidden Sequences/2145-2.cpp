class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long prefix = 0;
    long mini = 0;  // Starts from 0.
    long maxi = 0;  // Starts from 0.

    for (const int d : differences) {
      prefix += d;
      mini = min(mini, prefix);
      maxi = max(maxi, prefix);
    }

    return max(0L, (upper - lower) - (maxi - mini) + 1);
  }
};
