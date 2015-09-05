//
//  main.cpp
//  linked_list
//
//  Created by Alejandro Lopez on 9/4/15.
//  Copyright (c) 2015 Alejandro Lopez. All rights reserved.
//

#include <stdio.h>
#include "linked_list.h"

int main(){
    linked_list<int> list;
    
    list.push_back(1);
    list.push_back(20);
    list.printList();
    list.pop_front();
    //list.pop_back();
    list.printList();
    list.pop_front();
    list.printList();
    list.pop_front();
}
