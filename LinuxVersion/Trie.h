#ifndef TRIE_H
#define TRIE_H

#define MAX_WORD_LENGTH 31

template <class NodeType>
class TrieNode
{
public:
	NodeType *info;
	TrieNode<NodeType> *firstSon;
	TrieNode<NodeType> *rightBrother;
	int count;
	TrieNode();
	~TrieNode();
	void Clear();
};

template <class NodeType>
class Trie
{
public:
	TrieNode<NodeType> *root;
	Trie();
	~Trie();
	void insert(const NodeType *word, int length,int cnt);
	int find(const NodeType *word, int length);
	int match(const NodeType *word, NodeType *result,int length,int start);
};

template <class NodeType>
TrieNode<NodeType>::TrieNode()
{
	info = new NodeType;
	firstSon = NULL;
	rightBrother = NULL;
	count = 0;
}

template <class NodeType>
TrieNode<NodeType>::~TrieNode()
{

}

template <class NodeType>
void TrieNode<NodeType>::Clear()
{
	if (firstSon != NULL)
	{
		firstSon->Clear();
		delete firstSon;
	}
	if (rightBrother != NULL)
	{
		rightBrother->Clear();
		delete rightBrother;
	}
}


template <class NodeType>
Trie<NodeType>::Trie()
{
	root = new TrieNode<NodeType>;
}

template <class NodeType>
Trie<NodeType>::~Trie()
{
	root->Clear();
	delete root;
}

template <class NodeType>
void Trie<NodeType>::insert(const NodeType *word, int length,int cnt)
{
	TrieNode<NodeType>* currentNode = root;
	TrieNode<NodeType>* tmpNode = NULL;
	for (int i = 0; i < length; i++)
	{
		tmpNode = currentNode->firstSon;
		while (tmpNode != NULL)
		{
			if (*(tmpNode->info) == word[i]) break;
			tmpNode = tmpNode->rightBrother;
		}
		if (tmpNode == NULL)
		{
			tmpNode = new TrieNode<NodeType>();
			memcpy(tmpNode->info, &word[i], sizeof(NodeType));
			tmpNode->rightBrother = currentNode->firstSon;
			currentNode->firstSon = tmpNode;
		}
		currentNode = tmpNode;
	}
	currentNode->count+= cnt;
}

template <class NodeType>
int Trie<NodeType>::find(const NodeType *word, int length)
{
	TrieNode<NodeType>* currentNode = root;
	TrieNode<NodeType>* tmpNode = NULL;
	for (int i = 0; i < length; i++)
	{
		tmpNode = currentNode->firstSon;
		while (tmpNode != NULL)
		{
			if (*(tmpNode->info) == word[i]) break;
			tmpNode = tmpNode->rightBrother;
		}
		if (tmpNode == NULL)
		{
			return 0;
		}
		currentNode = tmpNode;
	}
	return currentNode->count;
}

//尽可能匹配到dict中最长的单词，返回值为下次匹配的起始点
template <class NodeType>
int Trie<NodeType>::match(const NodeType *word, NodeType *result,int length,int start)
{
	int end = start;

	TrieNode<NodeType>* currentNode = root;
	TrieNode<NodeType>* tmpNode = NULL;
	for (int i = start; i < length; i++)
	{
		tmpNode = currentNode->firstSon;
		while (tmpNode != NULL)
		{
			if (*(tmpNode->info) == word[i])	//找到了走下去的分支
			{
				if (tmpNode->count != 0)	//非0，表示能匹配上到当前的一部分
				{
					end = i+1;
				}
				break;
			}
			tmpNode = tmpNode->rightBrother;
		}
		if (tmpNode == NULL)	//没有分支可以走下去
		{
			//end为start表示没有任何可以匹配的结果
			if (end == start)
				return end;
			//否则，将匹配结果放入result中
			for (int j = start;j < end;j++)
				result[j-start] = word[j];
			result[end-start] = '\0';

			return end;
			//return false;
		}
		currentNode = tmpNode;
	}
	if (currentNode->count != 0)	//匹配结束，全部都匹配上
	{
		for (int j = start;j < length;j++)
			result[j-start] = word[j];
		result[length-start] = '\0';

		return end;
	}
	else
	{
		if (end == start)
			return end;
		//否则，将匹配结果放入result中
		for (int j = start;j < end;j++)
			result[j-start] = word[j];
		result[end-start] = '\0';
		return end;
	}
}

#endif
