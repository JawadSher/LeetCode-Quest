# Concatenation of Array

## Problem Statement

Given an integer array `nums` of length $n$, you want to create an array `ans` of length $2n$ where $ans[i] == nums[i]$ and $ans[i + n] == nums[i]$ for $0 \le i < n$ (0-indexed).

Specifically, `ans` is the concatenation of two `nums` arrays. Return the array `ans`.

**Problem URL:** [Concatenation of Array - LeetCode](https://leetcode.com/problems/concatenation-of-array/?envType=problem-list-v2&envId=dsa-linear-)

---

## Solution (C++)

```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums);
        
        for(int num : nums){
            ans.push_back(num);
        }

        return ans;
    }
};

```

---

## Explanation

The goal of the problem is to duplicate the given array and append it to itself.

1. **Initialization:** The solution leverages C++ vector constructors by initializing the `ans` vector with the exact same elements as the input `nums`. At this stage, `ans` is simply a copy of `nums`.
2. **Iteration & Appending:** We use a range-based for loop to iterate through every element `num` in the original `nums` array. For each element, we use the `push_back()` method to append it to the end of our `ans` vector.
3. **Result:** Because we iterate through `nums` from start to finish and append each element to `ans` (which already contains one full copy of `nums`), `ans` perfectly becomes the concatenation of `nums` with itself.

### Example with Iterations

Let's trace the algorithm with an example input: `nums = [1, 2, 1]`

* **Initialization:** `ans` is initialized as a copy of `nums`.
* `ans = [1, 2, 1]`


* **Loop Begins:** We iterate over each element in `nums = [1, 2, 1]`.
* **Iteration 1:** The first element is $1$. We push $1$ to `ans`.
* `ans` becomes `[1, 2, 1, 1]`


* **Iteration 2:** The second element is $2$. We push $2$ to `ans`.
* `ans` becomes `[1, 2, 1, 1, 2]`


* **Iteration 3:** The third element is $1$. We push $1$ to `ans`.
* `ans` becomes `[1, 2, 1, 1, 2, 1]`




* **Loop Ends:** We return `ans`. The final output is `[1, 2, 1, 1, 2, 1]`.

---

## Complexity Analysis

* **Time Complexity:** $O(n)$
* Initializing the `ans` vector with `nums` takes $O(n)$ time.
* The `for` loop iterates through the `nums` array exactly once, which takes $O(n)$ time.
* Appending an element to a vector using `push_back()` takes $O(1)$ amortized time.
* Overall time complexity: $O(n) + O(n) = O(n)$, where $n$ is the length of the input array `nums`.


* **Space Complexity:** $O(n)$
* We create a new vector `ans` to store the result, which will eventually hold $2n$ elements.
* Excluding the space required for the output array (which is standard practice), the auxiliary space is $O(1)$. However, strictly speaking, the memory we allocate scales linearly with the input, resulting in an overall space complexity of $O(n)$.
