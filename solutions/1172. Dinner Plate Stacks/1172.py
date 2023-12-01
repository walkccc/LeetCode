class DinnerPlates:
  def __init__(self, capacity: int):
    self.capacity = capacity
    self.stacks = []
    self.minHeap = [0]  # the minimum indices of the stacks to push

  def push(self, val: int) -> None:
    index = self.minHeap[0]
    # Add a new stack on demand.
    if index == len(self.stacks):
      self.stacks.append([])
    # Push the new value.
    self.stacks[index].append(val)
    # If the stack pushed is full, remove its candidacy from the `minHeap`.
    if len(self.stacks[index]) == self.capacity:
      heapq.heappop(self.minHeap)
      # If the `minHeap` is empty, the next available stack index is |stacks|.
      if not self.minHeap:
        heapq.heappush(self.minHeap, len(self.stacks))

  def pop(self) -> int:
    # Remove empty stacks from the back.
    while self.stacks and not self.stacks[-1]:
      self.stacks.pop()
    if not self.stacks:
      return -1
    return self.popAtStack(len(self.stacks) - 1)

  def popAtStack(self, index: int) -> int:
    if index >= len(self.stacks) or not self.stacks[index]:
      return -1
    # If the stack is going to have space, add its candiday to the `minHeap`.
    if len(self.stacks[index]) == self.capacity:
      heapq.heappush(self.minHeap, index)
    return self.stacks[index].pop()
