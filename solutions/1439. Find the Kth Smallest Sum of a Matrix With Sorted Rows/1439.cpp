struct Item {
  int i;
  int j;
  int sum;  // nums1[i] + nums2[j]
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
  // very similar to 373. Find K Pairs with Smallest Sums
  vector<int> kSmallestPairSums(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ans;
    auto compare = [&](const Item& a, const Item& b) { return a.sum > b.sum; };
    priority_queue<Item, vector<Item>, decltype(compare)> pq(compare);

    for (int i = 0; i < k && i < nums1.size(); ++i)
      pq.push({i, 0, nums1[i] + nums2[0]});

    while (!pq.empty() && ans.size() < k) {
      const auto [i, j, _] = pq.top(); pq.pop();
      ans.push_back(nums1[i] + nums2[j]);
      if (j + 1 < nums2.size())
        pq.push({i, j + 1, nums1[i] + nums2[j + 1]});
    }

    return ans;
  }
};
