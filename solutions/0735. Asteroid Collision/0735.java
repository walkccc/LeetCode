class Solution {
  public int[] asteroidCollision(int[] asteroids) {
    LinkedList<Integer> stack = new LinkedList<>();

    for (final int a : asteroids)
      if (a > 0) {
        stack.add(a);
      } else {
        // destroy previous positive one(s)
        while (!stack.isEmpty() && stack.getLast() > 0 && stack.getLast() < -a)
          stack.removeLast();
        if (stack.isEmpty() || stack.getLast() < 0)
          stack.add(a);
        else if (stack.getLast() == -a)
          stack.removeLast();
      }

    return stack.stream().mapToInt(i -> i).toArray();
  }
}
