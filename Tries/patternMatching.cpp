#include <string>
#include <vector>

class TrieNode {
public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode*[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode* root, const std::string& word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    void insertWord(const std::string& word) {
        insertWord(root, word);
    }

    bool search(TrieNode* root, const std::string& word) {
        if (word.size() == 0) {
            return true;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
            return search(child, word.substr(1));
        }

        return false;
    }

    bool search(const std::string& word) {
        return search(root, word);
    }

   bool patternMatching(vector<string> vect, string pattern) {



        vector<string> suffix;

      for (int i1 = 0; i1 < vect.size(); i1++) {
    for (int p = vect[i1].size() - 1; p >= 0; p--) {
        string temp;
        for (int i = p; i < vect[i1].size(); i++) {
            temp = temp + vect[i1][i];
        }
        suffix.push_back(temp);
    }
}

   /*for(int i=0;i<vect.size();i++)
    {
        insertWord(vect[i]);
    }*/

    for (int p = 0; p < suffix.size(); p++) {
      insertWord(suffix[p]);
    }



        return search(pattern);
    }
};
