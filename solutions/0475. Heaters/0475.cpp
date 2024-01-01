class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    ranges::sort(houses);
    ranges::sort(heaters);

    int ans = 0;
    int i = 0;  // heaters' index (currently used)

    for (const int house : houses) {
      while (i + 1 < heaters.size() &&
             house - heaters[i] > heaters[i + 1] - house)
        ++i;  // The next heater is better.
      ans = max(ans, abs(heaters[i] - house));
    }

    return ans;
  }
};
