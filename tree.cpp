#include <iostream>

class Node {
  public:
  char value;
  Node* bigger;
  Node* smaller;
  Node(char value) {
    this->value = value; 
    this->bigger = this->smaller = NULL;
  }
};

class Tree {
  Node* root;

  void _paint(Node* p) {
    std::cout << p->value;
    if (p->smaller || p->bigger) {
      std::cout << "(";
      if (p->smaller)
        this->_paint(p->smaller);
      else
        std::cout << "_";
      std::cout << ", ";
      if (p->bigger) 
        this->_paint(p->bigger);
      else
        std::cout << "_";
      std::cout << ")";
    }
  }

  void _add(Node* p, char value) {
    // std::cout << "_add" << std::endl;
    Node** t;
    if (value < p->value) {
      t = &p->smaller;
    } else {
      t = &p->bigger;
    }

    if((*t) == NULL)
      (*t) = new Node(value);
    else
      this->_add((*t), value);
  }

  bool _find(Node* p, char value) {
    if (p->value == value) {
      return true;
    }

    Node** t;
    if (value < p->value) {
      t = &p->smaller;
    } else {
      t = &p->bigger;
    }

    if ((*t) == NULL)
      return false;
    else
      return this->_find((*t), value);
  }
  
  public:
  Tree() {
    this->root = NULL;
  }

  void grow(std::string& in) {
    std::cout << "Growing a tree with seed: "<< in << std::endl;
    for(int i = 0; i < in.size(); i++) {
      this->add(in[i]);
    }
  }

  void paint() {
    // wild guess the starting padding
    std::string padding = "                                 ";
    if(this->root == NULL) {
      std::cout << "Earth. Sky.";
    }
    this->_paint(this->root);
    std::cout << std::endl;
  }

  void add(char value) {
    if(this->root == NULL) {
      this->root = new Node(value); 
    } else {
      this->_add(this->root, value);
    }
  }
 
  bool find(char value) {
    if(this->root == NULL)
      return false;

    return this->_find(this->root, value);
  }
};

int main() {
  std::string in = "abfskjrewklcxkjckjdsnfirenfreee";
  Tree* t = new Tree();
  t->grow(in);
  std::cout << "Painted tree: \n"; 
  t->paint();
  
  std::cout << "Did we find 'i' on the tree? \n";
  std::cout << (t->find("i"[0]) ? "yes": "no");
  std::cout << std::endl;

  std::cout << "Did we find 'g' on the tree? \n";
  std::cout << (t->find("g"[0]) ? "yes": "no");
  std::cout << std::endl;

  std::cout << "In-order: \n";
  t->in_order();



 
  // std::cout << "---------------" << std::endl;
  // std::string a = "lala";
  // std::cout << (int)33/2; 
  std::cout << std::endl;
}
