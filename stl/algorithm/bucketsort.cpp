/* 
 * bucketSort() - None Comparison Sort algorithm, bucket sorting
 * O(n+k), O(n+k), Stable
 */
void bucketSort(int A[], int n, int max)
{
    int i, j;
    int buckets[max];

    // Initiate all values to 0 in buckets
    memset(buckets, 0, max * sizeof(int));

    // 1. counting
    for (i = 0; i < n; i++)
        buckets[A[i]]++;

    // 2. sorting
    for (i = 0, j = 0; i < max; i++)
    {
        while ((buckets[i]--) > 0)
            A[j++] = i;
    }
}