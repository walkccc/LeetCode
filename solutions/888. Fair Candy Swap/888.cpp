class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    const int diff = (accumulate(aliceSizes.begin(), aliceSizes.end(), 0) -
                      accumulate(bobSizes.begin(), bobSizes.end(), 0)) /
                     2;
    const unordered_set<int> bobSizesSet{bobSizes.begin(), bobSizes.end()};

    for (const int aliceSize : aliceSizes) {
      const int target = aliceSize - diff;
      if (bobSizesSet.count(target))
        return {aliceSize, target};
    }

    throw;
  }
};
