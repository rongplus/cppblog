Catherine’s boss asks her to analyze how users are finding Codecademy’s websites using UTM Parameters. UTM Parameters are special tags that site owners add to their pages to track what website a user was on before they reach the website. For instance:

If a user found Codecademy’s website through Google search, the table page_visits might have utm_source set to ‘google’.
If a different user clicked a Facebook ad to get to Codecademy’s website, then their row in page_visits might have utm_source as ‘facebook’.

---
SELECT utm_source,
 	COUNT(DISTINCT user_id) AS num_users
FROM page_visits
GROUP BY 1
ORDER BY 2 DESC;