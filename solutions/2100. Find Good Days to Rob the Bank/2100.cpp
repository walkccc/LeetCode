class Solution {
 public:
  vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    const int n = security.size();
    vector<int> ans;
    // dec[i] := the number of continuous decreasing numbers before i
    vector<int> dec(n);
    // inc[i] := the number of continuous increasing numbers after i
    vector<int> inc(n);

    for (int i = 1; i < n; ++i)
      if (security[i - 1] >= security[i])
        dec[i] = dec[i - 1] + 1;

    for (int i = n - 2; i >= 0; --i)
      if (security[i] <= security[i + 1])
        inc[i] = inc[i + 1] + 1;

    for (int i = 0; i < n; ++i)
      if (dec[i] >= time && inc[i] >= time)
        ans.push_back(i);

    return ans;
  }
};
