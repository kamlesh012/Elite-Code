#include <bits/stdc++.h>
using namespace std;
//TRIE->
struct Node {
	struct Node * children[26] = {NULL};
	bool isEnd = false;
};

struct Node * getNode() {
	struct Node *newNode = new Node();
	for (int i = 0; i < 26; i++) {
		newNode->children[i] = NULL;
	}
	newNode->isEnd = false;
	return newNode;
};

struct Node* insert(struct Node *root, string s) {
	int n = s.length();
	struct Node* dumm = root;
	for (int i = 0; i < n; i++) {
		if (!dumm->children[s[i] - 'a']) {
			dumm->children[s[i] - 'a'] = getNode();
		}
		dumm = dumm->children[s[i] - 'a'];
	}
	dumm->isEnd = true;
	return root;
};

bool search(struct Node *root, string s) {
	int n = s.length();
	struct Node* dumm = root;
	for (int i = 0; i < n; i++) {
		if (!dumm->children[s[i] - 'a']) {
			return false;
		}
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
	//if trie is empty
	if (!root)return NULL;

	//Base case if reached end of string
	if (i == s.length()) {

		if (root->isEnd)root->isEnd = false;

		if (isEmpty(root)) {
			delete(root);
			return NULL;
		}
		return root;
	}

	root->children[s[i] - 'a'] = del(root->children[s[i] - 'a'], s, i + 1);

	//case if current node has only one chid &
	//that child of current root has been deleted(that's why root->isEnd=false)
	//if current node had a single child
	//and that child would not have been deleted then root->isEnd should have been true
	//or the node should have more than one child.
	//consider case of app & apple. for better understanding.

	if (isEmpty(root) && root->isEnd == false) {
		delete(root);
		return NULL;
	}
	return root;

	// del(root->children[s[i] - 'a'], s, i + 1);
	// root->isEnd = false;
	// delete root;
	// return NULL;
}
bool starts_with(Node *node, string s) {
	Node *curr = node;
	for (auto i : s) {
		if (!curr->children[i - 'a'])return false;
		curr = curr->children[i - 'a'];
	}
	return true;
}

int main()
{
	string keys[] = {"the", "a", "there",
	                 "answer", "any", "by",
	                 "bye", "their"
	                };

	int n = sizeof(keys) / sizeof(keys[0]);

	struct Node *root = getNode();

	// Construct trie
	for (int i = 0; i < n; i++)
		insert(root, keys[i]);


	// Search for different keys
	// search(root, "the") ? cout << "Yes\n" :
	// cout << "No\n";
	// search(root, "these") ? cout << "Yes\n" :
	// cout << "No\n";
	// search(root, "their") ? cout << "Yes\n" :
	// cout << "No\n";
	// search(root, "thaw") ? cout << "Yes\n" :
	// cout << "No\n";
	// root = del(root, "the", 0);
	// root = del(root, "their", 0);
	// root = del(root, "there", 0);

	search(root, "there") ? cout << "Yes\n" :
	                             cout << "No\n";

	starts_with(root, "the") ? cout << "Yes\n" :
	                                cout << "No\n";
	return 0;
}
