WITH
  RankedProjects AS (
    SELECT project_id, RANK() OVER(ORDER BY COUNT(*) DESC) AS `rank`
    FROM Project
    GROUP BY 1
  )
SELECT project_id
FROM RankedProjects
WHERE `rank` = 1;
