class Solution {
  public int scheduleCourse(int[][] courses) {
    int time = 0;
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    Arrays.sort(courses, (a, b) -> (a[1] - b[1]));

    for (int[] course : courses) {
      final int duration = course[0];
      final int lastDay = course[1];
      maxHeap.offer(duration);
      time += course;
      // If the current course cannot be taken, check if it can be swapped with
      // a previously taken course that has a larger duration to increase the
      // time available to take upcoming courses.
      if (time > lastDay)
        time -= maxHeap.poll();
    }

    return maxHeap.size();
  }
}
