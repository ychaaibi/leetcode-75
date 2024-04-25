class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> hash1(26,0), hash2(26,0);
        
        if ( word1.length() != word2.length() )
            return ( false );
        
        for ( int i=0; i<word1.length(); i++ )
            hash1[word1[i] - 'a']++, hash2[word2[i] - 'a']++;
        
        for ( int i=0; i<26; i++ )
            if ( (!hash1[i] and hash2[i]) or (hash1[i] and !hash2[i]))
                return ( false );
        
        sort(hash1.begin(), hash1.end());
        sort(hash2.begin(), hash2.end());
        
        for ( int i=0; i<26; i++ )
            if ( hash1[i] != hash2[i] )
                return ( false );
        
        return ( true );
    }
};