class Solution {
 public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    int ans = 0;

    sort(begin(seats), end(seats));
    sort(begin(students), end(students));

    for (int i = 0; i < seats.size(); ++i)
      ans += abs(seats[i] - students[i]);

    return ans;
  }
};
