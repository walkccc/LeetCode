class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(begin(houses), end(houses));
    sort(begin(heaters), end(heaters));

    int ans = 0;
    int i = 0;  // point to the heater that currently used

    for (const int house : houses) {
      while (i + 1 < heaters.size() &&
             house - heaters[i] > heaters[i + 1] - house)
        ++i;  // next heater is better
      ans = max(ans, abs(heaters[i] - house));
    }

    return ans;
  }
};
