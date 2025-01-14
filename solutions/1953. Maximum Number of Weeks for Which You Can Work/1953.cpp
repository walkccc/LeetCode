class Solution {
 public:
  long long numberOfWeeks(vector<int>& milestones) {
    // The best strategy is to pick "max, nonMax, max, nonMax, ...".
    const int mx = ranges::max(milestones);
    const long sum = accumulate(milestones.begin(), milestones.end(), 0L);
    const long nonMax = sum - mx;
    return min(sum, 2 * nonMax + 1);
  }
};
