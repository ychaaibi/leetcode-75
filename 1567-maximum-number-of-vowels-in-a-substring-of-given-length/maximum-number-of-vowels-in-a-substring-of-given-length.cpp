class Solution {
public:
    string vowels;

    bool    is_vowel( char c )
    {
        return ( vowels.find( c ) != string::npos );  
    }
    
    int maxVowels(string s, int k) {
        vowels = "aeoiu";
        
        int curr = 0, ans = 0;
        
        for ( int i=0; i<k; i++ )
            curr += is_vowel(s[i]);
        ans = curr;
        
        for ( int i=k; i<s.length(); i++ )
        {
            curr = curr - is_vowel(s[i - k]) + is_vowel(s[i]);
            ans = max(curr, ans);
        }
        
        return ( ans );
    }
};