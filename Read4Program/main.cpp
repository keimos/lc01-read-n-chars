//
//  main.cpp
//  Read4Program
//
//  Created by KEITH MOSLEY on 7/10/24.
//

#include <iostream>
#include <vector>
#include <cstring>

int read4(char *buf) {
    static std::string fileContent = "The quick brown fox jumps over the lazy dog.";
    static size_t fileIndex = 0;
    
    int count = 0;
    while (count < 4 && fileIndex < fileContent.size()) {
        buf[count++] = fileContent[fileIndex++];
    }
    return count;
}

class Solution {
public:
    
    int read(char *buf, int n){
        int totalCharsRead = 0;
        char tempBuf[4];
        int charsRead;
        
        while (totalCharsRead < n) {
            charsRead = read4(tempBuf);
            
            if (charsRead == 0) {
                break;
            }
            
            int charsToCopy = std::min(charsRead, n - totalCharsRead);
            std::memcpy(buf + totalCharsRead, tempBuf, charsToCopy);
            totalCharsRead += charsToCopy;
        }
        
        return totalCharsRead;
    }
};


int main() {
    Solution solution;
    char buf[100];
    int n = 10; // Number of characters to read
    int charsRead = solution.read(buf, n);
    
    std::cout << "Number of characters read: " << charsRead << std::endl;
    std::cout << "Content read: " << std::string(buf, charsRead) << std::endl;
    
    return 0;
}
