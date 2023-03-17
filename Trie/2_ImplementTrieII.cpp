#include <bits/stdc++.h> 
struct Node {
	struct Node * children[26] = {NULL};
	int isEnd = 0;
};

struct Node * getNode() {
	struct Node *newNode = new Node();
	for (int i = 0; i < 26; i++) {
		newNode->children[i] = NULL;
	}
	newNode->isEnd = 0;
	return newNode;
};

struct Node* insertnode(struct Node *root, string s) {
	int n = s.length();
	struct Node* dumm = root;
	for (int i = 0; i < n; i++) {
		if (!dumm->children[s[i] - 'a']) {
			dumm->children[s[i] - 'a'] = getNode();
		}
		dumm = dumm->children[s[i] - 'a'];
	}
	(dumm->isEnd)++;
    return root;
};

int search(struct Node *root, string s) {
	int n = s.length();
	struct Node* dumm = root;
	for (int i = 0; i < n; i++) {
		if (!dumm->children[s[i] - 'a']) {
			return 0;
		dumm = dumm->children[s[i] - 'a'];
	}
	return dumm->isEnd;
}

bool isEmpty(struct Node *root) {
	for (int i = 0; i < 26; i++) {
		if (root->children[i])return false;
	}
	return true;
}

struct Node * del(struct Node *root, string s, int i) {

	if (!root)return NULL;

	if (i == s.length()) {

		if (root->isEnd){
            (root->isEnd)--;
        }
  
		if (isEmpty(root) && !root->isEnd) {
      //delete current node only if any other node does not end here. & current node has no children
			delete(root);
			return NULL;
		}
		return root;
	}

	root->children[s[i] - 'a'] = del(root->children[s[i] - 'a'], s, i + 1);

	if (isEmpty(root) && root->isEnd==0) {
		delete(root);
		return NULL;
	}
	return root;
}

int starts_with(Node *node, string s) {
	Node *curr = node;
	for (auto i : s) {
		if (!curr->children[i - 'a'])return 0;
		curr = curr->children[i - 'a'];
	}
    int ans=0;
    ans=curr->isEnd;
    for(char c='a';c<='z';c++){
        if(curr->children[c-'a']){
            ans=ans+starts_with(curr->children[c-'a'],"");
            }
    }
	return ans;
}

class Trie{
    private:
    Node* root;

    public:

    Trie(){
        root=getNode();
    }

    void insert(string &word){
        root=insertnode(root,word);
    }

    int countWordsEqualTo(string &word){
        return search(root,word);
    }

    int countWordsStartingWith(string &word){
        return starts_with(root,word);
    }

    void erase(string &word){
        Node * dummy=root;
        del(dummy,word,0);

    }
};
