class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    const int n = arr.size();
    queue<int> q{{start}};
    vector<bool> seen(n);

    while (!q.empty()) {
      const int node = q.front();
      q.pop();

      if (arr[node] == 0)
        return true;
      if (seen[node])
        continue;

      // Check the available next steps.
      if (node - arr[node] >= 0)
        q.push(node - arr[node]);
      if (node + arr[node] < n)
        q.push(node + arr[node]);

      seen[node] = true;
    }

    return false;
  }
};
