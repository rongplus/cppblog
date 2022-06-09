    1, 179 big number { 1,9,10,5}
        return 95110
        translate to string,
        compare two string add, return "9"+"5" > "5" + "9"
    
    2, 1288 Remove covered intervals;
        Sort first then compare

    3, 622 Design Circular Queue  
        double link list

    4， 402 Remove K Digits - return smallest digits
        {1,2,4,5,1,9} k=2
        return 1219
        loop, if cur < pre, pop(pre)
        at the end, if len( digits)  >  all -k, remove the end

    5, Intersection of Two Linked Lists  160 [get the intersection point of two Linked Lists](https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/)
        after the intersection node, the two lists is equal,
        i, get the length of the two list,
        ii, loop the longger list to the position = longger-shorter
        iii, compare one by one till equal.

    6, 147,[Insertion Sort List](https://www.geeksforgeeks.org/insertion-sort/?ref=gcse)

    7, 280 Wiggle Sort
        even, odd position stratege

    8, 901 online stock span
        jump the days of the smaller digits.

    9, Word Pattern - Leetcode 290
        1, same length
        2, double equal.  charToWord[c] == w and wordToChar[w] ==c
        3, set value,charToWord[c] = w and wordToChar[w] =c

    10, Valid Perfect Square - Leetcode 367 
        half check
    
    11, 322 Coin Change - Dynamic Programming Bottom Up 
        sum(m)-->
            for coin in coins
                if coin < m
                    cion + sum(m-coin)
                else
                    return -1

    12 Find K Closest Elements - Leetcode 658 - Python

    13 Minimum Size Subarray Sum - Leetcode 209
        left=0, right =0;
        if total < target
            right ++
        else
            while total > target
                left ++

    14 Maximum Number of Balloons - Leetcode 1189

    15 Find All Numbers Disappeared in an Array - Leetcode 448
        use the num = nums[index] in the array to set the nums[num] = abs(nums[num]) *-1

    16 Open the Lock - Leetcode 752
        ? record turns, add dead turn to visited list

    17 Single Number - Leetcode 136
        using ^
        res = n ^ res

    18 Move Zeroes - Leetcode 283
        l =0;
        for r = (0-->n)
            if (nums[r]):
                swap(nums[l],nums[r])
                l+=1
    
    19 Delete and Earn - Dynamic Programming - Leetcode 740
        earn1, earn2,
        if (nums[i]==nums[i-1]+1)
            temp = earn2;
            earn2 = max(nums[i]+ eran1,earn2)
            earn1 = temp;
        else:
            temp = earn2;
            earn2 =  earn2+ nums[i]
            earn1 = temp;

    20 Rotting Oranges - Leetcode 994
        if (position) != 1(fresh)
            continue;
        only add new rotted to queue

    21 Matchsticks to Square - Leetcode 473
        i, only check 3 sides.
        ii, if sum > side length, go to next index
        iii, set current num = side length+1
        iii, if find one then go next.
        iv, (import) 
            (a) include current, go to next index. if find, return true, (not return if not find)
            (b) exclude curent , means reset the value and go to next index;   

    22 Integer Break - Dynamic Programming - Leetcode 343 -
        i, dp[1]=1
        ii if not the n, set dp[num] = num and then
           loop 2->num dp[num] = max(dp[num], dp[i]*dp[num-i])
        iii return dp[n]

    23 Find All Anagrams in a String - Leetcode 438
        slide window, move one position, remov s[l] and add s[r]

    24 Trim a Binary Search Tree - Leetcode 669 
        if root->val > high
            return trim(left);
        if root->val < low
            return trim(righ)
        
        root->left = trim(left)
        root->righ = trim(right)
        return root;

    25 Kth Largest Element in a Stream - Leetcode 703 
        min heap
        --> std::priority_queue<int,vector<int>, greater<int> > que; default is great to less,
        since we can only visit from top, do not use the default one

    26 Number of 1 Bits - Leetcode 191
        i, method one res+= n%2;n= n>>1
        ii method two n = n& (n-1), res++;

    27 Subtree of Another Tree - Leetcode 572 
        is same tree
        is sub tree;

    28 Integer to Roman - Leetcode 12
      and 900, 400, 90, 40, 9, 4 to list cases

    29 Maximum Product of the Length of Two Palindromic Subsequences - Leetcode 2002

    30 Length of Last Word - Leetcode 58 
        from last
        1, find last != ' ' get r;
        2, from r, get last = ' ', get l
        return r-l+1

    31 Longest Common Prefix - Leetcode 14 
        check this i is out of index or,  using the shortest one

    32 Balanced Binary Tree - Leetcode 110
        return max(left,right) if abs(left-ring) == 1 
        or -1 

    33 Pow(x, n) - X to the power of N - Leetcode 50

    34 Pascal's Triangle - Leetcode 118 
        i, append [] to result[][],
        ii,  grap result[n] as temp-2, insert 0 at begin and end
        iii, for 0 to temp.szie() add temp[m]+ temp[m+1], 

    35 Decode String - Leetcode 394


    36 Robot Bounded in Circle - Math & Geometry - Leetcode 1041
        dirX, dirY;
        when 'L"  swap(dirX,dirY), and dirX=-1* dirX;
        when 'R'  swap(dirX,dirY), and dirY=-1* dirY;

    37 Combination Sum II - Backtracking - Leetcode 40

    38 Unique Length-3 Palindromic Subsequences 
        middle, left and right set have same character.

    39 Valid Sudoku - Amazon Interview Question - Leetcode 36
        loop all items
            if not dup:
                add to rows[][]
                add to cols[][]
                add to squares[r%3][c%3]
            else
            return false

    40 Eliminate Maximum Number of Monsters - Leetcode 1921 
        get react time,
        from 0->n;
            if time > reachtime
                return;
            ++ count；

    41   289

    42 Maximum Alternating Subsequence Sum - Dynamic Programming - Leetcode 1911 
        --> not done

    43 Design Min Stack - Amazon Interview Question - Leetcode 155
        one stack (FILO) to cashe the value
        another stack(FILO) to cashe min value at this position

    44 Walls and Gates - Multi-Source BFS - Leetcode 286 
        BFS ---> 同时， 然后，如果不是空， 就停
            tips: 用一个统一的dist，避免访问之前的room to check dist.

    45 Linked List Cycle - Floyd's Tortoise and Hare - Leetcode 141 
        using 2 pointers, fast and slow pointers.

    46 Find the Duplicate Number - Floyd's Cycle Detection - Leetcode 287
    