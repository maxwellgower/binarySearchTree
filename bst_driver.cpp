/********************************* FILE  INFO *********************************/
// Name: Max Gower  Z#: Z23637403
// Course: Data Structures and Algorithm Analysis COP3530: Dr. Lofton Bullard
// Due Date: Tuesday, August 3rd    Due Time: 11:59 PM
// Total Points: 100    Assignment 11: Binary Search Tree Program

// Description: Driver file for Binary Search Tree Program
/******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"

using namespace std;

/******************************************************************************/
/******************************* MAIN  FUNCTION *******************************/

int main( ) {

    cout<<"================================|\n"
          " Module 11: Binary Search Trees |\n"
          "================================'\n\n"
          "(all contents displayed in order)\n\n";


    cout<<"* * Test 1 * * (Default Constructor)\n\n";
    bst myTree;
    myTree.print_tree();
    cout<<"\n\n==== End of Test 1 ====\n"<<endl;


    cout<<"* * Test 2 * * (Insert Function)\n\n";
    myTree.insert("New County", 234658);
    myTree.print_tree();
    cout<<"\n\n==== End of Test 2 ====\n"<<endl;


    cout<<"* * Test 3 * * (County Ranges: B to K)\n\n";
    myTree.county_ranges("B","K");
    cout<<"\n\n==== End of Test 3 ====\n"<<endl;


    cout<<"* * Test 4 * * (Delete Function)\n\n";
    myTree.del_name("Miami Dade");
    myTree.print_tree();
    cout<<"\n\n==== End of Test 4 ====\n"<<endl;


    cout<<"* * Test 5 * * (Sorted Info)\n\n";
    myTree.sorted_info();
    cout<<"\n\n==== End of Test 5 ====\n"<<endl;


    cout<<"* * Test 6 * * (Empty BST)\n\n";
    myTree.empty_tree();
    myTree.print_tree();
    cout<<"\n\n==== End of Test 6 ====\n\n";

    bst B;
    treenode* root1=nullptr,* root2=nullptr;
    string s;
    double p;
    char ch;
    string key3;
    string key4;
    string response;
    string r1, r2;
    cout<<"enter command, c=count, i=insert item,s=search tree,d=delete item,"
          "p=print tree, r = range, e=exit: ";
    cin>>ch;
    cout<<endl;

    while (ch != 'e') {
        switch (ch) {

            case 'i':cout<<"\nenter county: ";
                cin>>s;
                cout<<"\nenter population: ";
                cin>>p;
                B.insert(s, p);
                break;
            case 's':cout<<"enter word to search for: ";
                cin>>s;
                if (!B.search_tree(s))
                    cout<<s<<"not in tree\n";
                else
                    cout<<s<<" was found in the tree\n";
                break;
            case 'd':cout<<"enter word to delete: ";
                cin>>s;
                B.del_name(s);
                break;
            case 'p':cout<<"...printing tree...\n";
                B.print_tree();
                break;

            default:break;
        }
        cout<<"enter command, i=insert item,s=search tree,d=delete item,"
              "p=print tree, e=exit: ";
        cin>>ch;
        cout<<endl;
    }
    cout<<endl<<"no more binary tree.....\n";

    cout<<"============================\n";
    cout<<"==== Program Terminated ====\n";
    cout<<"============================\n";

    return 0;

}

/******************************************************************************/