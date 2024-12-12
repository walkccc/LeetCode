class Solution {
  public double[] getCollisionTimes(int[][] cars) {
    double[] ans = new double[cars.length];
    Deque<Car> stack = new ArrayDeque<>();

    for (int i = cars.length - 1; i >= 0; --i) {
      final int pos = cars[i][0];
      final int speed = cars[i][1];
      while (!stack.isEmpty() &&
             (speed <= stack.peek().speed ||
              getCollisionTime(stack.peek(), pos, speed) >= stack.peek().collisionTime))
        stack.pop();
      if (stack.isEmpty()) {
        stack.push(new Car(pos, speed, Integer.MAX_VALUE));
        ans[i] = -1;
      } else {
        final double collisionTime = getCollisionTime(stack.peek(), pos, speed);
        stack.push(new Car(pos, speed, collisionTime));
        ans[i] = collisionTime;
      }
    }

    return ans;
  }

  private record Car(int pos, int speed, double collisionTime) {}

  private double getCollisionTime(Car car, int pos, int speed) {
    return (double) (car.pos - pos) / (speed - car.speed);
  }
}
