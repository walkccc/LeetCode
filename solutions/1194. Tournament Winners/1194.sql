WITH
  PlayerToScore AS (
    (
      SELECT
        Players.player_id,
        Players.group_id,
        Matches.first_score AS score
      FROM Players
      LEFT JOIN Matches
        ON (Players.player_id = Matches.first_player)
    )
    UNION ALL
    (
      SELECT
        Players.player_id,
        Players.group_id,
        Matches.second_score AS score
      FROM Players
      LEFT JOIN Matches
        ON (Players.player_id = Matches.second_player)
    )
  ),
  RankedPlayers AS (
    SELECT
      player_id,
      group_id,
      RANK() OVER(
        PARTITION BY group_id
        ORDER BY SUM(score) DESC,
          player_id
      ) AS `rank`
    FROM PlayerToScore
    GROUP BY 1
  )
SELECT group_id, player_id
FROM RankedPlayers
WHERE `rank` = 1;
