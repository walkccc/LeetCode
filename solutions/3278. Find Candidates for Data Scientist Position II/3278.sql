WITH
  ProjectSkills AS (
    SELECT project_id, COUNT(skill) AS required_skills
    FROM Projects
    GROUP BY 1
  ),
  CandidateScores AS (
    SELECT
      Projects.project_id,
      Candidates.candidate_id,
      100 + SUM(
        CASE
          WHEN Candidates.proficiency > Projects.importance THEN 10
          WHEN Candidates.proficiency < Projects.importance THEN -5
          ELSE 0
        END
      ) AS score,
      COUNT(Projects.skill) AS matched_skills
    FROM Projects
    INNER JOIN Candidates
      USING (skill)
    GROUP BY 1, 2
  ),
  RankedCandidates AS (
    SELECT
      CandidateScores.project_id,
      CandidateScores.candidate_id,
      CandidateScores.score,
      RANK() OVER(
        PARTITION BY CandidateScores.project_id
        ORDER BY CandidateScores.score DESC, CandidateScores.candidate_id
      ) AS `rank`
    FROM CandidateScores
    INNER JOIN ProjectSkills
      USING (project_id)
    WHERE CandidateScores.matched_skills = ProjectSkills.required_skills
  )
SELECT project_id, candidate_id, score
FROM RankedCandidates
WHERE `rank` = 1
ORDER BY 1;
