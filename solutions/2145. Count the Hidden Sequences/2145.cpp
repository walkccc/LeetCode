class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    // start from 0, so prefix[0] = 0
    // changing prefix[0] to any other number doesn't affect the ans
    vector<long> prefix(differences.size() + 1);

    for (int i = 0; i < differences.size(); ++i)
      prefix[i + 1] += prefix[i] + differences[i];

    const long maxi = *max_element(begin(prefix), end(prefix));
    const long mini = *min_element(begin(prefix), end(prefix));
    return max(0L, (upper - lower) - (maxi - mini) + 1);
  }
};
