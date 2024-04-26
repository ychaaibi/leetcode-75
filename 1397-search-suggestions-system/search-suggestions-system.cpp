class Solution {
private:
class Trie {
public:
    vector<Trie*>   alpha;
    bool            end;

    Trie() {
        end = false;

        alpha.resize( 26, NULL );
    }
    
    void insert(string word) {
        Trie* curr = this;

        for ( int i=0; i<word.length(); i++ )
        {
            if ( !curr->alpha[word[i] - 'a'] )
                curr->alpha[word[i] - 'a'] = new Trie();

            curr = curr->alpha[word[i] - 'a'];
        }

        curr->end = true;
    }
    
    bool search(string word) {
        Trie* curr = this;

        for ( int i=0; i<word.length(); i++ )
        {
            if (!curr->alpha[word[i] - 'a'])
                return ( false );
            
            curr = curr->alpha[word[i] - 'a'];
        }

        return ( curr->end );
    }
    
    void    startsWith(string& prefix, vector<string>& ans, string& curr, Trie* system, int index ) {
        if ( ans.size() >= 3 )
            return ;

        if ( index < prefix.length() and !system->alpha[ prefix[index] - 'a' ] )
            return ;

        if ( index < prefix.length() )
        {
            startsWith( prefix, ans, curr, system->alpha[prefix[index] - 'a'], index + 1 );
            return ;
        }

       if ( system->end )
            ans.push_back( curr );

        for ( int i=0; i<26; i++ )
        {
            if ( !system->alpha[i] )
                continue ;
            curr.push_back( i + 'a' );
            startsWith( prefix, ans, curr, system->alpha[i], index + 1);
            if ( ans.size() >= 3 )
                return ;
            curr.pop_back( );
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* system_complet = new Trie();

        vector<vector<string>>  ans( searchWord.length() );

        sort( products.begin(), products.end() );

        for ( int i=0; i<products.size(); i++ )
            system_complet->insert( products[i] );

        for ( int i=0; i<searchWord.length(); i++ )
        {
            string prefix = searchWord.substr( 0, i + 1 );
            string curr = prefix;

            system_complet->startsWith( prefix, ans[i], curr, system_complet, 0 );
        }

        return ( ans );
    }
};