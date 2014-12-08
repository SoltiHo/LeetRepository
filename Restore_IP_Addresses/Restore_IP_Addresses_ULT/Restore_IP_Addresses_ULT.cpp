#include "gtest/gtest.h"  // access test macro
#include "Restore_IP_Addresses.h"

TEST(Leet, Basic04){
    //Output:["255.255.111.35"]
    //Expected : ["255.255.11.135", "255.255.111.35"]
    string input("25525511135");
    Solution sol;
    vector<string> output = sol.restoreIpAddresses(input);

}



TEST(Leet, Basic03){
    //Output:[]
    //Expected : ["17.216.25.41", "17.216.254.1", "172.16.25.41", "172.16.254.1", "172.162.5.41", "172.162.54.1"]
    string input("172162541");
    Solution sol;
    vector<string> output = sol.restoreIpAddresses(input);

}

TEST(Leet, Basic02){
    //Output:["0.1.00.10", "0.1.001.0", "0.10.0.10", "0.10.01.0", "0.100.1.0", "01.0.0.10", "01.0.01.0", "01.00.1.0", "010.0.1.0"]
    //Expected : ["0.10.0.10", "0.100.1.0"]
    string input("010010");
    Solution sol;
    vector<string> output = sol.restoreIpAddresses(input);

}

TEST(Leet, Basic01){
    string input("0000");
    Solution sol;
    vector<string> output = sol.restoreIpAddresses(input);

}

// --------------------------------------------------------------------

