class Solution {
 public:
  int meetRequirement(int n, vector<vector<int>>& lights,
                      vector<int>& requirement) {
    int ans = 0;
    int currBrightness = 0;
    vector<int> change(n + 1);

    for (const auto& light : lights) {
      const int position = light[0];
      const int range = light[1];
      ++change[max(0, position - range)];
      --change[min(n, position + range + 1)];
    }

    for (int i = 0; i < n; ++i) {
      currBrightness += change[i];
      if (currBrightness >= requirement[i])
        ++ans;
    }

    return ans;
  }
};
