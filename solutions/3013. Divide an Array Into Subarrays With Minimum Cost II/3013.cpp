class Solution {
 public:
  long long minimumCost(vector<int>& nums, int k, int dist) {
    // Equivalently, the problem is to find nums[0] + the minimum sum of the top
    // k - 1 numbers in nums[i..i + dist], where i > 0 and i + dist < n.
    long windowSum = 0;
    multiset<int> selected;
    multiset<int> candidates;

    for (int i = 1; i <= dist + 1; ++i) {
      windowSum += nums[i];
      selected.insert(nums[i]);
    }

    windowSum = balance(windowSum, selected, candidates, k);
    long minWindowSum = windowSum;

    for (int i = dist + 2; i < nums.size(); ++i) {
      const int outOfScope = nums[i - dist - 1];
      if (selected.find(outOfScope) != selected.end()) {
        windowSum -= outOfScope;
        selected.erase(selected.find(outOfScope));
      } else {
        candidates.erase(candidates.find(outOfScope));
      }
      if (nums[i] < *selected.rbegin()) {  // nums[i] is a better number.
        windowSum += nums[i];
        selected.insert(nums[i]);
      } else {
        candidates.insert(nums[i]);
      }
      windowSum = balance(windowSum, selected, candidates, k);
      minWindowSum = min(minWindowSum, windowSum);
    }

    return nums[0] + minWindowSum;
  }

 private:
  // Returns the updated `windowSum` by balancing the multiset `selected` to
  // keep the top k - 1 numbers.
  long balance(long windowSum, multiset<int>& selected,
               multiset<int>& candidates, int k) {
    while (selected.size() < k - 1) {
      const int minCandidate = *candidates.begin();
      windowSum += minCandidate;
      selected.insert(minCandidate);
      candidates.erase(candidates.find(minCandidate));
    }
    while (selected.size() > k - 1) {
      const int maxSelected = *selected.rbegin();
      windowSum -= maxSelected;
      selected.erase(selected.find(maxSelected));
      candidates.insert(maxSelected);
    }
    return windowSum;
  }
};
