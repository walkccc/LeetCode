class Solution {
 public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                               vector<int>& persons) {
    vector<int> ans;
    vector<int> starts;
    vector<int> ends;

    for (const vector<int>& flower : flowers) {
      starts.push_back(flower[0]);
      ends.push_back(flower[1]);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    for (const int p : persons) {
      const int started =
          upper_bound(starts.begin(), starts.end(), p) - starts.begin();
      const int ended = lower_bound(ends.begin(), ends.end(), p) - ends.begin();
      ans.push_back(started - ended);
    }

    return ans;
  }
};
