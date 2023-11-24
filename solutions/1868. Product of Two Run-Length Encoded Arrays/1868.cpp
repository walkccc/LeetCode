class Solution {
 public:
  vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1,
                                   vector<vector<int>>& encoded2) {
    vector<vector<int>> ans;
    int i = 0;  // encoded1's index
    int j = 0;  // encodes2's index

    while (i < encoded1.size() && j < encoded2.size()) {
      const int mult = encoded1[i][0] * encoded2[j][0];
      const int minFreq = min(encoded1[i][1], encoded2[j][1]);
      if (!ans.empty() && mult == ans.back()[0])
        ans.back()[1] += minFreq;
      else
        ans.push_back({mult, minFreq});
      encoded1[i][1] -= minFreq;
      encoded2[j][1] -= minFreq;
      if (encoded1[i][1] == 0)
        ++i;
      if (encoded2[j][1] == 0)
        ++j;
    }

    return ans;
  }
};
