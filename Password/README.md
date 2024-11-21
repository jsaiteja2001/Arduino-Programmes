# Password Guessing Game

## Overview
This project implements a password guessing game using an Arduino and the `Password` library. The program allows users to guess a predefined password via the Serial Monitor. Feedback is provided for each action, such as appending a character, resetting the input, or evaluating the guess.

## Features
- **Password Entry**: Users can input characters to form a password guess.
- **Reset Functionality**: The guessed password can be reset using the `!` character.
- **Evaluation**: The guessed password is evaluated against the predefined password using the `?` character.
- **Masked Input**: Feedback shows `*` for each entered character to mask the input.

## Requirements
### Hardware
- Arduino Board (e.g., Uno, Mega)
- USB Cable to connect Arduino to a computer

### Software
- Arduino IDE
- `Password` library (Ensure it's installed in the Arduino IDE)

## How to Use
1. **Setup the Code**:
   - Upload the code to your Arduino board using the Arduino IDE.
   - Open the Serial Monitor (ensure the baud rate is set to `9600`).

2. **Gameplay Instructions**:
   - **Enter Characters**: Type characters into the Serial Monitor to form your password guess.
   - **Reset Password**: Type `!` to reset the entered password.
   - **Evaluate Guess**: Type `?` to check if your guess matches the predefined password.

3. **Feedback**:
   - If the password matches, the Serial Monitor displays:
     ```
     You guessed the correct password!
     ```
   - If the password does not match, the Serial Monitor displays:
     ```
     You did not guess the correct password!
     ```

## Example Interaction


## Notes
- The predefined password in this example is `1234`. Modify it in the code to change the password.
- Characters are masked with `*` to prevent revealing the password.

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**

For any questions or contributions, visit the repository at [GitHub](https://github.com/jsaiteja2001).

