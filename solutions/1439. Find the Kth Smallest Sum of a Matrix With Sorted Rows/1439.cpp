struct T {
  int i;
  int j;
  int sum;  // nums1[i] + nums2[j]
  T(int i, int j, int sum) : i(i), j(j), sum(sum) {}
};

class Solution {
 public:
  int kthSmallest(vector<vector<int>>& mat, int k) {
    vector<int> row = mat[0];

    for (int i = 1; i < mat.size(); ++i)
      row = kSmallestPairSums(row, mat[i], k);

    return row.back();
  }

 private:
  // Similar to 373. Find K Pairs with Smallest Sums
  vector<int> kSmallestPairSums(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ans;
    auto compare = [&](const T& a, const T& b) { return a.sum > b.sum; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);

    for (int i = 0; i < k && i < nums1.size(); ++i)
      minHeap.emplace(i, 0, nums1[i] + nums2[0]);

    while (!minHeap.empty() && ans.size() < k) {
      const auto [i, j, _] = minHeap.top();
      minHeap.pop();
      ans.push_back(nums1[i] + nums2[j]);
      if (j + 1 < nums2.size())
        minHeap.emplace(i, j + 1, nums1[i] + nums2[j + 1]);
    }

    return ans;
  }
};
