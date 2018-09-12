#include <iostream>
#include "math.h"

int main(int argc, char** argv)
{

    math::vec3 v(1,2,3);
    
    printf("Yo! %f \n",v.len());
    
    return 0;
}
