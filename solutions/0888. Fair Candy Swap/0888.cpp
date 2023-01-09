class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    const int diff = (accumulate(begin(aliceSizes), end(aliceSizes), 0) -
                      accumulate(begin(bobSizes), end(bobSizes), 0)) /
                     2;
    const unordered_set<int> bobSizesSet{begin(bobSizes), end(bobSizes)};

    for (const int aliceSize : aliceSizes) {
      const int target = aliceSize - diff;
      if (bobSizesSet.count(target))
        return {aliceSize, target};
    }

    throw;
  }
};
