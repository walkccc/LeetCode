class Item {
  public char c;
  public int freq;
  public Item(char c, int freq) {
    this.c = c;
    this.freq = freq;
  }
}

class Solution {
  public String removeDuplicates(String s, int k) {
    StringBuilder sb = new StringBuilder();
    LinkedList<Item> stack = new LinkedList<>();

    for (final char c : s.toCharArray()) {
      if (!stack.isEmpty() && stack.peek().c == c)
        ++stack.peek().freq;
      else
        stack.push(new Item(c, 1));
      if (stack.peek().freq == k)
        stack.pop();
    }

    while (!stack.isEmpty()) {
      Item item = stack.pop();
      for (int i = 0; i < item.freq; ++i)
        sb.append(item.c);
    }

    return sb.reverse().toString();
  }
}
