#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string compressedString(string word) {
            string comp = ""; 
            int index = 0, length = word.length();

            while(index < length) {
                char current_Character = word[index];
                int temp_Index = index+1;
                int current_Character_Count = 1;

                while(temp_Index < length && 
                        current_Character_Count < 9 && 
                        word[temp_Index] == current_Character) {
                    current_Character_Count += 1;
                    temp_Index += 1;
                }

                comp += to_string(current_Character_Count) + current_Character;
                index = temp_Index;
            }

            return comp;
        }
};

int main() {
    string word; Solution sol;
    cin >> word;

    cout << sol.compressedString(word = word) << endl;
}