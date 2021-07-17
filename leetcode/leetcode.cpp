1. Two Sum
    a, sort
    b, int s = 0; e = size;
    c, sum = num[e]+ num[s]
    d, if sum == target, return {e,s}
        else if sum > target e--;
        else s++; 

2. Add Two Numbers
    a, int res = 0; int value = 0;
    b, sum = nums1[n] + nums2[n] + res;
    c, res = sum/10; value = sum%10;
    d, make a list node, which value is value;


3. Longest Substring Without Repeating Characters
    inStr, subStr;
    a, get ch = inStr[n],
    b, if ch not in subStr, append ch to sbStr; get the max = curLen;
        else, find ch position in subStr, make subStr = subStr.subStr(pos+1),
            and append ch to the end; 

4. Median of Two Sorted Arrays
    solution A, remove bigest and smallest till 1 or 2 left,  return sum/size;
    solution B, move start to middle.
    solution C, remove smallest till size/2

5. Longest Palindromic Substring
    solution A, from pos N, check s[n+off] and s[n-off], ,then off++, till s[n+off] != s[n-off], then check s[n+pos+1] and s[n-pos-1].

6. ZigZag Conversion
    from 0-n, put char to string[n]; then from n-2 to 1, put char.

7. Reverse Integer
    check result > INT_MAX/10, return 0 result <INT_MIN return 0; or result = result * 10 + x%10; x /=10;

8. String to Integer (atoi)
    1, result as long; 

9. Palindrome Number   
    if <0 return false; =0 return ture; reverse the number check they are ==;

10. Regular Expression Matching

11. Container With Most Water
    if values[lfet] < values[right] left++ else right--;

