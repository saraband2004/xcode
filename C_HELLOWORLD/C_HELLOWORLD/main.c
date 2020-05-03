//
//  main.c
//  C_HELLOWORLD
//
//  Created by FAN ZHOU on 4/8/20.
//  Copyright © 2020 FAN ZHOU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    void * p =  malloc(132);
    int * inp = p;
    inp ++ ;
    *inp = 45;
    printf("%d \n", * ((int*)(p+4)));
    
    
    p = calloc(31, 4);
    inp = p;
    inp ++ ;
    *inp = 45;
    for (int i = 0; i <10; i ++)
        printf("%d ", * ((int*)(p+i)));
    free(p);
    
    return 0;
}
