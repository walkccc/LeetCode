WITH
  RankedStudents AS (
    SELECT
      student_id,
      RANK() OVER(PARTITION BY exam_id ORDER BY score ASC) rank_asc,
      RANK() OVER(PARTITION BY exam_id ORDER BY score DESC) rank_desc
    FROM Exam
  )
SELECT * FROM Student
WHERE student_id IN (
  SELECT student_id FROM RankedStudents
  GROUP BY 1
  HAVING MIN(rank_asc) > 1 AND MIN(rank_desc) > 1
)
ORDER BY student_id;
