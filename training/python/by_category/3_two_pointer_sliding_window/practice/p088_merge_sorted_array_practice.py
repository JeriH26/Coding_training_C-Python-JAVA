"""LeetCode 88 practice: merge nums2 into nums1 in place.

Rules:
- Do not return a new list.
- Do not call sort().
- Use three indexes and fill nums1 from right to left.
"""


class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        i = m - 1
        j = n - 1
        write = m + n - 1

        # TODO: While nums2 still has unmerged values:
        # 1. Compare nums1[i] and nums2[j].
        # 2. Write the larger value into nums1[write].
        # 3. Move the indexes that were used.
        raise NotImplementedError("TODO: implement LeetCode 88")


def run_tests() -> None:
    cases = [
        ([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3, [1, 2, 2, 3, 5, 6]),
        ([1], 1, [], 0, [1]),
        ([0], 0, [1], 1, [1]),
        ([2, 0], 1, [1], 1, [1, 2]),
    ]

    for nums1, m, nums2, n, expected in cases:
        Solution().merge(nums1, m, nums2, n)
        assert nums1 == expected, (nums1, expected)

    print("Python LeetCode 88 practice passed")


if __name__ == "__main__":
    run_tests()
