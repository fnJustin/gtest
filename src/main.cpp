#include <iostream>
#include "math.h"
int * leak()
{
    return new int();
}

int main(int argc, char** argv)
{

    math::vec3 v(1,2,3);

    int * l = leak();
    
    printf("Yo! %f \n",v.len());
    
    return 0;
}
