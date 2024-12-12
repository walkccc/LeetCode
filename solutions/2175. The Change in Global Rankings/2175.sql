SELECT
  TeamPoints.team_id,
  TeamPoints.name,
  CAST(
    RANK() OVER(
      ORDER BY TeamPoints.points DESC, TeamPoints.name
    ) AS SIGNED
  ) -
  CAST(
    RANK() OVER(
      ORDER BY TeamPoints.points + PointsChange.points_change DESC,
        TeamPoints.name
    ) AS SIGNED
  ) AS rank_diff
FROM TeamPoints
INNER JOIN PointsChange
  USING (team_id);
