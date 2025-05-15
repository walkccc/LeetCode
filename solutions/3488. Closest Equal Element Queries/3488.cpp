class Solution {
 public:
  vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    const int n = nums.size();
    vector<int> ans;
    // minDist[i] := the minimum distance between nums[i], and any other index j
    // in the circular array, where nums[j] == nums[i]
    vector<int> minDist(n, n);
    unordered_map<int, int> lastSeen;

    for (int i = 0; i < n * 2; ++i) {
      const int index = i % n;
      const int num = nums[index];
      if (const auto it = lastSeen.find(num); it != lastSeen.cend()) {
        const int prevIndex = it->second % n;
        const int d = i - prevIndex;
        minDist[index] = min(minDist[index], d);
        minDist[prevIndex] = min(minDist[prevIndex], d);
      }
      lastSeen[num] = i;
    }

    for (const int query : queries)
      ans.push_back(minDist[query] == n ? -1 : minDist[query]);

    return ans;
  }
};
