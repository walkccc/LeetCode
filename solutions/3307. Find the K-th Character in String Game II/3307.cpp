class Solution {
 public:
  char kthCharacter(long long k, vector<int>& operations) {
    const int operationsCount = ceil(log2(k));
    int increases = 0;

    for (int i = operationsCount - 1; i >= 0; --i) {
      const long halfSize = 1L << i;
      if (k > halfSize) {
        k -= halfSize;  // Move k from the right half to the left half.
        increases += operations[i];
      }
    }

    return 'a' + increases % 26;
  }
};
