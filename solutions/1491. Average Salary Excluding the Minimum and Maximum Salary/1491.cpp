class Solution {
 public:
  double average(vector<int>& salary) {
    const double sum = accumulate(salary.begin(), salary.end(), 0.0);
    const int mx = ranges::max(salary);
    const int mn = ranges::min(salary);
    return (sum - mx - mn) / (salary.size() - 2);
  }
};
