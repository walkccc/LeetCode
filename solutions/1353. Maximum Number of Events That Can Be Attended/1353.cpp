class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    int ans = 0;
    int d = 0;  // current day
    int i = 0;  // events' index
    priority_queue<int, vector<int>, greater<>> minHeap;

    sort(begin(events), end(events));

    while (!minHeap.empty() || i < events.size()) {
      // if no events are available to attend today,
      // let time flies to the next available event
      if (minHeap.empty())
        d = events[i][0];
      // all events starting from today are newly available
      while (i < events.size() && events[i][0] == d)
        minHeap.push(events[i++][1]);
      // greedily attend the event that'll end the earliest
      // because it has higher chance can't be attended in the future
      minHeap.pop();
      ++ans;
      ++d;
      // pop events that can't be attended
      while (!minHeap.empty() && minHeap.top() < d)
        minHeap.pop();
    }

    return ans;
  }
};
