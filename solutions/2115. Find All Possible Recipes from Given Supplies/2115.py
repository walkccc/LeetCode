class Solution:
  def findAllRecipes(
      self,
      recipes: list[str],
      ingredients: list[list[str]],
      supplies: list[str],
  ) -> list[str]:
    ans = []
    supplies = set(supplies)
    graph = collections.defaultdict(list)
    inDegrees = collections.Counter()
    q = collections.deque()

    # Build the graph.
    for i, recipe in enumerate(recipes):
      for ingredient in ingredients[i]:
        if ingredient not in supplies:
          graph[ingredient].append(recipe)
          inDegrees[recipe] += 1

    # Perform topological sorting.
    for recipe in recipes:
      if inDegrees[recipe] == 0:
        q.append(recipe)

    while q:
      u = q.popleft()
      ans.append(u)
      for v in graph[u]:
        inDegrees[v] -= 1
        if inDegrees[v] == 0:
          q.append(v)

    return ans
