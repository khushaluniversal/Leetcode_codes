/*
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 

Note:

1 <= words.length <= 2000
1 <= words[i].length <= 2000
Words will only consist of lowercase English letters.
Queries will only consist of lowercase English letters.
The number of queries is at most 40000.
*/

class TrieNode
{
    public:
        bool isWord;
        vector<TrieNode *> next;
        TrieNode():isWord(false),next(vector<TrieNode *>(26,NULL)){}
    
};
class Trie
{
    public:
        TrieNode *root = NULL;
    
        Trie()
        {
            root = new TrieNode();
        }
        void insert(string &word)
        {
            TrieNode *curr = root;
        
            for(int i = word.length()-1; i >= 0 ; i--)
            {
                int pos = word[i] - 'a';
                if(curr->next[pos] == NULL)
                    curr->next[pos] = new TrieNode();
            
                curr = curr->next[pos];
            }
            curr->isWord = true;
        }
    
        bool findword(string &word)
        {
            TrieNode *curr = root;
            for(int i = word.length()-1; i >= 0 ; i--)
            {
                int pos = word[i] - 'a';
                curr = curr->next[pos];
                if(curr == NULL)
                    return false;
            
                if(curr->isWord == true)
                    return true;
            }
            return false;
        }
};
class StreamChecker {
public:
    string stream = "";
    size_t maxLen = 0;
    Trie trie = Trie();
    StreamChecker(vector<string>& words) {
        for(auto word : words)
        {
            trie.insert(word);
            maxLen = max(maxLen,word.size());
        }
    }
    
    bool query(char letter) {
        stream += letter;
        
        if(stream.size() > maxLen)
            stream.erase(stream.begin());
        
        return trie.findword(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
