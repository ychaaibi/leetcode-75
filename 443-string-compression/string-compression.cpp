class Solution {
public:
    int compress(vector<char>& chars) {
        int p1=0, p2=0, modif=0;
        
        while ( p2 < chars.size() )
        {
            if ( chars[p2] == chars[p1] )
                p2++;
            
            if ( p2 == chars.size() or chars[p2] != chars[p1] )
            {
                chars[modif++] = chars[p1];
                
                if ( p2 - p1 > 1 )
                {
                    string num = to_string(p2 - p1);
                    for ( int i=0; i<num.length(); i++ )
                        chars[modif++] = num[i];
                }
                p1 = p2;
            }
        }
        
        return ( modif );
    }
};