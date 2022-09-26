class DinnerPlates:
  def __init__(self, capacity: int):
    self.capacity = capacity
    self.stacks = []
    self.minHeap = [0]  # min stacks to push

  def push(self, val: int) -> None:
    index = self.minHeap[0]
    # add new stack on demand
    if index == len(self.stacks):
      self.stacks.append([])
    # push the new value
    self.stacks[index].append(val)
    # if the stack pushed is full, remove its candidacy from minHeap
    if len(self.stacks[index]) == self.capacity:
      heapq.heappop(self.minHeap)
      # if minHeap is empty, the next available stack index is stacks.size()
      if not self.minHeap:
        heapq.heappush(self.minHeap, len(self.stacks))

  def pop(self) -> int:
    # remove empty stacks from back
    while self.stacks and not self.stacks[-1]:
      self.stacks.pop()
    if not self.stacks:
      return -1
    return self.popAtStack(len(self.stacks) - 1)

  def popAtStack(self, index: int) -> int:
    if index >= len(self.stacks) or not self.stacks[index]:
      return -1
    # if the stack is going to have space, add its candiday to minHeap
    if len(self.stacks[index]) == self.capacity:
      heapq.heappush(self.minHeap, index)
    return self.stacks[index].pop()
