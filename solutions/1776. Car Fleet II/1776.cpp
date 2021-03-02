struct T {
  int position;
  int speed;
  double collideTime;
};

class Solution {
 public:
  vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    vector<double> ans(cars.size());
    stack<T> stack;

    for (int i = cars.size() - 1; i >= 0; --i) {
      const int position = cars[i][0];
      const int speed = cars[i][1];
      while (!stack.empty() && (speed <= stack.top().speed ||
                                (stack.top().position - position) /
                                        (double)(speed - stack.top().speed) >=
                                    stack.top().collideTime))
        stack.pop();
      if (stack.empty()) {
        stack.push({position, speed, INT_MAX});
        ans[i] = -1;
      } else {
        const double collideTime = (stack.top().position - position) /
                                   (double)(speed - stack.top().speed);
        stack.push({position, speed, collideTime});
        ans[i] = collideTime;
      }
    }

    return ans;
  }
};
