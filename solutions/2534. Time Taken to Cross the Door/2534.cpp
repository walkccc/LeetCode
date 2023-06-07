class Solution {
 public:
  vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
    const int n = arrival.size();
    vector<int> ans(n);
    // qs[0] := enter, qs[1] := exit
    vector<queue<int>> qs(2);
    int time = 0;
    int d = 1;

    for (int i = 0; i < n; ++i) {
      popQueues(time, d, arrival[i], qs, ans);
      // If the door was not used in the previous second, then the person who
      // wants to exit goes first.
      if (arrival[i] > time) {
        time = arrival[i];  // Forward the `time` to now.
        d = 1;
      }
      qs[state[i]].push(i);
    }

    popQueues(time, d, 200'000, qs, ans);
    return ans;
  }

 private:
  void popQueues(int& time, int& d, int arrivalTime, vector<queue<int>>& qs,
                 vector<int>& ans) {
    while (arrivalTime > time && (!qs[0].empty() || !qs[1].empty())) {
      if (qs[d].empty())
        d ^= 1;
      ans[qs[d].front()] = time, qs[d].pop();
      ++time;
    }
  }
};
