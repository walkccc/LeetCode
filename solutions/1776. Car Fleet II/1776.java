class T {
  public int position;
  public int speed;
  public double collideTime;

  public T(int position, int speed, double collideTime) {
    this.position = position;
    this.speed = speed;
    this.collideTime = collideTime;
  }
}

class Solution {
  public double[] getCollisionTimes(int[][] cars) {
    double[] ans = new double[cars.length];
    Stack<T> stack = new Stack<>();

    for (int i = cars.length - 1; i >= 0; --i) {
      final int position = cars[i][0];
      final int speed = cars[i][1];
      while (!stack.isEmpty()
          && (speed <= stack.peek().speed
              || (stack.peek().position - position) / (double) (speed - stack.peek().speed)
                  >= stack.peek().collideTime))
        stack.pop();
      if (stack.isEmpty()) {
        stack.push(new T(position, speed, Integer.MAX_VALUE));
        ans[i] = -1;
      } else {
        final double collideTime =
            (stack.peek().position - position) / (double) (speed - stack.peek().speed);
        stack.push(new T(position, speed, collideTime));
        ans[i] = collideTime;
      }
    }

    return ans;
  }
}
