class Solution {
 public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> ans(n);
    stack<int> stack;  // [oldest_id, ..., latest_id]
    int prevTime;

    for (const string& log : logs) {
      // Get the seperators' indices.
      const int colon1 = log.find_first_of(':');
      const int colon2 = log.find_last_of(':');
      // Get the function_id, the label, and the timestamp.
      const int id = stoi(log.substr(0, colon1));  // {function_id}
      const char label = log[colon1 + 1];  // {"s" ("start") | "e" ("end") }
      const int timestamp = stoi(log.substr(colon2 + 1));  // {timestamp}
      if (label == 's') {
        if (!stack.empty())
          ans[stack.top()] += timestamp - prevTime;
        stack.push(id);
        prevTime = timestamp;
      } else {
        ans[stack.top()] += timestamp - prevTime + 1, stack.pop();
        prevTime = timestamp + 1;
      }
    }

    return ans;
  }
};
