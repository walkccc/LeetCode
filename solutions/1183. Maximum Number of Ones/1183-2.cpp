class Solution {
 public:
  int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
    vector<int> subCount;

    auto getCount = [&](int length, int index) -> int {
      return (length - index - 1) / sideLength + 1;
    };

    for (int i = 0; i < sideLength; ++i)
      for (int j = 0; j < sideLength; ++j)
        subCount.push_back(getCount(width, i) * getCount(height, j));

    sort(begin(subCount), end(subCount), greater<>());
    return accumulate(begin(subCount), begin(subCount) + maxOnes, 0);
  }
};
