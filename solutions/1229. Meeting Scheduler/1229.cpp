class Solution {
 public:
  vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                   vector<vector<int>>& slots2, int duration) {
    ranges::sort(slots1);
    ranges::sort(slots2);

    int i = 0;  // slots1's index
    int j = 0;  // slots2's index

    while (i < slots1.size() && j < slots2.size()) {
      const int start = max(slots1[i][0], slots2[j][0]);
      const int end = min(slots1[i][1], slots2[j][1]);
      if (start + duration <= end)
        return {start, start + duration};
      if (slots1[i][1] < slots2[j][1])
        ++i;
      else
        ++j;
    }

    return {};
  }
};
