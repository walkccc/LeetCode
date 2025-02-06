class SnakeGame {
  /**
   * Initialize your data structure here.
   *
   * @param width  - screen width
   * @param height - screen height
   * @param food   - A list of food positions E.g food = [[1,1], [1,0]] means the
   *               first food is positioned at [1,1], the second is at [1,0].
   */
  public SnakeGame(int width, int height, int[][] food) {
    this.width = width;
    this.height = height;
    this.food = food;
    lookup.add(getId(0, 0));
    body.offerLast(getId(0, 0));
  }

  /**
   * Moves the snake.
   *
   * @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
   * @return The game's score after the move. Return -1 if game over. Game over
   *         when snake crosses the screen boundary or bites its body.
   */
  public int move(String direction) {
    // the old head's position
    int i = body.peekFirst() / width;
    int j = body.peekFirst() % width;

    // Update the head's position and check if it's out-of-bounds.
    if (direction.equals("U") && --i < 0)
      return -1;
    if (direction.equals("L") && --j < 0)
      return -1;
    if (direction.equals("R") && ++j == width)
      return -1;
    if (direction.equals("D") && ++i == height)
      return -1;

    final int newHead = getId(i, j);

    // 1. Eat food and increase the size by 1.
    if (k < food.length && i == food[k][0] && j == food[k][1]) {
      lookup.add(newHead);
      body.offerFirst(newHead);
      ++k;
      return ++score;
    }

    // 2. new head != old tail and eat body!
    if (newHead != body.peekLast() && lookup.contains(newHead))
      return -1;

    // 3. normal case
    // Remove the old tail first, then add new head because new head may be in
    // old tail's position.
    lookup.remove(body.peekLast());
    lookup.add(newHead);
    body.pollLast();
    body.offerFirst(newHead);
    return score;
  }

  private int width;
  private int height;
  private int score = 0;
  private int k = 0; // food's index
  private int[][] food;
  private Set<Integer> lookup = new HashSet<>();
  private Deque<Integer> body = new ArrayDeque<>(); // snake's body

  private int getId(int i, int j) {
    return i * width + j;
  }
}
