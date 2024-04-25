class Solution {
public:
    string vowels;
    
    bool is_vowel( char c )
    {
        return ( vowels.find(c) != string::npos );
    }
    
    string reverseVowels(string s) {
        vowels = "aeiouAEIOU";
        
        int p1=0, p2=s.length() - 1;
        
        while ( p1 < p2 )
        {
            if ( !is_vowel(s[p1]) )
                p1++;
            else if ( !is_vowel(s[p2]) )
                p2--;
            else
                swap( s[p2--], s[p1++] );
        }
        return ( s );
    }
};