WITH
  MatchesWithRowNumberInEachPlayer AS (
    SELECT
      *,
      ROW_NUMBER() OVER(
        PARTITION BY player_id
        ORDER BY match_day
      ) AS `row_number`
    FROM Matches
  ),
  `Groups` AS (
    SELECT
      *,
      `row_number` - ROW_NUMBER() OVER(
        PARTITION BY player_id
        ORDER BY match_day
      ) AS group_id
    FROM MatchesWithRowNumberInEachPlayer
    WHERE result = 'Win'
  ),
  ConsecCounts AS (
    SELECT
      player_id,
      COUNT(*) AS consec_count
    FROM `Groups`
    GROUP BY player_id, group_id
  )
SELECT
  Matches.player_id,
  IFNULL(MAX(ConsecCounts.consec_count), 0) AS longest_streak
FROM Matches
LEFT JOIN ConsecCounts
  USING (player_id)
GROUP BY 1;
