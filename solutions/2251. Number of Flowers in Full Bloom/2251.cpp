class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                               vector<int>& persons) {
    vector<int> ans;
    vector<int> starts;
    vector<int> ends;

    for (const auto& f : flowers) {
      starts.push_back(f[0]);
      ends.push_back(f[1]);
    }

    sort(begin(starts), end(starts));
    sort(begin(ends), end(ends));

    for (const int p : persons) {
      const int started =
          upper_bound(begin(starts), end(starts), p) - begin(starts);
      const int ended = lower_bound(begin(ends), end(ends), p) - begin(ends);
      ans.push_back(started - ended);
    }

    return ans;
  }
};
