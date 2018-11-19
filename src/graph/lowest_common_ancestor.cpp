//
// Created by yuanhao on 18-11-19.
//

#include "../../include/graph/lowest_common_ancestor.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    // 当你要为节点添加子节点的时候不能为const，叶子节点才可以为const
    tree<int> *root = new tree<int>(1);
    tree<int> *t2 = new tree<int>(2, root);
    tree<int> *t3 = new tree<int>(3, t2);
    const tree<int> *t4 = new tree<int>(4, t3);
    tree<int> *t5 = new tree<int>(5, t3);
    const tree<int> *t6 = new tree<int>(6, t5);
    const tree<int> *toor = new tree<int>(0);

    cout << lowest_common_ancestor(root, t4, t6)->data << endl; // 3
    cout << lowest_common_ancestor(root, t5, t6)->data << endl; // 5
    cout << lowest_common_ancestor(root, t5, toor) << endl; // 0 (NULL)

    root->release();
    toor->release();

    return 0;
}