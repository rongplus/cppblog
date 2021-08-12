Analyzing User Churn
Next, Catherine wants to take a look at the churn rate.

A churn rate is the percent of subscribers to a monthly service who have canceled. For example, in January, let’s say Codecademy has 1,000 customers. In February, 200 learners sign up, and 250 cancel.

The churn rate for February would be:

\frac{cancellations}{total\ subscribers} = \frac{250}{1000 + 200} = 20.8\% 
total subscribers
cancellations
​
 = 
1000+200
250
​
 =20.8%
Catherine wants to analyze the churn rates for Codecademy for the past few months so she writes another SQL query.

SELECT COUNT(DISTINCT user_id) AS enrollments,
	COUNT(CASE
       	WHEN strftime("%m", cancel_date) = '03'
        THEN user_id
  END) AS march_cancellations,
 	ROUND(100.0 * COUNT(CASE
       	WHEN strftime("%m", cancel_date) = '03'
        THEN user_id
  END) / COUNT(DISTINCT user_id)) AS churn_rate
FROM pro_users
WHERE signup_date < '2017-04-01'
	AND (
    (cancel_date IS NULL) OR
    (cancel_date > '2017-03-01')
  );



  DELETE FROM band_students
where id in(
  SELECT * from drama_students
);