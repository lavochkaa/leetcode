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

## Single Number (#136)
- Pattern: XOR all elements
- a ^ a = 0, a ^ 0 = a → pairs cancel out, single number remains
- one loop, one variable result = 0
- O(n) time, O(1) space

## Excel Sheet Column Title (#168)
- Pattern: convert number to base-26 (A=1...Z=26)
- i-- before % 26 — otherwise Z (26) causes extra iteration
- char = 'A' + i % 26 after i--
- result = char + result — prepend each character
- i /= 26 — move to next digit
- mistake: without i-- loop runs extra iteration when i is multiple of 26

## Majority Element (#169)
- Pattern: count with unordered_map
- pass 1: map[num]++ — count each number
- pass 2: pair.first = number, pair.second = count
- if (pair.second > nums.size() / 2) → found it
- auto& pair : map — auto ok when type is long and obvious from context

## Excel Sheet Column Number (#171)
- Pattern: reverse of #168, string → number
- c - 'A' + 1 → char to number (A=1, B=2, ... Z=26)
- result = result * 26 + digit — shift left by one digit
- iterate left to right (same as building decimal number)

## Valid Anagram (#242)
- Pattern: one unordered_map<char,int> + two passes
- Pass 1: map[c]++ for each char in s
- Pass 2: map[c]-- for each char in t, if map[c]==0 → return false
- At end: return true
- First check if (s.size() != t.size()) return false — otherwise extra chars in s go undetected
- Mistake: second loop over map.size() instead of string t — map.size() is unique char count, not string length
- Mistake: !map.empty() after loop — map is never empty, correct check is string lengths

## Summary Ranges (#228)
- Pattern: single pass + track range start
- When: group consecutive numbers into ranges
- start = nums[0], loop until size()-1 (last element handled after loop)
- if nums[i]+1 != nums[i+1] → range ended → push_back, update start = nums[i+1]
- after loop: add last range manually (compare start vs nums.back())
- single number: start == nums[i] → to_string(start)
- range: else → to_string(start) + "->" + to_string(nums[i])
- Mistake: return {result} instead of return result — wraps vector inside another vector
- Mistake: nums[0] without empty check → crash, add if (nums.empty()) return {}
- Mistake: after loop push_back only nums.back() — last range loses its start

## Contains Duplicate II (#219)
- Pattern: unordered_map<int,int> — number → last seen index
- When: duplicate exists within distance k
- If number in map: check i - map[num] <= k → return true
- If not or distance too large: update map[num] = i
- Mistake: did continue when distance > k — didn't update index, lost current position
- Mistake: map.insert(x, y) — wrong syntax, correct is map[x] = y

## Contains Duplicate (#217)
- Pattern: unordered_set for uniqueness check
- When: find any duplicate in an array
- set.count(x) → 1 if exists, 0 if not
- if count == 1 → duplicate found → return true
- if not → insert and continue
- return false after loop (no duplicates found)
- Mistake: swapped return true/false — if element is already in set, that IS the duplicate

## Isomorphic Strings (#205)
- Pattern: two unordered_maps for bidirectional character mapping
- When: verify one-to-one correspondence between characters
- Two maps: array[s[i]]=t[i] and map[t[i]]=s[i]
- For each character: if key exists → check value matches, else return false
- If key missing → record new mapping
- Two independent if/else blocks — one for each map
- Mistake: one map — misses case where two different s chars map to same t char
- Mistake: && instead of || — each check is independent, either false → return false
- Mistake: checking second map only inside first map's if — misses when s[i] is new but t[i] is already taken