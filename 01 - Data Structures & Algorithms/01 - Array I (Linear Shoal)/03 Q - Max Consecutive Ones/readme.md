# Max Consecutive Ones

## Problem Statement

Given a binary array `nums`, return the maximum number of consecutive `1`s in the array.

**Problem URL:** [Max Consecutive Ones - LeetCode](https://leetcode.com/problems/max-consecutive-ones/description/?envType=problem-list-v2&envId=dsa-linear-shoal-array-i)

---

## Problem Explanation

You are given an array containing only `0`s and `1`s. Your task is to find the longest continuous sequence (or "streak") of `1`s and return the length of that longest sequence. If there are multiple streaks of `1`s, you simply want to find out how many `1`s were in the largest one.

---

## Solution (C++)

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int prev = 0;
        int curr = 0;

        for(int i = 0; i < nums.size(); i++){
           if(nums[i] == 1) {
            curr++;
           }else{
            prev = max(prev, curr);
            curr = 0;
           }
        }

        return max(prev, curr);
    }
};

```

---

## Code Explanation

1. **Initialization:** We initialize two integer variables, `prev` and `curr`, to `0`.
* `curr` acts as a counter for the current active streak of `1`s.
* `prev` keeps track of the highest streak of `1`s we have encountered and finalized so far.


2. **Iteration:** We use a `for` loop to step through each element in the `nums` array.
* **If the element is `1`:** We increment our `curr` streak counter by `1`.
* **If the element is `0`:** This means our current streak of `1`s has broken. We update `prev` using the `max()` function to ensure it stores the largest streak found so far (comparing the existing `prev` to the newly finished `curr`). Finally, we reset `curr` to `0` to prepare for the next potential streak.


3. **Result:** After the loop finishes iterating through the array, it's possible a streak of `1`s was still ongoing at the very end without being interrupted by a `0` (and thus, `prev` was never updated for that final streak). Therefore, we return `max(prev, curr)` to guarantee we capture the absolute maximum.

### Example with Iterations

Let's trace the algorithm with the input: `nums = [1, 1, 0, 1, 1, 1]`

* **Initialization:** * `prev = 0`
* `curr = 0`


* **Loop Begins:** We iterate through each element.
* **Iteration 1 (Element `1`):** * Increment `curr`.
* `curr = 1`, `prev = 0`


* **Iteration 2 (Element `1`):** * Increment `curr`.
* `curr = 2`, `prev = 0`


* **Iteration 3 (Element `0`):** * Streak breaks! Update `prev = max(0, 2) = 2`. Reset `curr = 0`.
* `curr = 0`, `prev = 2`


* **Iteration 4 (Element `1`):** * Increment `curr`.
* `curr = 1`, `prev = 2`


* **Iteration 5 (Element `1`):** * Increment `curr`.
* `curr = 2`, `prev = 2`


* **Iteration 6 (Element `1`):** * Increment `curr`.
* `curr = 3`, `prev = 2`




* **Loop Ends:** We return `max(prev, curr)` which evaluates to `max(2, 3)`. The final output is `3`.

---

## Complexity Analysis

* **Time Complexity:** **O(n)**
* The `for` loop iterates through the array of `n` elements exactly once.
* The operations inside the loop (comparisons, increments, and `max()` function calls) all execute in **O(1)** constant time.
* Therefore, the total running time scales linearly with the size of the array, resulting in **O(n)**.


* **Space Complexity:** **O(1)**
* The memory used by the algorithm relies entirely on two integer variables (`prev` and `curr`), along with the loop counter `i`.
* Regardless of how large the input array `nums` gets, the amount of extra memory used remains exactly the same. Thus, the space complexity is **O(1)** constant space.
