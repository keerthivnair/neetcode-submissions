class PrefixNode {
    public:
    PrefixNode* children[26];
    bool isEndOfWord;
    PrefixNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEndOfWord = false;
    }
};

class PrefixTree {
    PrefixNode* root;
public:
    PrefixTree() {
        root = new PrefixNode();
    }
    
    void insert(string word) {
        PrefixNode* curr = root;
        for(char c: word) {
            int idx = c-'a';
            if(!curr->children[idx]) curr->children[idx] = new PrefixNode();
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        PrefixNode* curr = root;
        for(char c:word) {
            int idx = c-'a';
            if(!curr->children[idx]) return false;
            curr=curr->children[idx];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        PrefixNode* curr = root;

    for(char c : prefix) {

        int idx = c - 'a';

        if(!curr->children[idx]) {
            return false;
        }

        curr = curr->children[idx];
    }

    return true;
    }
};
