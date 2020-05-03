//
//  main.cpp
//  cpp832
//
//  Created by FAN ZHOU on 4/16/20.
//  Copyright © 2020 FAN ZHOU. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <list>
using namespace std;

struct compare {
    bool operator() (const int &lhs, const int &rhs) const{
        if (rhs - lhs < 0) return 1;
        if (rhs - lhs > 0) return 0;
        return 0;
    }
};

void print(set<int, compare> &tree){
    
    set<int>::iterator it = tree.begin();
    while (it!=tree.end()){
        
        cout << *it << endl;
        it ++ ;
    }
    
    
}
struct MyStruct {
  bool operator() (int i,int j) { return (i>j);}
} ;

class MyClass {
    public :
    bool operator() (int i,int j) { return (i>j); };
};

bool compfun (int i,int j) { return (i>j); };

int main(int argc, const char * argv[]) {
 
    set<int, compare> tree;
    tree.insert(2);
    tree.insert(10);
    tree.insert(6);
    tree.insert(8);
    tree.insert(12);
    MyClass myclass;
    MyStruct mystruct;
    
//    for (int x: tree){
//        cout << x << endl;
//    }
    
    vector<int> lnk;
    for (int i = 0; i < 10 ; i++)
        lnk.push_back(i);
    
    vector<int> :: iterator it = lnk.begin();
    it ++ ;
    it ++ ;
    cout << *(it) << endl;
    lnk.insert(it, 77);
    lnk.insert(it, 888);
    
    it = lnk.end();
    //it -- ;
    std::sort (lnk.begin(), it, mystruct);
    std::sort (lnk.begin(), it, myclass );
    for (int u: lnk){
        cout << u << ", ";
    }
    
    return 0;
}
