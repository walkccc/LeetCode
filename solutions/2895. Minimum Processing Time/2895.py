class Solution:
  def minProcessingTime(
      self,
      processorTime: list[int],
      tasks: list[int],
  ) -> int:
    return max(time + task
               for (time, task) in zip(
                   sorted(processorTime),
                   sorted(tasks)[:: -4]))
