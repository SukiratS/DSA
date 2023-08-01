

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

    bool search(TrieNode* root,string word) {
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

    bool search(string word) {
        return search(root, word);
    }
    void autoComplete(vector<string> input, string pattern) {
          
         

            for(int i=0;i<input.size();i++)
            {
                insertWord(input[i]);
            }

            bool ans=search(pattern);

          
          if(ans==true)
          {
               char c=pattern[pattern.size()-1];
               int index=c-'a';

               TrieNode* currentnode=root;

              
              for(int i=0;i<pattern.size();i++)
              {
                if (currentnode->children[pattern[i] - 'a'] != NULL) {
                  currentnode = currentnode->children[pattern[i] - 'a'];
                }
              }

              Butocomplete(currentnode, pattern);

          }

          else
            return;
    }

    void Butocomplete(TrieNode* current,string w)
    {
      if (current->isTerminal == true) {
       
        cout << w << endl;
      }

      char ch;

            for (int i = 0; i < 26; i++) {
              if (current->children[i] != NULL) {
              
              ch = i + 'a';

              Butocomplete(current->children[i], w + ch);
            }
            }

            
    }
};
