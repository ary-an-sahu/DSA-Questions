class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequencies
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        string result = "";
        // Step 2: Repeatedly pick max frequency char
        while (!freq.empty()) {
            // find char with max frequency (O(n) each time)
            char maxChar;
            int maxFreq = 0;
            for (auto &p : freq) {
                if (p.second > maxFreq) {
                    maxChar = p.first;
                    maxFreq = p.second;
                }
            }

            // Step 3: Append maxChar maxFreq times
            result.append(maxFreq, maxChar);

            // Step 4: Remove this char from map
            freq.erase(maxChar);
        }

        return result;
    }
};
