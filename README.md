# c_lists
a library for using lists in C/C++

This library was written in C by me, NUMBUKU. It defines some basic list operators that languages like Python and 
JavaScript also have, I used linked lists to do so. It uses three standard libraries: stdio.h, stdlib.h and math.h.
I got most of my knowledge from this webpage: https://www.learn-c.org/en/Linked_lists, I recommend checking it out
since you might not know what is going on in these methods. I also wanted to say that I am not a 
professional programmer, and that if you have any tips on how to improve this library, please contact me and I will
try to implement them.

The library works as the following. To define a new, empty list, use: "node * 'the name of your list' = newList();".
To use any of the other methods, please read the comments that I put next to them, so you know what they do. All of 
them will require a list to operate on though, so just use: 
"'the method you want to use'('the name of your list', [any other arguments]);". Sometimes a function will return
a new list, then use: 
"node * 'the name of your new list' = 'the method you want to use'('the name of your list', [any other arguments]);".
I included an example file so you can see how you might use this library, the file is called: example.c.

To include the file have it in the same folder and type: '# include "clists.h"'.

That's it, I hope you learn something.
