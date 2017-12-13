/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  UnitTest.hpp
 *  NQueens
 *
 *  Created by laptop on 20/10/2017.
 *  Copyright © 2017 RyanNeedham. All rights reserved.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef UnitTest_hpp
#define UnitTest_hpp

#include <functional>
#include <iostream>
#include <vector>

typedef std::function<void()> F;
typedef std::vector<F> FunctionList;

class UnitTest
    {
    public:
        UnitTest () {}
       ~UnitTest () {}
        virtual std::string name ()
            { return "Unit Test"; };
        void run ()
            {
            FunctionList tests = populate();
            for (F f : tests) std::__invoke (f);
            show ();
            }
    protected:
        typedef std::pair<std::string, bool> Test;
        template <class T>
        void inline assert (std::string message, T expected, T actual)
            { results.push_back(Test(message, expected == actual)); }
        template <class T, class V>
        void inline assert (std::string message, T expected, V actual)
            { results.push_back(Test(message, expected == actual)); }
        bool passed ()
            { return std::all_of(results.begin(), results.end(), [&] (Test t) { return t.second; }); }
        virtual FunctionList populate ()
            { return FunctionList (); }
        void show ()
            {
            std::cout << name() << std::endl;
            std::cout << "-------------------------" << std::endl;
            std::for_each(results.begin(), results.end(), [&] (Test t) -> void
                { std::cout << t.first << ": " << ((t.second) ? "PASS" : std::string("FAIL")) << std::endl; });
            std::cout << std::endl;
            std::cout << name() << ": " << ((passed()) ? "SUCCESS" : "FAIL") << std::endl;
            std::cout << std::endl;
            }
    private:
        std::vector<Test> results;
    };

#endif /* UnitTest_hpp */
