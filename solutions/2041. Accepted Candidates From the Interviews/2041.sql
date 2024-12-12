SELECT Candidates.candidate_id
FROM Candidates
INNER JOIN Rounds
  USING (interview_id)
WHERE Candidates.years_of_exp >= 2
GROUP BY 1
HAVING SUM(Rounds.score) > 15;
