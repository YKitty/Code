/**功能：对于huffman tree的创建
 * 使用了两个类，一个是节点类，一个是huffman tree树类
 * 对于创建huffman tree最终要实现一个加权路径最短
 * 所以每次都需要找到两个最小的结点来进行实现树
 * 所以采用堆排序来实现构建huffman tree 
 * 对于堆排序使用现存的优先级队列来实现 
 * 使用priority_queue来实现
 * 对于优先级队列必须自己写一个比较的虚函数
 * 如果不自己写的话，就会根据类型来比较，也就是比较结点，这样子就会出错
 * 所以要自己写一个只比较结点中的数据的虚函数
 */


#pragma once 

#include <iostream>
#include <queue>
#include <vector>

template <class W>
class HuffmanTreeNode
{
  HuffmanTreeNode<W>* _left;
  HuffmanTreeNode<W>* _right;
  W _w;
};

template <class W>
class HuffmanTree
{
  typedef  HuffmanTreeNode<W> Node;

public:
  HuffmanTree()
    : _root(NULL)
  {}

  struct NodeCompare
  {
    bool operator()(const Node*l, const Node* r)
    {
      l->_w > r->_w;
    }
  };

  HuffmanTree(W* w, size_t n)
  {
    //构建huffman tree
    //堆排序
    std::priority_queue<Node*, std::vector<Node*>, NodeCompare> minheap;
    for (size_t i = 0; i < n; i++)
    {
      minheap.push(new Node(w[i]));
    }

    while (minheap.size() > 1)
    {
      Node* left = minheap.top();
      minheap.pop();
      Node* right = minheap.top();
      minheap.pop();
      Node* parent = new Node(left->_w + right->_w);
      parent->_left = left;
      parent->_right = right;
      minheap.push(parent); 
    }

    _root = minheap.top();
  }

  ~HuffmanTree()
  {
    Destory(_root);
    _root = NULL;
  }

  void Destory(Node* root)
  {
    if (root == NULL)
    {
      return ;
    }
    Destory(root->_left);
    Destory(root->_right);
    delete _root;
  }

private:
  HuffmanTree(const HuffmanTree<W>& t);
  HuffmanTree<W>& operator=(const HuffmanTree<W>& t);

protected:
    Node* _root;
};
