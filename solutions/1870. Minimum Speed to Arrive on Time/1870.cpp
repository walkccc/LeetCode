class Solution {
 public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    int ans = -1;
    int l = 1;
    int r = 1e7;

    while (l <= r) {
      const int m = (l + r) / 2;
      if (time(dist, hour, m) > hour) {
        l = m + 1;
      } else {
        ans = m;
        r = m - 1;
      }
    }

    return ans;
  }

 private:
  double time(const vector<int>& dist, double hour, int speed) {
    double sum = 0;
    for (int i = 0; i < dist.size() - 1; ++i)
      sum += ceil((double)dist[i] / speed);
    return sum + (double)dist.back() / speed;
  }
};
