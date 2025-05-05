class Solution {
 public:
  int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    return ranges::count_if(hours,
                            [target](int hour) { return hour >= target; });
  }
};
