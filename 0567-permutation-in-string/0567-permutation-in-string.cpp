class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length()) {
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Frequency of s1
        for(int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }

        // First window
        int windowSize = s1.length();
        for(int i = 0; i < windowSize; i++) {
            freq2[s2[i] - 'a']++;
        }

        if(freq1 == freq2) {
            return true;
        }

        // Sliding Window
        for(int i = windowSize; i < s2.length(); i++) {

            // Add new character
            freq2[s2[i] - 'a']++;

            // Remove old character
            freq2[s2[i - windowSize] - 'a']--;

            // Compare
            if(freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};