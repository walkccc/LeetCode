class Solution {
 public:
  long long minTotalTime(vector<int>& forward, vector<int>& backward,
                         vector<int>& queries) {
    const int n = forward.size();
    const long sum = accumulate(backward.begin(), backward.end(), 0L);
    long ans = 0;
    int pos = 0;
    vector<long> prefixF(n + 1);
    vector<long> prefixB(n + 1);

    for (int i = 0; i < n; ++i) {
      prefixF[i + 1] = prefixF[i] + forward[i];
      prefixB[i] = (i == 0 ? 0 : prefixB[i - 1]) + backward[i];
    }

    for (const int q : queries) {
      const long r = (q < pos ? prefixF[n] : 0) + prefixF[q] - prefixF[pos];
      const long l = (q > pos ? sum : 0) + prefixB[pos] - prefixB[q];
      ans += min(l, r);
      pos = q;
    }

    return ans;
  }
};
