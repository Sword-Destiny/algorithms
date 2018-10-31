//
// Created by 袁浩 on 2018/10/31.
//

#include <iostream>
using std::cout;
using std::endl;

#include "../../include/mid_level/segment_tree.h"

int main(){
    segment_tree<int> tree(10,2048);
    tree.update(5,3);
    cout << tree.query(1,10,0,0, 16) << endl;
}