class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    int ans = 0;
    int sumSatisfaction = 0;

    sort(satisfaction.rbegin(), satisfaction.rend());

    for (const int s : satisfaction) {
      sumSatisfaction += s;
      if (sumSatisfaction <= 0)
        return ans;
      ans += sumSatisfaction;
    }

    return ans;
  }
};
