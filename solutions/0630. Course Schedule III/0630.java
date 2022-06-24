class Solution {
  public int scheduleCourse(int[][] courses) {
    int time = 0;
    Arrays.sort(courses, (a, b) -> (a[1] - b[1]));
    Queue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);

    for (int[] c : courses) {
      final int duration = c[0];
      final int lastDay = c[1];
      maxHeap.offer(duration);
      time += c[0];
      // if current course could not be taken, check if it's able to swap with a
      // previously taken course with larger duration, to increase the time
      // available to take upcoming courses
      if (time > lastDay)
        time -= maxHeap.poll();
    }

    return maxHeap.size();
  }
}
