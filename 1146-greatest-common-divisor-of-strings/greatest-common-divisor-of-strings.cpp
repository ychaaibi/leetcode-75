class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int g = __gcd( str1.length(), str2.length() );
        
        string  ans = str1.substr(0, g);
        
        cout << ans << endl;
        string  s1, s2;
        
        s1.reserve( s1.length() );
        s2.reserve( s2.length() );

        for ( int i=0; i<str1.length() / g; i++ )
            s1 += ans;
        
        for ( int i=0; i<str2.length() / g; i++ )
            s2 += ans;
        
        if ( s1 == str1 and s2 == str2 )
            return ( ans );
        return ( "" );
    }
};