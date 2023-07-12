# include <clists.h>

int main(){
  // note that the list stores double data type
  node * list = newList(); // defines a new list called list
  
  // appends some initial values to the list
  app(list, 0);
  list = prp(list, 3001); // prepends a value to the list  
  app(list, -3);
  app(list, 6.9);
  app(list, -2.8);
  app(list, 420);
  
  printlist(list); // prints the entire list
  slice(list, 1, 3); // prints the list from index 1 to index 3 including  1 and 3
  int length = len(list); // stores the length of the list in a variable (length in this case)
  
  node * list2 = newList();
  app(list2, -3);
  app(list2, 1.3E-5);
  
  extend(list, list2); // appends another list (list2 in this case) to the list
  pop(list); // removes the last value of the list
  list = shift(list); // removes the first value of the list
  node * list3 = copy(list); // stores a copy of the list in a new list (list3 in this case)
  double index3 = atIndex(list, 3); // stores the value of the list at index 3 in a variable (index3 in this case)
  list = removeAtIndex(list, 0); // removes the value of the list at index 0
  list = removeValue(list, 420); // removes the first occurence of the value 3001
  list = reverse(list); // reverses the list so that the last element becomes the first element
  int negthree = count(list, -3); // counts the number of occurences of the value -3 and stores it in a variable (negthree in this case)
  double maximum = max(list); // strores the maximum value of the list in a variable (maximum in this case)
  list = sort(list); // sorts the list in ascending order
  averagevalue = average(list); // stores the average of the list in a variable (averagevalue in this case)
}
