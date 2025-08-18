class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words (ignores multiple spaces automatically)
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse words
        reverse(words.begin(), words.end());

        // Join words with space
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }

        return result;
    }
};
