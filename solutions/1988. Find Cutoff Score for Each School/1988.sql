SELECT
  Schools.school_id,
  IFNULL(MIN(Exam.score), -1) AS score
FROM Schools
LEFT JOIN Exam
  ON (capacity >= student_count)
GROUP BY 1;
