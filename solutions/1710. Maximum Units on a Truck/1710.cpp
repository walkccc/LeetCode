class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int ans = 0;

    ranges::sort(boxTypes, [](const vector<int>& a, const vector<int>& b) {
      return b[1] < a[1];
    });

    for (const vector<int>& boxType : boxTypes) {
      const int boxes = boxType[0];
      const int units = boxType[1];
      if (boxes >= truckSize)
        return ans + truckSize * units;
      ans += boxes * units;
      truckSize -= boxes;
    }

    return ans;
  }
};
