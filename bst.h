/********************************* FILE  INFO *********************************/
// Name: Max Gower  Z#: Z23637403
// Course: Data Structures and Algorithm Analysis COP3530: Dr. Lofton Bullard
// Due Date: Tuesday, August 3rd    Due Time: 11:59 PM
// Total Points: 100    Assignment 11: Binary Search Tree Program

// Description: Declaration of Class bst
/******************************************************************************/

#ifndef bst_H
#define bst_H

using namespace std;

/****************************** CLASS DEFINITION ******************************/

class treenode {
public:
    string county_name;
    double population_size;
    treenode* lchild;
    treenode* rchild;
};

/****************************** CLASS DEFINITION ******************************/

class bst {
public:
    bst(); //store the data file (“county_data.txt”) into initial bst.
    ~bst(); //de-allocates dynamic memory allocate for tree bool empty();
    // checks to see if the tree is empty.
    bool empty(); //return true if bst is null; otherwise false is returned.
    void insert(const string& item, const double& population); //aux function.
    void insert(treenode*&, const string& item, const double& population);
    //inserts an item into the bst; this function is invoked in main by the
    // auxiliary function described above.
    void del_name(string item); //auxiliary function.
    void del_name(treenode*& loc_ptr, string item); //function deletes an item
    //from the bst; function invoked in main by aux function described above.
    treenode* search_tree(string item); //auxiliary function.
    treenode* search_tree(treenode*, string item); //returns a pointer to the
    // node in bst with a county name county name that matches item; this
    // function is invoked in main by the auxiliary function described above.
    treenode* inorder_succ(treenode*); //returns a pointer to the inorder
    // successor, based on the county name.
    void county_ranges(const string& min,const string& max); //aux function.
    void county_ranges(treenode*&, const string& min, const string& max);
    //prints all county names that lie between min and max, inclusive.
    void print_tree(); //aux function.
    void print_tree(treenode*&); //prints county records, sorted by name.
    void sorted_info(); //aux function.
    void sorted_info(ostream&, treenode*&); //prints each county record to
    // a file called “county_info.txt”, sorted by county name.
    void empty_tree(); //de-allocate all nodes that were allocated to the bst.

private:
    treenode* root;
};

#endif //bst_H

/******************************************************************************/