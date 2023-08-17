/*
    This library was written in C by me, NUMBUKU. It defines some basic list operators that languages like Python and 
    JavaScript also have, I used linked lists to do so. It uses three standard libraries: stdio.h, stdlib.h and math.h.
    I got most of my knowledge from this webpage: https://www.learn-c.org/en/Linked_lists, I recommend checking it out
    because otherwise you might not know what is going on in these methods. I also wanted to say that I am not a 
    professional programmer, and that if you have any tips on how to improve this library, please contact me and I will
    try to implement them.

    The library works as the following. To define a new, empty list, use: "node * 'the name of your list' = newList();".
    To use any of the methods, please read the comments that I put next to them, so you know what they do. All of them
    will require a list to operate on though, so just use: 
    "'the method you want to use'('the name of your list, '[any other arguments]);".

    That's it, I hope you learn something.
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct node_t { // defines an element
    double data;
    struct node_t * next;
} node;

node * newList (){ // returns a head which points to a list with a small garbage value in it
    node * a = NULL;
    a = (node *)malloc(sizeof(node));
    a->data = 1.7E-308;
    a->next = NULL;
    return a;
}

node * clear(node * head){ // clears the list and makes it empty again
    node * temp = NULL;
    temp = newList();
    return temp;
}

void printlist(node * head){ // prints the entire list
    node * current = head;
    if (current->data == 1.7E-308){
        return;
    }

    while (current != NULL) {
        printf("%lf\n", current->data);
        current = current->next;
    }
    return;
}

void slice(node * head, int index1, int index2){ // prints the list between the two given indices
    node * current = head;
    if (current->data == 1.7E-308){
        return;
    }

    for (int i = 0; i < index1; i++){
        if (current != NULL){
            current = current->next;
        } else {
            printf("Index %d is not in this list.", index2);
        }
    }
    for (int j = 0; j < index2 - index1 + 1; j++){
        if (current != NULL){
            printf("%lf\n", current->data);
            current = current->next;
        } else {
            printf("Index %d is not in this list.", index2);
        }
    }
    return;
}

int len(node * head){ // returns the length of the list
    int i = 0;
    node * current = head;
    if (current->data == 1.7E-308){
        return 0;
    }
    while (current != NULL){
        i++;
        current = current->next;
    }
    return i;
}

void app(node * head, double data){ // appends a value to the end of the list
    node * current = head;
    if (current->data == 1.7E-308){
        current->data = data;
        current->next = NULL;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newList();
        current->next->data = data;
        current->next->next = NULL;
    }
    return;
}

void extend(node * head, node * head1){ // extends the list by adding another list at the end
    node * current = head;
    if (current->data == 1.7E-308){
        current = head1;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = head1;
    }
    return;
}

node * prp(node * head, double data){ // prepends a value to the beginning of the list and returns the new head
    node * temp = newList();
    temp->data = data;
    temp->next = head;

    return temp;
}

void pop(node * head){ // removes the value at the end of the list
    node * current = head;
    node * previous;
    if (len(head) == 1){
        current->data = 1.7E-308;
        current->next = NULL;
        return;
    }
    if (current->data != 1.7E-308){
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
    }
    return;
}

node * shift(node * head){ // removes the value at the beginning of the list and returns the new head
    if (len(head) == 1){
        return newList();
    }
    return head->next;
}

node * copy(node * head){ // returns a copy of the original list, without pointing to the same thing
    node * returnvalue = newList();
    node * current = head;
    while (current != NULL && current->data != 1.7E-308){
        app(returnvalue, current->data);
        current = current->next;
    }
    return returnvalue;
}

double atIndex(node * head, int index){ // returns the value at a given index
    int i;
    for (i = 0; i < index; i++){
        if(head->next != NULL){
            head = head->next;
        } else {
            printf("Index %d is not in the range of this list.\n", index);
            return NAN;
        }
    }
    return head->data;
}

int indexOf(node * head, double val){ // returns the index of the first value in the list with the given value
    int i = 0;
    int c = -1;
    while (1){
        c++;
        if (head->data == val){
            break;
        } else {
            head = head->next;   
        }

        if (head->next = NULL){
            printf("Found no such element as %lf in this list.\n", val);
            return -1;
        }
    }
    return c;
}

void changeAtIndex(node * head, int index, double data){ // changes the value at the given index to the given value
    int i;
    for (i = 0; i < index; i++){
        head = head->next;
    }
    head->data = data;
    return;
}

node * insert(node * head, double data, int index){ // inserts the given value at the given index, returns the new head when inserting values at the beginning of the list
    node * current = head;
    if (index == 0){
        return prp(head, data);
    }

    for (int i = 0; i < index-1; i++){
        if (current->next != NULL){
            current = current->next;
        } else if (i+1 == index){
            break;
        } else {
            printf("Index %d is not in the range of this list.\n", index);
            return head;
        }
    }
    node * temp = current->next;
    current->next = newList();
    current->next->data = data;
    current->next->next = temp;
    return head;
}

node * removeAtIndex(node * head, int index){ // removes the value at the given index, returns the new head when removing the first value in the list
    node * current = head;
    node * previous;

    if (index == 0){
        return shift(head);
    }

    for (int i = 0; i < index; i++){
        if (current->next != NULL){
            previous = current;
            current = current->next;
        } else if (i+1 == index){
            break;
        } else {
            printf("Index %d is not in the range of this list.\n", index);
            return head;
        }
    }
    previous->next = current->next;
    return head;
}

node * removeValue(node * head, double data){ // removes the first occurence of the given value in the list, returns the new head when removing the first value in the list
    node * current = head;
    node * previous;
    
    if (current->data == data){
        return shift(head);
    }

    while (current->data != data){
        if (current->next == NULL && current->data != data){
            printf("Found no such element as %lf in this list.\n", data);
            return head;
        }
        previous = current;
        current = current->next;
    }
    previous->next = previous->next->next;
    return head;
}

node * reverse(node * head){ // returns a list which is the reverse of the given list
    node * temp = copy(head);
    node * returnvalue = newList();
    for (int i = 0; i < len(head); i++){
        app(returnvalue, atIndex(temp, len(temp) - 1));
        pop(temp);
    }
    return returnvalue;
}

int sign(node * head){ // returns 1 if there are any signed numbers, otherwise it returns 0
    node * temp = head;
    while (temp != NULL) {
        if (abs(temp->data) != temp->data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int unsign(node * head){ // returns 1 if there are any unsigned numbers, otherwise it returns 0
    node * temp = head;
    while (temp != NULL) {
        if (abs(temp->data) == temp->data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int count(node * head, double data){ // returns the number of occurences of the given value in the list
    int ans = 0;
    node * current = head;
    while (current != NULL){
        if (current->data == data){
            ans++;
        }
        current = current->next;
    }
    return ans;
}

double min (node * head){ // returns the smallest value in the list
    node * temp = head;
    double a = temp->data;
    while (temp != NULL){
        if (temp->data < a){
            a = temp->data;
        }
        temp = temp->next;
    }
    return a;
}

double max(node * head){ // returns the largest value in the list
    node * temp = head;
    double a = temp->data;
    while (temp != NULL){
        if (temp->data > a){
            a = temp->data;
        }
        temp = temp->next;
    }
    return a;
}

node * sort(node * head){ // returns the given list, but sorted in ascending order
    node * temp = copy(head);
    node * returnvalue = newList();
    int a = len(head);
    for (int i = 0; i < a; i++){
        app(returnvalue, min(temp));
        temp = removeValue(temp, min(temp));
    }
    return returnvalue;
}

double average(node * head){ // returns the average of all elements
    double a;
    node * temp = head;
    while (temp != NULL){
        a += temp->data;
        temp = temp->next;
    }
    return a/len(head);
}

double mean(node * head){ // returns the median of all elements
    node * sorted = sort(head);
    double a = len(sorted);
    int b = a/2;
    a = a/2;
    if (b == a){
        return (atIndex(sorted, a - 1) + atIndex(sorted, a))/2;
    } else {
        return atIndex(sorted, a - 0.5);
    }
}

double mode(node * head){ // returns the mode of all elements
    node * number = newList();
    for (int i = 0; i < len(head); i++){
        app(number, count(head, atIndex(head, i)));
    }
    node * temp = number;
    double maximum = max(temp);
    temp = removeValue(temp, max(temp));
    if (max(temp) == maximum){
        printf("No mode found in this list");
        return NAN;
    }
    return atIndex(head, indexOf(number, max(number)));
}
