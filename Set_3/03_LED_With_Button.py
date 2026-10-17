# Experiment Name: Interface Push Button / Digital sensors with Raspberry Pi
# (experiment14). Source: photos at8.42.14PM (16),(17), page12 + continuation.
#
# Aim:
# Interface Push Button, Digital sensors with Raspberry Pi; write a program to
# turn ON LED when push button is pressed or at sensor detection.
#
# Required starting theory:
# No separate introductory theory/principle paragraph is present before the code.
# The page lists components and connections. The supplied code implements the
# push-button part of the aim; no digital-sensor interface is shown.
#
# Components Required:
# - Raspberry Pi3 setup with monitor, mouse and keyboard
# - One LED
# - One330-ohm resistor
# - Jumper wires
# - Breadboard
# - Push button
#
# Connections:
# LED: long leg ->physical pin7; short leg ->GND.
# Push button: one side ->physical pin11; other side ->GND.
# Code: GPIO.BOARD; LED=7 (BCM4), button=11 (BCM17); internal GPIO.PUD_UP.
# The exact physical GND pin is not specified in this experiment.
# Safety clarification: put the listed330-ohm resistor in series with the LED;
# its placement is omitted from the written connection list. A press grounds the
# pulled-up input (False/LOW). Never connect a button input to5V.
#
# Python Program:

# Extracted and corrected: exp14 p12 + continuation, photos14(16),(17).
# Original BOARD mode, LED7/button11, active-low logic and ELSE sleep(1) retained.
# False/pull_up_down/PUD_UP spelling fixed. Cleanup moved to an interrupt handler.
# No new debounce or polling behavior has been introduced.
import RPi.GPIO as GPIO
import time

LED = 7
button = 11
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(button, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED, GPIO.OUT)
try:
    while True:
        button_state = GPIO.input(button)
        if button_state == False:
            GPIO.output(LED, GPIO.HIGH)
        else:
            time.sleep(1)
            GPIO.output(LED, GPIO.LOW)
except KeyboardInterrupt:
    GPIO.cleanup()

# Expected Output/Result:
# No separate written result/output section is available on the button pages.
# Expected from code: a press turns LED ON; unpressed branch waits1s then turns
# LED OFF. No console output. Original slow-release behavior is preserved.
# Not physically tested.
