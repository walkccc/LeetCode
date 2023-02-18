class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    const int n = dist.size();
    vector<int> arrivalTime(n);

    for (int i = 0; i < n; ++i)
      arrivalTime[i] = (dist[i] - 1) / speed[i];

    sort(begin(arrivalTime), end(arrivalTime));

    for (int i = 0; i < n; ++i)
      if (i > arrivalTime[i])
        return i;

    return n;
  }
};
