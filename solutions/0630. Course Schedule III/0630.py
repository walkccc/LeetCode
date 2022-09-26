class Solution:
  def scheduleCourse(self, courses: List[List[int]]) -> int:
    time = 0
    maxHeap = []

    for duration, lastDay in sorted(courses, key=lambda x: x[1]):
      heapq.heappush(maxHeap, -duration)
      time += duration
      # if current course could not be taken, check if it's able to swap with a
      # previously taken course with larger duration, to increase the time
      # available to take upcoming courses
      if time > lastDay:
        time += heapq.heappop(maxHeap)

    return len(maxHeap)
