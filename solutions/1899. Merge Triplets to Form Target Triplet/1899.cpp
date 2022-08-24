class Solution {
 public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int> merged(target.size());

    for (auto& t : triplets)
      if (equal(begin(t), end(t), begin(target),
                [](int a, int b) { return a <= b; }))
        transform(begin(t), end(t), begin(merged), begin(merged),
                  [](int a, int b) { return max(a, b); });

    return merged == target;
  }
};
