#include "gtest/gtest.h"  // access test macro
#include "MultiplyStrings.h"


TEST(MultiplyStrings, Basic_02){
    Solution sol;
    string num1;
    string num2;

    char temp[1000];
    bool testPassed = false;
    for (int testNum1 = 0; testNum1 < 1000; ++testNum1){
        for (int testNum2 = 0; testNum2 < 1000; ++testNum2){
            num1.clear();
            num2.clear();
            memset(temp, 0, sizeof(char)* 1000);
            _itoa_s(testNum1, temp, 10);
            num1.insert(0, temp);

            memset(temp, 0, sizeof(char)* 1000);
            _itoa_s(testNum2, temp, 10);
            num2.insert(0, temp);

            string answer = sol.multiply(num1, num2);

            unsigned int calculatedAnswer = 0;
            for (unsigned int i = 0; i < answer.size(); ++i){
                calculatedAnswer = calculatedAnswer * 10 + (answer[i] - 0x30);
            }

            testPassed = (calculatedAnswer == (testNum1*testNum2));
            if (testPassed == false){
                std::cout << "num 1 = "<< num1 << ", " << "num2 = " << num2 << std::endl;
                std::cout << "results = " << calculatedAnswer << ", not equal to " << (testNum1*testNum2) << std::endl;
            }
            ASSERT_TRUE(testPassed);
        }
    }

    

}



TEST(MultiplyStrings, Basic_01){
    Solution sol;
    string num1;
    string num2;

    char temp[1000];
    memset(temp, 0, sizeof(char)* 1000);
    _itoa_s(999, temp, 10);
    num1.insert(0, temp);

    memset(temp, 0, sizeof(char)* 1000);
    _itoa_s(9999, temp, 10);
    num2.insert(0, temp);

    string answer = sol.multiply(num1, num2);

    unsigned int calculatedAnswer = 0;
    for (unsigned int i = 0; i < answer.size(); ++i){
        calculatedAnswer = calculatedAnswer * 10 + (answer[i] - 0x30);
    }

    ASSERT_EQ(calculatedAnswer, 9999 * 999);
}