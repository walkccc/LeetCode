class Solution {
 public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int> merged(target.size());

    for (auto& t : triplets)
      if (equal(t.begin(), t.end(), target.begin(),
                [](int a, int b) { return a <= b; }))
        transform(t.begin(), t.end(), merged.begin(), merged.begin(),
                  [](int a, int b) { return max(a, b); });

    return merged == target;
  }
};
