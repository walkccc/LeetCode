struct Car {
  int pos;
  int speed;
  double collisionTime;
  Car(int pos, int speed, double collisionTime)
      : pos(pos), speed(speed), collisionTime(collisionTime) {}
};

class Solution {
 public:
  vector<double> getCollisionTimes(vector<vector<int>>& cars) {
    vector<double> ans(cars.size());
    stack<Car> stack;

    for (int i = cars.size() - 1; i >= 0; --i) {
      const int pos = cars[i][0];
      const int speed = cars[i][1];
      while (!stack.empty() && (speed <= stack.top().speed ||
                                getCollisionTime(stack.top(), pos, speed) >=
                                    stack.top().collisionTime))
        stack.pop();
      if (stack.empty()) {
        stack.emplace(pos, speed, INT_MAX);
        ans[i] = -1;
      } else {
        const double collisionTime = getCollisionTime(stack.top(), pos, speed);
        stack.emplace(pos, speed, collisionTime);
        ans[i] = collisionTime;
      }
    }

    return ans;
  }

 private:
  double getCollisionTime(const Car& car, int pos, int speed) {
    return (car.pos - pos) / (double)(speed - car.speed);
  }
};
