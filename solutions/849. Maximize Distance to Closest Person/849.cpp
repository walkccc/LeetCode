class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    const int n = seats.size();
    int ans = 0;
    int j = -1;

    for (int i = 0; i < n; ++i)
      if (seats[i] == 1) {
        ans = j == -1 ? i : max(ans, (i - j) / 2);
        j = i;
      }

    return max(ans, n - j - 1);
  }
};
