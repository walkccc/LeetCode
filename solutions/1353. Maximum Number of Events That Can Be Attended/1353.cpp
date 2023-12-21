class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    int ans = 0;
    int d = 0;  // the current day
    int i = 0;  // events' index
    priority_queue<int, vector<int>, greater<>> minHeap;

    ranges::sort(events);

    while (!minHeap.empty() || i < events.size()) {
      // If no events are available to attend today, let time flies to the next
      // available event.
      if (minHeap.empty())
        d = events[i][0];
      // All the events starting from today are newly available.
      while (i < events.size() && events[i][0] == d)
        minHeap.push(events[i++][1]);
      // Greedily attend the event that'll end the earliest since it has higher
      // chance can't be attended in the future.
      minHeap.pop();
      ++ans;
      ++d;
      // Pop the events that can't be attended.
      while (!minHeap.empty() && minHeap.top() < d)
        minHeap.pop();
    }

    return ans;
  }
};
