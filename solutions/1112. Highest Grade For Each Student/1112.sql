WITH
  RankedEnrollments AS (
    SELECT
      student_id,
      course_id,
      grade,
      RANK() OVER(
        PARTITION BY student_id
        ORDER BY grade DESC, course_id
      ) AS `rank`
    FROM Enrollments
  )
SELECT
  student_id,
  course_id,
  grade
FROM RankedEnrollments
WHERE `rank` = 1;
