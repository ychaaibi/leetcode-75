class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        size_t  gcd = __gcd(str1.length(), str2.length());
        string  s = str1.substr(0, gcd);

        for (size_t i = 0; i<str1.length(); i += s.length())
            if (str1.compare(i, gcd, s) != 0)
                return ("");
        
        for (size_t i = 0; i<str2.length(); i += s.length())
            if (str2.compare(i, gcd, s))
                return ("");

        return (s);
    }
};