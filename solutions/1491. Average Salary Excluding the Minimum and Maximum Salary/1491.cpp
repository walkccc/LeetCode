class Solution {
 public:
  double average(vector<int>& salary) {
    const double sum = accumulate(salary.begin(), salary.end(), 0.0);
    const int max = ranges::max(salary);
    const int min = ranges::min(salary);
    return (sum - max - min) / (salary.size() - 2);
  }
};
