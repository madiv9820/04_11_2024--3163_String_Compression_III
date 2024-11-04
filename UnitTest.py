from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testCases = {
            1: ('abcde', '1a1b1c1d1e'),
            2: ('aaaaaaaaaaaaaabb', '9a5a2b')
        }
        self.__obj = Solution()
        return super().setUp()
    
    @timeout(0.5)
    def test_Case1(self):
        word, output = self.__testCases[1]
        result = self.__obj.compressedString(word = word)
        self.assertIsInstance(result, str)
        self.assertEqual(result, output)

    @timeout(0.5)
    def test_Case2(self):
        word, output = self.__testCases[2]
        result = self.__obj.compressedString(word = word)
        self.assertIsInstance(result, str)
        self.assertEqual(result, output)

if __name__ == '__main__':
    unittest.main()