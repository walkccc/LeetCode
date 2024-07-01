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

    ranges::sort(subCount, greater<>());
    return accumulate(subCount.begin(), subCount.begin() + maxOnes, 0);
  }
};
