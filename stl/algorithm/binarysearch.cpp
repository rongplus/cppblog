/* 2. BinarySearch
 * Binary search works on sorted arrays. Binary search begins by comparing
 * an element in the middle of the array with the target value. If the target
 * value matches the element, its position in the array is returned. 
 * If the target value is less than the element, the search continues in the
 * lower half of the array. If the target value is greater than the element, 
 * the search continues in the upper half of the array. By doing this,
 * the algorithm eliminates the half in which the target value cannot lie 
 * in each iteration.
 * ASL = log(n+1), Average Performance: O(log n), Space complexity: O(1)
 */

int BinarySearch(int A[], int low, int high, int T)
{
    int L = low, R = high - 1, m;
    while (L <= R)
    {
        m = (L + R) / 2;
        if (A[m] < T)
            L = m + 1;
        else if (A[m] > T)
            R = m - 1;
        else
            return m;
    }
    return -1;
}