//You are given a string word and a non-negative integer k.

//Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.
//Example 1:

//Input: word = "aeioqq", k = 1

//Output: 0

//Explanation:

//There is no substring with every vowel.

//Example 2:

//Input: word = "aeiou", k = 0

//Output: 1

//Explanation:

//The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

//Example 3:

//Input: word = "ieaouqqieaouqq", k = 1

//Output: 3

//Explanation:

//The substrings with every vowel and one consonant are:
//Answer
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        auto f = [&](int k) -> long long {
            long long ans = 0;
            int l = 0, x = 0;
            unordered_map<char, int> cnt;
            auto vowel = [&](char c) -> bool {
                return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
            };
            for (char c : word) {
                if (vowel(c)) {
                    cnt[c]++;
                } else {
                    ++x;
                }
                while (x >= k && cnt.size() == 5) {
                    char d = word[l++];
                    if (vowel(d)) {
                        if (--cnt[d] == 0) {
                            cnt.erase(d);
                        }
                    } else {
                        --x;
                    }
                }
                ans += l;
            }
            return ans;
        };

        return f(k) - f(k + 1);
    }
};
word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".
 

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5
