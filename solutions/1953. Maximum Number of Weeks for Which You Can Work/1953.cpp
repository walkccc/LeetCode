class Solution {
 public:
  long long numberOfWeeks(vector<int>& milestones) {
    // The best strategy is to pick "max, nonMax, max, nonMax, ...".
    const int max = ranges::max(milestones);
    const long long sum = accumulate(milestones.begin(), milestones.end(), 0LL);
    const long long nonMax = sum - max;
    return min(sum, 2 * nonMax + 1);
  }
};
