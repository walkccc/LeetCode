class Solution {
 public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int nextUnsatChair = 0;
    priority_queue<int, vector<int>, greater<>> emptyChairs;
    using P = pair<int, int>;  // (leaving, chair)
    priority_queue<P, vector<P>, greater<>> occupied;

    for (int i = 0; i < times.size(); ++i)
      times[i].push_back(i);

    ranges::sort(times);

    for (const vector<int>& time : times) {
      const int arrival = time[0];
      const int leaving = time[1];
      const int i = time[2];
      while (!occupied.empty() && occupied.top().first <= arrival)
        emptyChairs.push(occupied.top().second), occupied.pop();
      if (i == targetFriend)
        return emptyChairs.empty() ? nextUnsatChair : emptyChairs.top();
      if (emptyChairs.empty())
        occupied.emplace(leaving, nextUnsatChair++);
      else
        occupied.emplace(leaving, emptyChairs.top()), emptyChairs.pop();
    }

    throw;
  }
};
