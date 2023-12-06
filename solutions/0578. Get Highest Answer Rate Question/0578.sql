SELECT question_id AS survey_log
FROM SurveyLog
GROUP BY 1
ORDER BY
  COUNT(answer_id) / COUNT(*) DESC,
  question_id ASC
LIMIT 1;
