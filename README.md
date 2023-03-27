# Arduino Countdown Timer

This project is a simple Arduino countdown timer that uses a knob to set the time and buttons to adjust the countdown. It also includes a buzzer and LED lights for feedback. I have made this project for an assignment for my university and I have decided to publish these files. Feel free to use them for anything, no attribution required.

## Getting Started

### Prerequisites

To use this code, you will need the following:

- VS Code (or the Arduino IDE)
- Arduino board (tested on Arduino Uno)
- Arduino and C/C++ extensions for VS Code

### Installing

To install this project, follow these steps:

1. Clone this repository onto your local machine.
2. Open the project folder in your IDE.
3. If you use VS Code, install the necessary extensions (I used PlatformIO).
4. Open the "Timer.cpp" file in your IDE.
5. Upload the code to your Arduino board.
6. Connect the necessary components (buttons, LEDs, knob, and buzzer) to your Arduino board.
7. Make sure the PINs are set correct.
8. Power on your Arduino board and start the countdown timer.

### Usage

To use the countdown timer, follow these steps:

1. Adjust PIN_KNOB to your liking, the knob is used to control how quickly the countdown time is adjusted.
2. Press or hold PIN_BUTTON_1 to increase countdown time, and PIN_BUTTON_2 to decrease countdown time.
3. Press both buttons simultaneously to start or stop the countdown. You can adjust the countdown time when stopped.
4. The buzzer will beep when the countdown reaches zero.
