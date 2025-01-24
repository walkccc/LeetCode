class Solution:
  def canAliceWin(self, a: list[str], b: list[str]) -> bool:
    # words[0][i] := the biggest word starting with ('a' + i) for Alice
    # words[1][i] := the biggest word starting with ('a' + i) for Bob
    words = [[''] * 26 for _ in range(2)]

    # For each letter, only the biggest word is useful.
    for word in a:
      words[0][ord(word[0]) - ord('a')] = word

    for word in b:
      words[1][ord(word[0]) - ord('a')] = word

    # Find Alice's smallest word.
    i = 0
    while not words[0][i]:
      i += 1

    # 0 := Alice, 1 := Bob
    # Start with Alice, so it's Bob's turn now.
    turn = 1

    # Iterate through each letter until we find a winner.
    while True:
      # If the current player has a word that having the letter that is greater
      # than the opponent's word, choose it.
      if words[turn][i] and words[turn][i] > words[1 - turn][i]:
        # Choose the current words[turn][i].
        pass
      elif words[turn][i + 1]:
        # Choose the next words[turn][i + 1].
        i += 1
      else:
        # Game over. If it's Bob's turn, Alice wins, and vice versa.
        return turn == 1
      turn = 1 - turn
