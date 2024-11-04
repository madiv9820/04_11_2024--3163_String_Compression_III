# String Compression Explanation

- ### Intuition
    - The goal of the function is to compress a string by converting sequences of the same character into a format where the character is followed by the count of its consecutive occurrences. This is particularly useful in scenarios where we want to reduce the size of data for storage or transmission. For instance, a string like `"aaabbc"` can be represented more compactly as `"3a2b1c"`, which provides a clear representation of the character counts.

- ### Approach
    1. **Initialization**:
        - Start by defining a string `comp` to hold the compressed result.
        - Use an integer `index` to track the current position in the input string and get its length `length`.

    2. **Outer Loop**:
        - Use a `while` loop to traverse the string from the beginning to the end (`index < length`).
        - At each iteration, identify the current character and set up a counter for its occurrences.

    3. **Inner Loop**:
        - Within the outer loop, use another `while` loop to count how many times the current character appears consecutively This loop continues as long as:
                - `temp_Index` is within the bounds of the string.
                - The count of occurrences is less than 9 (to fit in a single digit).
                - The character at `temp_Index` matches the `current_Character`.
        - Increment the count and move `temp_Index` forward each time a match is found.

    4. **Building the Compressed String**:
        - Once the count of the current character has been determined, append the count and the character to the `comp` string. This is done by converting the count to a character (e.g., `char('0' + current_Character_Count)`).

    5. **Update Index**:
        - Set `index` to `temp_Index` to continue processing the next distinct character.

    6. **Return Result**:
        - After the entire string has been processed, return the `comp` string containing the compressed format.

- ### Example
    Let's illustrate the process with the string `"aaabbc"`:

    1. **First iteration** (`index = 0`):
        - `current_Character = 'a'`
        - Count `current_Character_Count = 1`
        - The inner loop counts `2` more 'a's (total `3a`), so `comp = "3a"`, and `index` moves to `3`.

    2. **Second iteration** (`index = 3`):
        - `current_Character = 'b'`
        - Count `current_Character_Count = 1`
        - The inner loop counts `1` more 'b' (total `2b`), so `comp = "3a2b"`, and `index` moves to `5`.

    3. **Third iteration** (`index = 5`):
        - `current_Character = 'c'`
        - Count `current_Character_Count = 1`
        - No more 'c's to count, so `comp = "3a2b1c"`, and `index` moves to `6`, ending the loop.

- ### Time Complexity
    - **O(n)**: The algorithm processes each character of the string a limited number of times. Even though there are nested loops, the inner loop will never execute more times than there are characters in total. Therefore, the time complexity is linear with respect to the size of the input string.

- ### Space Complexity
    - **O(n)**: In the worst case, where the input string has no repeating characters (e.g., `"abcdef"`), the compressed string may end up being of similar length to the original. Thus, the space required for the compressed string can be proportional to the length of the input string, leading to a space complexity of O(n).

- ### Code
    **Python Solution** <br>
    ```python3 []
    class Solution:
        def compressedString(self, word: str) -> str:
            # Initialize an empty string for the compressed result
            comp = ''
            # Set the starting index to 0
            index = 0
            # Get the length of the input word
            length = len(word)

            # Loop until we reach the end of the word
            while index < length:
                # Store the current character
                current_Character = word[index]
                # Initialize a temporary index to check subsequent characters
                temp_Index = index + 1
                # Count occurrences of the current character, starting with 1
                current_Character_Count = 1

                # Count the number of consecutive occurrences of the current character
                while (temp_Index < length and 
                    current_Character_Count < 9 and 
                    word[temp_Index] == current_Character):
                    current_Character_Count += 1  # Increment the count
                    temp_Index += 1  # Move to the next character

                # Append the count and the character to the compressed string
                comp += str(current_Character_Count) + current_Character
                # Move the index to the next different character
                index = temp_Index

            return comp  # Return the final compressed string
    ```

    **C++ Solution** <br>
    ```C++ []
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
    ```