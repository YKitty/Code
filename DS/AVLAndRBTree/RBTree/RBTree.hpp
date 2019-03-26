#pragma once 

#include <iostream>

enum color 
{
  RED,
  BLACK
};

template<class K, class V>
struct  RBTreeNode 
{
  struct RBTreeNode<K, V>* _left;
  struct RBTreeNode<K, V>* _right;
  struct RBTreeNode<K, V>* _parent;

  K _key;
  V _value;
};

template<class K, class V>
class RBTree 
{
public:
  typedef struct RBTreeNode<K, V> Node;
  RBTree():_root(nullptr)
  {}

  ~RBTree()
  {}

  bool Insert(const K& key, const V& value)
  {
    //按照搜索树的规则进行插入   
    if (_root == nullptr) 
    {
      Node* tmp = new Node(key, value);
      _root = tmp;
      return true;
    }

    Node* parent = nullptr;
    Node* cur = _root;
    Node* insert_node = new Node(key, value);
    while (cur)
    {
      if (cur->_val == key)
      {
        return true;
      }
      else if (cur->_val > key)
      {
        parent = cur;
        cur = cur->_left;
      }
      else 
      {
        parent = cur;
        cur = cur->_right;
      }
    }

    if (parent->_key > key)
    {
      parent->_left = insert_node;
      insert_node->_parent = parent;
    }
    else 
    {
      parent->_right = insert_node;
      insert_node->_parent = parent;
    }
  }
private:
  Node* _root;
};
