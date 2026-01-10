class Node {
public: 
    unordered_map<char, Node*> children;    //this map will store char and node pointer of children of current node
    bool endOfWord; //T - a word ends here, F - word does not end

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;

        for(int i=0; i<word.size(); i++) {
            if(temp->children.count(word[i]) == 0) {     //agar trie mai wo character exist nahi karta 
                temp->children[word[i]] = new Node();    //insert
            }
            temp = temp->children[word[i]];
        }

        temp->endOfWord = true;
    }
    
    bool search(string word) {
        Node* temp = root;

        for(int i=0; i<word.size(); i++) {
            if(temp->children.count(word[i])) {  //exists
                temp = temp->children[word[i]];
            } else {    //does not exists
                return false;
            }
        }

        return temp->endOfWord; //T-if exists
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;

        for(int i=0; i<prefix.size(); i++) {
            if(temp->children.count(prefix[i])) {
                temp = temp->children[prefix[i]];
            } else {
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */