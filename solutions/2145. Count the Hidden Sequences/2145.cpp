class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    // Starts from 0, so prefix[0] = 0.
    // Changing prefix[0] to any other number doesn't affect the answer.
    vector<long> prefix(differences.size() + 1);

    for (int i = 0; i < differences.size(); ++i)
      prefix[i + 1] += prefix[i] + differences[i];

    const long mx = ranges::max(prefix);
    const long mn = ranges::min(prefix);
    return max(0L, (upper - lower) - (mx - mn) + 1);
  }
};
