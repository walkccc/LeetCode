WITH
  PassDetails AS (
    SELECT
      Passes.pass_from,
      Passes.pass_to,
      Passes.time_stamp,
      Team1.team_name AS from_team,
      Team2.team_name AS to_team,
      CASE
        WHEN Passes.time_stamp BETWEEN '00:00' AND '45:00' THEN 1
        WHEN Passes.time_stamp BETWEEN '45:01' AND '90:00' THEN 2
      END AS half_number
    FROM Passes
    INNER JOIN Teams AS Team1
      ON (Passes.pass_from = Team1.player_id)
    INNER JOIN Teams AS Team2
      ON (Passes.pass_to = Team2.player_id)
  )
SELECT
  from_team AS team_name,
  half_number,
  SUM(IF(from_team = to_team, 1, -1)) AS dominance
FROM PassDetails
GROUP BY 1, 2
ORDER BY 1, 2;
