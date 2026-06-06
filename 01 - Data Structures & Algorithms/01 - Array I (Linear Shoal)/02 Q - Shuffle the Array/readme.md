# Shuffle the Array

## Problem Statement

Given the array `nums` consisting of `2n` elements in the form `[x_1, x_2, ..., x_n, y_1, y_2, ..., y_n]`.

Return the array in the form `[x_1, y_1, x_2, y_2, ..., x_n, y_n]`.

**Problem URL:** [Shuffle the Array - LeetCode](https://leetcode.com/problems/shuffle-the-array/description/?envType=problem-list-v2&envId=dsa-linear-shoal-array-i)

---

## Problem Explanation

The goal of this problem is to take an array that is logically split into two halves—the first half containing `x` elements and the second half containing `y` elements—and perfectly interleave them. You want to pick the first element of the first half, then the first element of the second half, the second element of the first half, the second element of the second half, and so on until the entire array is shuffled together.

---

## Solution (C++)

```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
       vector<int> shuffle;
        
        int j = n;
        for(int i = 0; i < n; i++){
            shuffle.push_back(nums[i]);
            shuffle.push_back(nums[j]);
            j++;
        }
        
        return shuffle;
    }
};

```

---

## Code Explanation

1. **Initialization:** We create an empty integer vector named `shuffle` to hold our final interleaved result. We also initialize a pointer `j` to equal `n`. Because arrays are 0-indexed, index `n` represents the exact starting point of the second half (the `y` elements) of the original array.
2. **Iteration & Appending:** We use a `for` loop with an index `i` that starts at `0` and goes up to `n - 1`. This loop safely iterates through the entire first half of the array. During each iteration:
* We use `push_back()` to add `nums[i]` (the current `x` element) into our `shuffle` array.
* We immediately use `push_back()` to add `nums[j]` (the corresponding `y` element) into the `shuffle` array.
* We increment the `j` pointer (`j++`) so that in the next iteration, it points to the next `y` element.


3. **Result:** Once the loop finishes processing all `n` pairs, the `shuffle` vector contains all `2n` elements perfectly interleaved. We return this newly built array.

### Example with Iterations

Let's trace the algorithm with the input: `nums = [2, 5, 1, 3, 4, 7]` and `n = 3`.

* **Initialization:** * `shuffle` is empty: `[]`
* `j = 3` (pointing to the element `3`)


* **Loop Begins:** We iterate `i` from `0` to `2`.
* **Iteration 1 (`i = 0`):** * Push `nums[0]` (`2`) and `nums[3]` (`3`).
* Increment `j` to `4`.
* `shuffle` becomes `[2, 3]`


* **Iteration 2 (`i = 1`):** * Push `nums[1]` (`5`) and `nums[4]` (`4`).
* Increment `j` to `5`.
* `shuffle` becomes `[2, 3, 5, 4]`


* **Iteration 3 (`i = 2`):** * Push `nums[2]` (`1`) and `nums[5]` (`7`).
* Increment `j` to `6`.
* `shuffle` becomes `[2, 3, 5, 4, 1, 7]`




* **Loop Ends:** We return `shuffle`. The final output is `[2, 3, 5, 4, 1, 7]`.

---

## Complexity Analysis

* **Time Complexity:** **O(n)**
* The `for` loop runs exactly `n` times.
* Inside the loop, the vector `push_back()` method operates in **O(1)** amortized time.
* Therefore, the total time taken scales linearly with `n` (half the size of the array), simplifying to an overall time complexity of **O(n)**.


* **Space Complexity:** **O(n)**
* We allocate a new vector `shuffle` that stores exactly `2n` elements.
* Dropping the constant factor of `2`, the memory required grows linearly with the input size `n`, yielding a space complexity of **O(n)**. *(Note: If the output array itself is not counted toward auxiliary space—which is standard in many interview contexts—the space complexity would be considered **O(1)**).*
