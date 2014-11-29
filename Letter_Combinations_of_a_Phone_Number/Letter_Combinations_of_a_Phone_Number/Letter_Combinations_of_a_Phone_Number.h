// Given a digit string, return all possible letter combinations that the number could represent.
// 
// A mapping of digit to letters(just like on the telephone buttons) is given below.
// 
// Input:Digit string "23"
//   Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//        Note :
//             Although the above answer is in lexicographical order, your answer could be in any order you want.

// no 0 is allowed
// 1 is mapping to a space
// 2: abc --> 0x61 ~ 0x63
// 3: def --> 0x64 ~ 0x66
// 4: ghi --> 0x67 ~ 0x69
// 5: jkl --> 0x6A ~ 0x6C
// 6: mno --> 0x6D ~ 0x6F
// 7: pqrs --> 0x70 ~ 0x73
// 8: tuv --> 0x74 ~ 0x76
// 9: xwyz --> 0x77 ~ 0x7A

// [a ~ z] = 0x61 ~ 0x7A
// space = 0x20




#include <vector>
using namespace std;



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if (digits.size() == 0){
            output.push_back("");
        }

        // handle the first char
        switch (digits[0]){
        case '1':
            output.push_back(" ");
        case '2':
            // abc
            output.push_back("a");
            output.push_back("b");
            output.push_back("c");
            break;
        case '3':
            // def
            output.push_back("d");
            output.push_back("e");
            output.push_back("f");
            break;
        case '4':
            // ghi
            output.push_back("g");
            output.push_back("h");
            output.push_back("i");

            break;
        case '5':
            // jkl
            output.push_back("j");
            output.push_back("k");
            output.push_back("l");
            break;
        case '6':
            // mno
            output.push_back("m");
            output.push_back("n");
            output.push_back("o");
            break;
        case '7':
            // pqrs
            output.push_back("p");
            output.push_back("q");
            output.push_back("r");
            output.push_back("s");
            break;
        case '8':
            // tuv
            output.push_back("t");
            output.push_back("u");
            output.push_back("v");
            break;
        case '9':
            // wxyz
            output.push_back("w");
            output.push_back("x");
            output.push_back("y");
            output.push_back("z");
            break;
        default:
            // unsupported digits, fail
            return output;
            break;
        }

        // remove the first char
        digits.erase(0, 1);

        unsigned int originalSize = 0;
        for (auto& c : digits){
            originalSize = output.size();
            switch (c){
            case '1':
                for (auto& s : output){
                    s.append(" ");
                }
                break;
            case '2':
                // abc
                duplicateVector(output, 3);
                for (unsigned int i = 0; i < originalSize; ++i){
                    output[i].append("a");
                    output[i + originalSize].append("b");
                    output[i + (originalSize << 1)].append("c");
                }
                break;
            case '3':
                // def
                duplicateVector(output, 3);
                for (unsigned int i = 0; i < originalSize; ++i){
                    output[i].append("d");
                    output[i + originalSize].append("e");
                    output[i + (originalSize << 1)].append("f");
                }
                break;
            case '4':
                // ghi
                duplicateVector(output, 3);
                for (unsigned int i = 0; i < originalSize; ++i){
                    output[i].append("g");
                    output[i + originalSize].append("h");
                    output[i + (originalSize << 1)].append("i");
                }
                break;
            case '5':
                // jkl
                duplicateVector(output, 3);
                for (unsigned int i = 0; i < originalSize; ++i){
                    output[i].append("j");
                    output[i + originalSize].append("k");
                    output[i + (originalSize << 1)].append("l");
                }
                break;
            case '6':
                // mno
                duplicateVector(output, 3);
                for (unsigned int i = 0; i < originalSize; ++i){
                    output[i].append("m");
                    output[i + originalSize].append("n");
                    output[i + (originalSize << 1)].append("o");
                }
                break;
            case '7':
                // pqrs
                duplicateVector(output, 4);
                for (unsigned int i = 0; i < originalSize; ++i){
                    output[i].append("p");
                    output[i + originalSize].append("q");
                    output[i + (originalSize << 1)].append("r");
                    output[i + (originalSize * 3)].append("s");
                }
                break;
            case '8':
                // tuv
                duplicateVector(output, 3);
                for (unsigned int i = 0; i < originalSize; ++i){
                    output[i].append("t");
                    output[i + originalSize].append("u");
                    output[i + (originalSize << 1)].append("v");
                }
                break;
            case '9':
                // wxyz
                duplicateVector(output, 4);
                for (unsigned int i = 0; i < originalSize; ++i){
                    output[i].append("w");
                    output[i + originalSize].append("x");
                    output[i + (originalSize << 1)].append("y");
                    output[i + (originalSize * 3)].append("z");
                }
                break;
            default:
                // unsupported digits, fail
                return output;
                break;
            }
        }

        return output;
    }


    inline void duplicateVector(vector<string>& vec, const unsigned int factor){
        // fast way to duplicate vector itself
        //    std::size_t size = myvec.size();
        //    myvec.resize(size * 3);  //resize must protects us from iterator invalidation
        //    vector<string>::iterator it = myvec.begin() + size;
        //    std::copy(myvec.begin(), it, it);
        //    std::copy(myvec.begin(), it, it + size);
        // http://stackoverflow.com/questions/14781264/how-to-self-copy-a-vector

        const size_t originalSize = vec.size();
        vec.resize(originalSize * factor);

        vector<string>::iterator it = vec.begin() + originalSize;
        for (unsigned int i = 0; i < factor - 1; ++i){
            copy(vec.begin(), it, it + (originalSize * i));
        }
    }
};