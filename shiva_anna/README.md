# Robotic Arm Control Program

## Overview
This project controls a robotic arm with five servo motors. The arm performs a series of movements, simulating actions such as base rotation, shoulder lift, elbow extension, wrist movement, and wrist roll.

## Features
- **Base Rotation**: Sweeps the base servo motor from 0 to 180 degrees.
- **Shoulder Lift and Elbow Extension**: Lifts the shoulder while extending the elbow.
- **Wrist Movement**: Moves the wrist up while rolling the wrist.
- **Smooth Transitions**: Delays between movements for smooth and realistic operation.

---

## Hardware Requirements
- **Arduino Board** (e.g., Uno, Mega)
- **Servo Motors** (5x for base, shoulder, elbow, wrist, and wrist roll)
- **External Power Supply** (if needed for the servos)
- **Jumper Wires** and **Breadboard**

---

## Software Requirements
- **Arduino IDE**

---

## Circuit Connections
| Servo Motor    | Arduino Pin |
|----------------|-------------|
| Base           | 5           |
| Shoulder       | 4           |
| Elbow          | 3           |
| Wrist          | 6           |
| Wrist Roll     | 7           |

---

## How to Use
1. **Setup the Hardware**:
   - Connect the servo motors to their respective pins on the Arduino.
   - Ensure the servos are powered with an appropriate power source.

2. **Upload the Code**:
   - Open the provided code in the Arduino IDE.
   - Connect the Arduino to your computer via USB.
   - Select the correct board and port in the Arduino IDE.
   - Click **Upload** to load the program onto the Arduino.

3. **Run the Program**:
   - Observe the robotic arm performing a series of movements.
   - Adjust the code if needed for specific motions or ranges.

---

## Customization
- **Modify Servo Angles**:
  - Adjust the range of motion for each servo by changing the loop limits (e.g., `for (ang = 0; ang <= 180; ang += 15)`).

- **Add New Movements**:
  - Add more loops or logic to perform additional actions.

- **Control via Serial Input**:
  - Implement `Serial.read()` to control specific servos interactively.

---

## Troubleshooting
- **Servo Not Moving**:
  - Check the servo connection to the correct pin.
  - Verify the servo is powered properly.

- **Jerky Movement**:
  - Increase the delay between movements for smoother operation.

- **No Serial Output**:
  - Ensure the baud rate in the Serial Monitor matches the code (`9600`).

---

## License
This project is licensed under the [MIT License](./LICENSE).

## Author
**Sai Teja Jarabala**
