class Solution:
  def topStudents(
      self,
      positive_feedback: list[str],
      negative_feedback: list[str],
      report: list[str],
      student_id: list[int],
      k: int,
  ) -> list[int]:
    scoreAndIds = []
    pos = set(positive_feedback)
    neg = set(negative_feedback)

    for sid, r in zip(student_id, report):
      score = 0
      for word in r.split():
        if word in pos:
          score += 3
        if word in neg:
          score -= 1
      scoreAndIds.append((-score, sid))

    return [sid for _, sid in sorted(scoreAndIds)[:k]]
