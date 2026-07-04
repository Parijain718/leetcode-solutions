class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return 0;
        bool negative = num < 0;
        if(negative)
            num = -num;
        string s = to_string(num);
        if(negative){
            sort(s.begin(),s.end(),greater<char>());
            return -stoll(s);
        }
        sort(s.begin(),s.end());
        int i = 0;
        while(i < s.size() && s[i] == '0')
            i++;
        if( i < s.size())
            swap(s[0],s[i]);
        return stoll(s);
    }
};