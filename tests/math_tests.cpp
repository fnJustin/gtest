#include "gtest/gtest.h"
#include "../src/math.h"


TEST( aproximatlyEqual, vec3 ) {
    EXPECT_EQ( math::approximatelyEqual(1,1) , true );
    EXPECT_EQ( math::approximatelyEqual(0.999,1) , true );
    EXPECT_EQ( math::approximatelyEqual(0.0,-0.0001) , true );
    EXPECT_EQ( math::approximatelyEqual(0.0, 0.01) , false );
    EXPECT_EQ( math::approximatelyEqual(1000.0, 1000.01) , false );
}

TEST( lenSq , vec3 ) {
    EXPECT_EQ( math::vec3(2,2,2).lenSq() , 12 );
    EXPECT_EQ( math::vec3(1,10,1).lenSq() , 102 );
    EXPECT_EQ( math::vec3(-11,10,-12).lenSq() , 365 );
}

TEST( length, vec3 ) {
    EXPECT_EQ( math::approximatelyEqual(math::vec3(0.707,0.707,0).len(), 1),true );
    EXPECT_EQ( math::vec3(2,3,6).len() , 7 );
}

TEST( dot,vec3 ) {
    math::vec3 v1 = math::vec3(1,0,0);
    math::vec3 v2 = math::vec3(-1,0,0);
    //these are parrellel
    EXPECT_EQ( v1.dot(v2), -1.0f );
    
}

TEST( cross, vec3 ) {
    math::vec3 v1 = math::vec3(1,0,0);
    math::vec3 v2 = math::vec3(0,1,0);
    //right angle
    math::vec3 v3 = math::vec3(0,0,1);
    
    EXPECT_EQ( v1.cross(v2) , v3 );
}
