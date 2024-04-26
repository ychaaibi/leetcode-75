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
    
    bool startsWith(string prefix) {
        Trie* curr = this;

        for ( int i=0; i<prefix.length(); i++ )
        {
            if (!curr->alpha[prefix[i] - 'a'])
                return ( false );
            
            curr = curr->alpha[prefix[i] - 'a'];
        }

        return ( true );
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */