# Arduino Distance Sensor with LED and Buzzer

This Arduino project utilizes an ultrasonic distance sensor to measure distances and triggers different LED colors along with a buzzer based on the measured distance.

## Components Required

- Arduino board (e.g., Arduino Uno)
- Ultrasonic distance sensor (e.g., HC-SR04)
- RGB LED
- Buzzer
- Resistors
- Jumper wires

## Pin Connections

- RGB LED:
  - Red pin: Connected to pin 3 (RGB_RED_PIN)
  - Green pin: Connected to pin 5 (RGB_GREEN_PIN)
  - Blue pin: Connected to pin 6 (RGB_BLUE_PIN)
- Ultrasonic distance sensor:
  - Trigger pin: Connected to pin 12 (TRIG_PIN)
  - Echo pin: Connected to pin 8 (ECHO_PIN)
- Buzzer:
  - Connected to pin 13 (BUZZER_PIN)

## Sensor Parameters

- TRIGGER_DISTANCE_1: Distance threshold for triggering LED to fade to orange.
- TRIGGER_DISTANCE_2: Distance threshold for triggering LED to fade to red.

## LED Fade Parameters

- LED_FADE_STEP: Step size for fading the LED.
- LED_FADE_DELAY: Delay between each step in the LED fade process.

## Buzzer Parameters

- BUZZER_ON_DELAY: Delay duration for the buzzer being on.
- BUZZER_OFF_DELAY: Delay duration for the buzzer being off.

## How to Use

1. Connect the components according to the pin connections mentioned above.
2. Upload the provided Arduino sketch to your Arduino board.
3. Open the serial monitor to view the measured distances for debugging purposes.
4. Observe the LED and buzzer behavior based on the measured distance:
   - When the distance is between TRIGGER_DISTANCE_1 and TRIGGER_DISTANCE_2, the LED fades to orange, and the buzzer activates.
   - When the distance is less than or equal to TRIGGER_DISTANCE_2, the LED fades to red, and the buzzer activates with shorter delays.
   - Otherwise, the LED fades to blue, and the buzzer activates with longer delays.

## License

This project is licensed under the [MIT License](LICENSE).
