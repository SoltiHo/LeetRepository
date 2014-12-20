// Given an absolute path for a file(Unix - style), simplify it.
// 
// For example,
// path = "/home/", = > "/home"
// path = "/a/./b/../../c/", = > "/c"
// click to show corner cases.
// 
// Corner Cases :
// Did you consider the case where path = "/../" ?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        stack<string> folders;

        size_t found = 0;
        size_t lastFound = 0;
        char buffer[256];
        int sectionSize = 0;
        while (found != string::npos){
            memset(buffer, 0, sizeof(char)* 256);
            lastFound = found;
            found = path.find_first_of("/", found + 1);
            if ((found > lastFound + 1) && (found != string::npos)) {
                sectionSize = found - lastFound - 1;
                memcpy(buffer, path.data() + lastFound + 1, sizeof(char)* (sectionSize));
                if ((sectionSize == 2) && (memcmp(buffer, "..", sizeof(char)* 2) == 0)){
                    // pop
                    if (!folders.empty()){
                        folders.pop();
                    }
                }
                else if ((sectionSize > 1) || (memcmp(buffer, ".", sizeof(char)* 1) != 0)){
                    // a folder name
                    folders.push(buffer);
                }
            }
        }
        if (lastFound < path.size() - 1){
            sectionSize = path.size() - lastFound - 1;
            memcpy(buffer, path.data() + lastFound + 1, sizeof(char)* (sectionSize));
            if ((sectionSize == 2) && (memcmp(buffer, "..", sizeof(char)* 2) == 0)){
                // pop
                if (!folders.empty()){
                    folders.pop();
                }
            }
            else if ((sectionSize > 1) || (memcmp(buffer, ".", sizeof(char)* 1) != 0)){
                // a folder name
                folders.push(buffer);
            }
        }


        string output;
        if (folders.size() == 0){
            output.insert(output.begin(), '/');
        }
        else{
            while (folders.size() > 0){
                output.insert(0, folders.top());
                output.insert(output.begin(), '/');
                folders.pop();
            }
        }

        return output;
    }

};