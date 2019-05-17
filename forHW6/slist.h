#include "llist.h"

typedef char el_t;

class slist : public llist{
 public:
  slist(); // Constructor
  
  slist(const slist&); // Copy Constructor
  
  // search function, which will search for a number & return the position key
  int search(el_t);

  // replace functions will find a number & replace it with another desired
  // number

  void replace(el_t, int);

  // OVERLOAD OPERATOR SECTION

  // = operator overload means the receiver (to the left side of the 
  // equal sign) gets the toBeCopied's list

  // == operator will return a boolean value, depending on if the 
  // two lists are equal or not.

  slist& operator=(const slist&);
  bool operator==(const slist&);

};
