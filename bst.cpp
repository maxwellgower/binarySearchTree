/********************************* FILE  INFO *********************************/
// Name: Max Gower  Z#: Z23637403
// Course: Data Structures and Algorithm Analysis COP3530: Dr. Lofton Bullard
// Due Date: Tuesday, August 3rd    Due Time: 11:59 PM
// Total Points: 100    Assignment 11: Binary Search Tree Program

// Description: Implementation of Class bst
/******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "bst.h"

using namespace std;

/******************************* CONSTRUCTORS *********************************/

bst::bst() {
    root = nullptr;
}

/******************************** DESTRUCTORS *********************************/

bst::~bst() = default;

/********************************* ACCESSORS **********************************/

bool bst::empty() {
    return (root == nullptr);
}

void bst::sorted_info() {
}

void bst::sorted_info(ostream&, treenode*&) {
    ofstream info("county_info.txt");
    ifstream file("country_data.txt");
    string s;
    getline(file, s);
    while (getline(file, s)) {
        cout<<s;
        stringstream ss;
        ss<<s;
        double census = root->population_size;
        string county = root->county_name;
        ss>>county>>census;
        ss.clear();
    }
}

treenode* bst::search_tree(string item) {
    return search_tree(root, item);
}

treenode* bst::search_tree(treenode* loc_ptr, string item) {
    if (loc_ptr != nullptr) {
        if (loc_ptr->county_name == item)
            return loc_ptr;
        else if (loc_ptr->county_name>item)
            return search_tree(loc_ptr->lchild, item);
        else
            return search_tree(loc_ptr->rchild, item);
    }
    else
        return loc_ptr;
}

void bst::print_tree() {
    print_tree(root);
}

void bst::print_tree(treenode*& loc_ptr) {

    if (loc_ptr != nullptr) {
        print_tree(loc_ptr->lchild);
        cout<<loc_ptr->county_name<<endl;
        print_tree(loc_ptr->rchild);
    }
}

void bst::county_ranges(const string& min, const string& max) {

}

void bst::county_ranges(treenode*&,const string& min,const string& max) {

}

treenode* bst::inorder_succ(treenode* loc_ptr) {
    treenode* ptr = loc_ptr->rchild;
    while (ptr->lchild != 0) {
        ptr = ptr->lchild;
    }
    return ptr;
}

/********************************* MUTATORS ***********************************/

void bst::insert(const string& item, const double& population) {
    insert(root, item, population);
}

void bst::insert(treenode*& ptr,const string& item,const double& population) {
    if (ptr == nullptr) {
        ptr = new treenode;
        ptr->lchild = ptr->rchild = nullptr;
        ptr->county_name = item;
    }
    else if (ptr->county_name>item)
        insert(ptr->lchild, item, population);
    else if (ptr->county_name<item)
        insert(ptr->rchild, item, population);
    else
        cout<<"the item is already in the tree\n";
}

void bst::del_name(string item) {
    del_name(root, item);
}

void bst::del_name(treenode*& loc_ptr, string item) {
    if (loc_ptr == nullptr)
        cout<<"item not in tree\n";
    else if (loc_ptr->county_name>item)
        del_name(loc_ptr->lchild, item);
    else if (loc_ptr->county_name<item)
        del_name(loc_ptr->rchild, item);
    else {
        treenode* ptr;
        if (loc_ptr->lchild == nullptr) {
            ptr = loc_ptr->rchild;
            delete loc_ptr;
            loc_ptr = ptr;
        }
        else if (loc_ptr->rchild == nullptr) {
            ptr = loc_ptr->lchild;
            delete loc_ptr;
            loc_ptr = ptr;
        }
        else {
            ptr = inorder_succ(loc_ptr);
            loc_ptr->county_name = ptr->county_name;
            del_name(loc_ptr->rchild, ptr->county_name);
        }
    }
}

void bst::empty_tree() {

}

/******************************************************************************/
/******************************* MAIN  FUNCTION *******************************/


/******************************************************************************/