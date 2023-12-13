def second_largest(nums):
    def _max(lo, hi, seq):
            if lo >= hi:
                return seq[lo], []
            mid = lo + (hi - lo) // 2
            x, a = _max(lo, mid, seq)
            y, b = _max(mid + 1, hi, seq)

            if x > y:
                a.append(y)
                return x, a
            b.append(x)
            return y, b

    comparisons = _max(0, len(nums) - 1, nums)[1]
    return _max(0, len(comparisons) - 1, comparisons)[0]

nums = [6, 8, 3, 12, 5, 1]
print(second_largest(nums))
