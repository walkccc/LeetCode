class Solution {
  public int carFleet(int target, int[] position, int[] speed) {
    record Car(int pos, double time) {}
    int ans = 0;
    Car[] cars = new Car[position.length];

    for (int i = 0; i < position.length; ++i)
      cars[i] = new Car(position[i], (double) (target - position[i]) / speed[i]);

    Arrays.sort(cars, Comparator.comparingInt(Car::pos).reversed());

    double maxTime = 0; // the time of the slowest car to reach the target

    for (Car car : cars)
      // A car needs more time to reach the target, so it becomes the slowest.
      if (car.time > maxTime) {
        maxTime = car.time;
        ++ans;
      }

    return ans;
  }
}
