class SnakeGame:
  def __init__(self, width: int, height: int, food: List[List[int]]):
    """
    Initialize your data structure here.
    @param width - screen width
    @param height - screen height
    @param food - A list of food positions
    E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
    """
    self.width = width
    self.height = height
    self.food = food
    self.score = 0
    self.k = 0  # food's index
    self.lookup = set([self.getId(0, 0)])
    self.body = collections.deque([self.getId(0, 0)])  # snake's body

  def move(self, direction: str) -> int:
    """
    Moves the snake.
    @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
    @return The game's score after the move. Return -1 if game over.
    Game over when snake crosses the screen boundary or bites its body.
    """
    # the old head's position
    i = self.body[0] // self.width
    j = self.body[0] % self.width

    # Update the head's position and check if it's out-of-bounds.
    if direction == "U":
      i -= 1
      if i < 0:
        return -1
    if direction == "L":
      j -= 1
      if j < 0:
        return -1
    if direction == "R":
      j += 1
      if j == self.width:
        return -1
    if direction == "D":
      i += 1
      if i == self.height:
        return -1

    newHead = self.getId(i, j)

    # Case 1: Eat food and increase the size by 1.
    if self.k < len(self.food) and i == self.food[self.k][0] and j == self.food[self.k][1]:
      self.lookup.add(newHead)
      self.body.appendleft(newHead)
      self.k += 1
      self.score += 1
      return self.score

    # Case 2: new head != old tail and eat body!
    if newHead != self.body[-1] and newHead in self.lookup:
      return -1

    # Case 3: normal case
    # Remove the old tail first, then add new head because new head may be in
    # old tail's position.
    self.lookup.remove(self.body[-1])
    self.lookup.add(newHead)
    self.body.pop()
    self.body.appendleft(newHead)

    return self.score

  def getId(self, i: int, j: int) -> int:
    return i * self.width + j
