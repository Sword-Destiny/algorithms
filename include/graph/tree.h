//
// Created by yuanhao on 18-11-19.
//

#ifndef ALGORITHMS_TREE_H
#define ALGORITHMS_TREE_H

#include <list>

using std::list;

template<typename T>
/**
 * 树结构
 */
class tree {
public:
    T data;
    list<tree *> children;
    tree *parent;

public:
    /**
     * 这里p不能是const，因为那样的话p的children就不能添加新的节点了
     * @param dat
     * @param p
     */
    explicit tree(const T &dat, tree *p = NULL) : parent(p), data(dat), children() {
        if (p != NULL) {
            p->children.push_back(this);
        }
    }

    /**
     * 浅释放内存
     */
    virtual ~tree() = default;

    /**
     * 深复制
     */
    tree(const tree &t) : data(t.data), parent(NULL), children() {
        for (tree *child:t.children) {
            tree *c = child->deep_copy();
            c->parent = this;
            children.push_back(c);
        }
    }

    /**
     * 深复制
     */
    tree &operator=(const tree &t) {
        this->parent = NULL;
        this->data = t.data;
        this->children = list<T>();
        for (tree *child:t.children) {
            tree *c = child->deep_copy();
            c->parent = this;
            children.push_back(c);
        }
        return *this;
    }


public:

    /**
     * 递归释放内存
     */
    virtual void deep_release() const {
        for (tree *child:children) {
            child->deep_release();
        }
        delete this;
    }

    /**
     * 递归释放内存,并且可以为内部的data指定释放内存的函数
     */
    virtual void deep_data_release(void (*data_release)(T data)) const {
        for (tree *child:children) {
            child->deep_data_release(data_release);
        }
        data_release(data);
        delete this;
    }

    /**
     * 子节点相当于自己的深度，把自己视为root
     * @param child 子节点
     * @return 如果-1的话就是child不是自己的子节点
     */
    int depth(const tree *child) const {
        int n = 0;
        while (child != this) {
            if (child->parent == NULL) {
                return -1;
            }
            child = child->parent;
            n++;
        }
        return n;
    }

    /**
     * 深复制函数
     * 根节点的parent是不会复制的
     */
    tree *deep_copy() const {
        tree *res = new tree(data);
        for (tree *child:children) {
            tree *c = child->deep_copy();
            c->parent = res;
            res->children.push_back(c);
        }
        return res;
    }
};

#endif //ALGORITHMS_TREE_H
