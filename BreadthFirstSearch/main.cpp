//
//  main.cpp
//  BreadthFirstSearch
//
//  Created by adeeb mohammed on 15/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
// breadth first search algorithm,
// based on queue a node and its child is inserted into the array
// here the class nodes contains the tree
// the time complexity of the algorithm is o(v+e) the space complexity is o(v)

#include <iostream>
#include <vector>
#include <string>
#include <deque>

class Node {
public:
  std::string name;
  std::vector<Node *> children;
  Node(std::string str) { name = str; }

  std::vector<std::string> breadthFirstSearch(std::vector<std::string> *array) {
      std::deque<Node *> queue{this};
      while(!queue.empty()){
          Node current = *queue.front();
          queue.pop_front();
          array->push_back(current.name);
          for(int i = 0; i < current.children.size(); i++){
              queue.push_back(current.children[i]);
          }
      }
    
      return *array;
  }

  Node *addChild(std::string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};


int main(int argc, const char * argv[]) {

    std::cout << "BreadFirst Search Algorithm implemented\n";
    return 0;
}
