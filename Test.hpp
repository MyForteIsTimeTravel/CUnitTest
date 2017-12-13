/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Test
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Test_hpp
#define Test_hpp
#include "UnitTest.hpp"

struct Test : public UnitTest
    {
    std::string name () override
        { return "Test"; }
        
    FunctionList populate () override
        {
        return FunctionList
            {
            /**
             *  test one
             */
            [this] 
                {
                
                assert("test one", true, true);
                },
            
            /**
             *  test two
             */
            [this]
                {
                
                assert("test one", true, true);
                }
            };
        }
    };

#endif /* QuaterionTest_h */


