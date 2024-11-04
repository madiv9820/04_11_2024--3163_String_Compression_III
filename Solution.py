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