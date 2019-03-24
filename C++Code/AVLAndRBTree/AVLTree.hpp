#pragma once

template<class K, class V>
struct AVLTreeNode 
{
  struct AVLTreeNode<K, V>* _left;
  struct AVLTreeNode<K, V>* _right;
  struct AVLTreeNode<K, V>* _parent;

  K _key;
  V _value;
  int _bf;//平衡因子
  AVLTreeNode(const K& k, const V& v):_key(k),_value(v),_bf(0),_left(nullptr),_right(nullptr),_parent(nullptr)
  {}
};

template<class K, class V>
class AVLTree 
{
public:
  //typedef是在编译时处理的，需要知道具体的类型
  typedef struct AVLTreeNode<K, V> Node;
  AVLTree():_root(nullptr)
  {}

  ~AVLTree()
  {}

  bool Insert(const K& k, const V& v)
  {
    if (_root)
    {
      _root = new Node(k, v);
      return true;
    }
    
    Node* insert_node = new Node(k, v);
    Node* parent = nullptr;
    Node* cur = _root;
    while (cur)
    {
      if (cur->_key == k)
      {
        return false;//表示整个树中已经有这一个节点了，不需要在进行插入
      }
      else if (cur->_key < k)
      {
        //右子树
        parent = cur;
        cur = cur->_left;
      }
      else 
      {
        //左子树
        parent = cur;
        cur = cur->_right;
      }
    }
    //表示找到了插入的位置，进行插入
    if (parent->_key > k)
    {
      parent->_left = insert_node;
      insert_node->_parent = parent;
    }
    else 
    {
      parent->_right = insert_node;
      insert_node->_parent = parent;
    }

    //插入完毕之后需要判断这个数还是不是AVL树，如果不是的话需要进行调整
    //调整
    //1.插入的结点在parent的左边bf--,插入结点在parent的右边bf++
    //2.改变之后parent的bf==0，表示整个parent的树的高度没有改变，只是对于左子树或者右子树进行填充，所以更新结束
    //3.parent的bf的绝对值等于1，说明parent的高度改变了，继续向上更新
    //4.parent的bf的绝对值等于2，此时parent树已经不是AVL树了，进行旋转，将其变成AVL树
    
    //终止更新有三种情况：
    //1.更新到bf==0，高度没有改变
    //2.更新到|bf|==2，高度改变了需要进行旋转
    //3.更新到根节点，一直是|bf|==1，需要一直更新
    
    while (parent)
    {
      if (insert_node == parent->_right)
      {
        parent->_bf++;
      }
      else if (insert_node == parent->_left) 
      {
        parent->_bf--;
      }

      if (parent->_bf == 0)
      {
        break;
      }
      else if (abs(parent->_bf) == 1)
      {
        
      }
    }





  }

private:
  Node* _root;
};
