class Solution {
 public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks,
                  int additionalRocks) {
    const int n = capacity.size();
    vector<int> diff(n);

    for (int i = 0; i < n; ++i)
      diff[i] = capacity[i] - rocks[i];

    sort(begin(diff), end(diff));

    for (int i = 0; i < n; ++i) {
      if (diff[i] > additionalRocks)
        return i;
      additionalRocks -= diff[i];
    }

    return n;
  }
};
