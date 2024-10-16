WITH 
  VoterToValue AS (
    SELECT
      voter,
      1 / COUNT(*) AS value
    FROM Votes
    GROUP BY voter
  ),
  RankedCandidates AS (
    SELECT
      candidate,
      RANK() OVER(ORDER BY SUM(value) DESC) AS `rank`
    FROM Votes
    INNER JOIN VoterToValue
      USING (voter)
    WHERE candidate IS NOT NULL
    GROUP BY 1
  )
SELECT candidate
FROM RankedCandidates
WHERE `rank` = 1
ORDER BY 1;
