# Line Follower Bot

This Arduino project implements a line follower robot using infrared (IR) sensors to detect lines on the ground and control the movement of the robot accordingly.

## Components Required

- Arduino board (e.g., Arduino Uno)
- Motors and motor driver
- Infrared (IR) sensors
- Chassis and wheels
- Jumper wires

## Pin Connections

- Motor Control:
  - Motor 1 control pin 1: Connected to pin [motorPin1]
  - Motor 1 control pin 2: Connected to pin [motorPin2]
  - Motor 2 control pin 1: Connected to pin [motorPin3]
  - Motor 2 control pin 2: Connected to pin [motorPin4]
- IR Sensors:
  - IR sensor 1 pin: Connected to pin [irSensorPin1]
  - IR sensor 2 pin: Connected to pin [irSensorPin2]

## Operation

The robot moves according to the following logic:

- If both sensors detect the line, it moves forward.
- If only the left sensor detects the line, it turns right.
- If only the right sensor detects the line, it turns left.
- If neither sensor detects the line, it stops.

## Threshold

The `threshold` variable defines the threshold value for line detection. Adjust this value according to the ambient light conditions and the surface color of the line.

## Usage

1. Connect the components according to the pin connections mentioned above.
2. Upload the provided Arduino sketch to your Arduino board.
3. Place the robot on a surface with a line to follow.
4. Power on the robot and observe its behavior as it follows the line.

## License

This project is licensed under the [MIT License](LICENSE).

