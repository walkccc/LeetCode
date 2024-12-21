class Solution {
 public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int> merged(target.size());

    for (const vector<int>& triplet : triplets)
      if (equal(triplet.begin(), triplet.end(), target.begin(),
                [](int a, int b) { return a <= b; }))
        transform(triplet.begin(), triplet.end(), merged.begin(),
                  merged.begin(), [](int a, int b) { return max(a, b); });

    return merged == target;
  }
};
