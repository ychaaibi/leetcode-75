class Solution {
public:
    string reverseWords(string s) {
        string ans;
        
        ans.reserve(s.length());
        
        reverse(s.begin(), s.end());
        
        for ( int i=0; i<s.length(); )
        {
            if ( s[i] == ' ' )
            {
                i++;
                continue ;
            }
            
            int p1 = i;
            
            for ( ;i < s.length() and s[i] != ' '; i++ );
            
            reverse(s.begin() + p1, s.begin() + i);
        }
        
        for ( int i=0; i<s.length(); i++ )
        {
            if ( s[i] == ' ' and ( !i  or s[i - 1] == ' ' ) )
                continue ;
            ans.push_back( s[i] );
        }
        
        if ( ans.back() == ' ' )
            ans.pop_back();
        
        return ( ans );
    }
};