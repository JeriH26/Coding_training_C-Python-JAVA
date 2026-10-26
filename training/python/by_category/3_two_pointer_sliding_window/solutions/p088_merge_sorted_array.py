"""LeetCode 88: Merge Sorted Array.

Time: O(m + n)
Extra space: O(1)
"""


class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """Merge nums2 into nums1 in non-decreasing order."""
        i = m - 1          # Last real value in nums1.
        j = n - 1          # Last value in nums2.
        write = m + n - 1  # Last available position in nums1.

        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[write] = nums1[i]
                i -= 1
            else:
                nums1[write] = nums2[j]
                j -= 1
            write -= 1


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

    print("Python LeetCode 88 passed")


if __name__ == "__main__":
    run_tests()
