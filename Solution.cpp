#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to compress the input string
    string compressedString(string word) {
        // Initialize an empty string for the compressed result
        string comp = ""; 
        // Set the starting index to 0
        int index = 0, length = word.length();

        // Loop until we reach the end of the word
        while(index < length) {
            // Store the current character
            char current_Character = word[index];
            // Initialize a temporary index to check subsequent characters
            int temp_Index = index + 1;
            // Count occurrences of the current character, starting with 1
            int current_Character_Count = 1;

            // Count the number of consecutive occurrences of the current character
            while(temp_Index < length && 
                  current_Character_Count < 9 && 
                  word[temp_Index] == current_Character) {
                current_Character_Count += 1;  // Increment the count
                temp_Index += 1;  // Move to the next character
            }

            // Append the count and the character to the compressed string
            comp += to_string(current_Character_Count) + current_Character;
            // Move the index to the next different character
            index = temp_Index;
        }

        // Return the final compressed string
        return comp;
    }
};

int main() {
    string word; Solution sol;
    cin >> word;

    cout << sol.compressedString(word = word) << endl;
}