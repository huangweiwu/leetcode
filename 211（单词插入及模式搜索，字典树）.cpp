class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode() {
        isKey = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class WordDictionary {
private:
	TrieNode* root;
public:
	WordDictionary() {
		root = new TrieNode();
	}
    // Adds a word into the data structure.
    void addWord(string word) {
		TrieNode* cur = root;
		for(int i=0; i<word.length(); i++) {
			if(!cur->children[word[i] - 'a'])
				cur->children[word[i] - 'a'] = new TrieNode();
			cur = cur->children[word[i] - 'a'];
		}
		cur->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelp(0, word, root);
    }

	bool searchHelp(int pos, string word, TrieNode* root) {
		TrieNode* cur = root;
		for(int i=pos; i<word.length(); i++) {
			if(cur && word[i] != '.')
				// 不等于'.'，直接往下移
				cur = cur->children[word[i] - 'a'];
			else if(cur && word[i] == '.') {
				// 等于'.'，需要遍历26个孩子
				TrieNode* tmp = cur;
				for(int j=0; j<26; j++) {
					cur = tmp->children[j];
					if(searchHelp(i+1, word, cur))
						return true;
				}
			}
			else
				break;
		}
		return cur && cur->isKey;
	}
};

int main() {
	//Solution so;
	WordDictionary w;
	w.addWord("ab");
	w.search("a.");
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	ListNode* headA = new ListNode(3);
	ListNode* headB = new ListNode(2);
	headB->next = headA;
	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {1, 2, 3, 4, 5};
	vector<int> v(a, a+5);
	unordered_map<char, int> m;
	
	system("pause");
	return 0;
}