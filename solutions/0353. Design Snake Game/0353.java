class SnakeGame {
  public SnakeGame(int width, int height, int[][] food) {
    this.width = width;
    this.height = height;
    this.food = food;
    lookup.add(getId(0, 0));
    body.offerLast(getId(0, 0));
  }

  public int move(String direction) {
    // old head's position
    int i = body.peekFirst() / width;
    int j = body.peekFirst() % width;

    // update head's position and check if out of bound
    if (direction.equals("U") && --i < 0)
      return -1;
    else if (direction.equals("L") && --j < 0)
      return -1;
    else if (direction.equals("R") && ++j == width)
      return -1;
    else if (direction.equals("D") && ++i == height)
      return -1;

    final int newHead = getId(i, j);

    // case 1: eat food and increase size by 1
    if (k < food.length && i == food[k][0] && j == food[k][1]) {
      lookup.add(newHead);
      body.offerFirst(newHead);
      ++k;
      return ++score;
    }

    // case 2: new head != old tail and eat body!
    if (newHead != body.peekLast() && lookup.contains(newHead))
      return -1;

    // case 3: normal case
    // remove old tail first (important), then add new head
    // because new head may be in old tail's position
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