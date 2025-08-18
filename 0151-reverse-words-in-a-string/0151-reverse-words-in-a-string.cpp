class Solution {
public:
    string trim(const string &s) {
        int start = s.find_first_not_of(" \t\n\r\f\v");
        if (start == string::npos) return "";
        int end = s.find_last_not_of(" \t\n\r\f\v");
        return s.substr(start, end - start + 1);
    }

    string reverseWords(string s) {
        string newS = trim(s);
        int size = newS.length();
        vector<string> store;
        int start = 0;

        for (int i = 0; i < size; i++) {
            if (newS[i] == ' ') {
                if (i > start) { // avoid multiple spaces
                    string word = newS.substr(start, i - start);
                    store.insert(store.begin(), word); // insert at front
                }
                start = i + 1;
            }
        }

        // Add last word
        if (start < size) {
            string word = newS.substr(start, size - start);
            store.insert(store.begin(), word);
        }

        // Join words with space
        string final = "";
        for (int i = 0; i < store.size(); i++) {
            final += store[i];
            if (i != store.size() - 1) final += " ";
        }

        return final;
    }
};
