WITH RECURSIVE
  -- Join team names for both passing and receiving players.
  TeamPasses AS (
    SELECT
      Team1.team_name AS team1,
      Team2.team_name AS team2,
      Passes.time_stamp
    FROM Passes
    INNER JOIN Teams AS Team1
      ON (Passes.pass_from = Team1.player_id)
    INNER JOIN Teams AS Team2
      ON (Passes.pass_to = Team2.player_id)
  ),
  -- Rank passes by timestamp within each team.
  Ranked AS (
    SELECT
      team1,
      team2,
      RANK() OVER(PARTITION BY team1 ORDER BY time_stamp) AS `rank`
    FROM TeamPasses
  ),
  -- Recursively calculate pass streaks.
  PassStreaks AS (
    -- Base case: first pass for each team
    SELECT
      team1,
      team2,
      `rank`,
      IF(team1 = team2, 1, 0) AS streak
    FROM Ranked
    WHERE `rank` = 1
    UNION ALL
    -- Recursive case: subsequent passes
    SELECT
      Ranked.team1,
      Ranked.team2,
      Ranked.`rank`,
      IF(Ranked.team1 = Ranked.team2, PassStreaks.streak + 1, 0) AS streak
    FROM Ranked
    INNER JOIN PassStreaks
      ON (
        Ranked.`rank` = PassStreaks.`rank` + 1
        AND Ranked.team1 = PassStreaks.team1)
  )
-- Get the longest streak for each team.
SELECT team1 AS team_name, MAX(streak) AS longest_streak
FROM PassStreaks
GROUP BY 1
HAVING longest_streak > 0
ORDER BY 1;
