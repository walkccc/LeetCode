class Solution:
  def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
    return max(time + task
               for (time, task) in zip(sorted(processorTime), sorted(tasks)[::-4]))
