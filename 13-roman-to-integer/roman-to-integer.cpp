class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int res = 0;
        int i = 0;
        int len = s.length();

        while(i<len){
            if(mp[s[i]] >= mp[s[i+1]]){
                res+=mp[s[i]];
                i++;
            } else {
                res+=mp[s[i+1]] - mp[s[i]];
                i+=2;
            }
        }

        return res;
    }
};