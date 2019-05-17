// =======================================================
// HW#: HW3P2 searchable linked list
// Your name: Parth Kapur
// Compiler:  g++
// File type: header file
//=======================================================

#include "llist.h" //  To link with llist.h file



//typedef char el_t;  // alias will be int type




//Purpose: class searchable linked list, llist access public.
class slist: public llist
{


 public:
  slist();   //Constructor


  slist(const slist&); //Copy constructor


  slist& operator=(const slist&); //Copy overload function


  //Purpose: Search function to find Key contained
  int search(el_t);


  //Purpose: Replaces with another element.
  void replace(el_t,  int);


};
