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