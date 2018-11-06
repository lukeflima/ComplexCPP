#include "main.cpp"
#include "../complex.cpp"

TEST_CASE( "Complex operations", "[complex]" ) {

    Complex c1(1,2);
    Complex c2(2,-1);
    Complex zero(0,0);
    Complex one(1,0);
    Complex i(0,1);
    
    SECTION( "sum" ) {
        auto sum1 = c1 + c2;
        REQUIRE((sum1.a == 3 && sum1.b == 1));
        auto sum2 = c2 + c1;
        REQUIRE((sum1.a == sum2.a && sum1.b == sum2.b));
        sum2 = sum1 + zero;
        REQUIRE((sum1.a == sum2.a && sum1.b == sum2.b));
        sum2 = sum1 + one;
        REQUIRE((sum1.a + 1 == sum2.a && sum1.b == sum2.b));
        sum2 = sum1 + i;
        REQUIRE((sum1.a == sum2.a && sum1.b + 1 == sum2.b));
    }
    SECTION( "sub" ) {
        auto sub1 = c1 - c2;
        REQUIRE((sub1.a == -1 && sub1.b == 3));
        auto sub2 = c2 - c1;
        REQUIRE((sub1.a == -sub2.a && sub1.b == -sub2.b));
        sub2 = sub1 - zero;
        REQUIRE((sub1.a == sub2.a && sub1.b == sub2.b));
        sub2 = sub1 - one;
        REQUIRE((sub1.a - 1 == sub2.a && sub1.b == sub2.b));
        sub2 = sub1 - i;
        REQUIRE((sub1.a == sub2.a && sub1.b - 1 == sub2.b));
        sub2 = -sub1;
        REQUIRE((sub1.a == -sub2.a && sub1.b == -sub2.b));
    }

    SECTION( "mul" ) {
        auto mul1 = c1 * c2;
        REQUIRE((mul1.a == 4 && mul1.b == 3));
        auto mul2 = c2 * c1;
        REQUIRE((mul1.a == mul2.a && mul1.b == mul2.b));
        mul2 = mul1 * zero;
        REQUIRE((mul2.a == 0 && mul2.b == 0));
        mul2 = mul1 * one;
        REQUIRE((mul1.a  == mul2.a && mul1.b == mul2.b));
        mul2 = mul1 * i;
        REQUIRE((mul2.a == -3 && mul2.b == 4));
    }

    SECTION( "div" ) {
        auto div1 = c1 / c2;
        REQUIRE((div1.a == 0 && div1.b == 1));
        auto div2 = c2 / c1;
        REQUIRE((div2.a == 0 && div2.b == -1));
        div2 = div1 / one;
        REQUIRE((div2.a == div1.a && div2.b == div1.b));
        div2 = div1 / i;
        REQUIRE((div2.a  == 1 && div2.b == 0));
        REQUIRE_THROWS((div1 / zero));
    }
}