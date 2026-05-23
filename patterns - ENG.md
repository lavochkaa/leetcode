## Roman to Integer (#13)
- Mistake: overcomplicated condition (val == 1 || val == 10 || val == 100)
- Fix: just if (val < val_next) is enough

## Longest Common Prefix (#14)
- Mistake: result += symbol inside inner loop — added symbol once per matching word instead of once per position
- Fix: move result += symbol after the inner loop

## Valid Parentheses (#20)
- Pattern: Stack + Hash Map
- When: checking pairs (brackets, tags, nesting)
- Opening → push, closing → compare with top() → pop()
- Mistake: forgot to check stack.empty() before top() — condition order matters

## Find the Index (#28)
- Pattern: Substr + Iteration
- When: searching for a substring in a string
- Mistake: created an unnecessary inner loop, substr already handles comparison

## Search Insert Position (#35)
- Pattern: Binary Search
- When: sorted array + finding element/position
- How: mid = (left + right) / 2, compare nums[mid] with target
  - less → left = mid + 1
  - greater → right = mid - 1
  - equal → return mid
- After while → return left (insertion position)
- Mistake: while (left < right) instead of while (left <= right) — missed the case when left == right
- Mistake: recalculated mid in two places instead of once at the start of the loop

## Length of Last Word (#58)
- Pattern: iterate from end of string
- When: need to find something at the end of a string
- Mistake: s.size() returns unsigned — on empty string s.size()-1 overflows → use (int)s.size()-1
- Mistake: while loop without checking i >= 0 before s[i] — condition order matters

## Plus One (#66)
- Pattern: reverse iteration with carry
- When: arithmetic on array of digits
- How: digits[i]++ → if < 10 return → else set 0, continue
- After loop: insert(begin(), 1) for case [9,9,9] → [1,0,0,0]
- Learned: cout can't print vector directly, use range-based for

## Add Binary (#67)
- Pattern: two pointers from end + carry
- when: adding numbers represented as strings
- s[i] - '0' → convert char to digit (otherwise you get ASCII value)
- sum % 2 → current bit, sum / 2 → carry
- result = digit + result → build from end, prepend each digit
- after loop: if (carry) result = "1" + result
- mistake: nested loops = multiplication, not addition
- mistake: accessing a[i] when i < 0 — always check if (i >= 0) first

## Merge Sorted Array (#88)
- Pattern: three pointers from end
- when: merging two sorted arrays in-place
- idea: compare from end, write larger to end of nums1
- if i < 0 → take from nums2, if j < 0 → take from nums1
- mistake: break when one array ends — need continue with remaining
- mistake: k-- inside each if instead of once after assignment

## Pascal's Triangle (#118)
- Pattern: build each row from previous row
- structure: vector<vector<int>>
- each row size i+1, filled with ones
- middle: row[j] = result[i-1][j-1] + result[i-1][j]
- inner loop from j=1 to j<i (edges stay 1)
- mistake: push_back before filling middle — pushes old version
- mistake: j < i-1 instead of j < i — last middle element not filled

## Pascal's Triangle II (#119)
- same as 118 but return single row by index
- loop until i <= rowIndex (not i < rowIndex)
- push_back outside if block — otherwise rows 0 and 1 never added
- return result[rowIndex]

## Best Time to Buy and Sell Stock (#121)
- Pattern: single pass + track minimum
- min_price = prices[0], max_profit = 0
- each step: update min, then compute prices[i] - min
- return max(0, max_profit)
- mistake: else if for min — only one updated per step
- mistake: max_profit not initialized to 0 — wrong starting value

## Valid Palindrome (#125)
- Pattern: two pointers + pre-filter string
- isalnum(c) → letter or digit? tolower(c) → lowercase
- filter into new string first, then two pointers i and j
- i < j — loop condition (not i <= j, middle element skipped)
- mistake: compared s[i] instead of sorted[i]
- mistake: j++ instead of j-- — pointers must move toward each other