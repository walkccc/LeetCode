struct Car {
  int pos;
  double time;  // the time to reach the target
};

class Solution {
 public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int ans = 0;
    vector<Car> cars(position.size());

    for (int i = 0; i < position.size(); ++i)
      cars[i] = {position[i], (double)(target - position[i]) / speed[i]};

    ranges::sort(cars,
                 [](const auto& a, const auto& b) { return a.pos > b.pos; });

    double maxTime = 0;  // the time of the slowest car to reach the target

    for (const Car& car : cars)
      // A car needs more time to reach the target, so it becomes the slowest.
      if (car.time > maxTime) {
        maxTime = car.time;
        ++ans;
      }

    return ans;
  }
};
