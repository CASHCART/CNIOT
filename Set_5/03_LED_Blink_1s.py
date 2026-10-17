# Experiment Name: LED blinking every1second (exam adaptation of experiment12)
# Source: photos at8.42.14PM (12),(13), record pages8-9.
#
# Aim:
# Original record aim: To interface an LED with Raspberry Pi and write a Python
# program to turn the LED ON for1second and OFF for2seconds, continuously.
# Explicit Set5 adaptation:1second ON and1second OFF; only OFF delay changes.
# There is no separately photographed1s/1s experiment.
#
# Required starting theory:
# No separate theoretical introduction is printed on the available pages.
# The following Procedure appears before the program (wording normalized):
# 1. Switch ON the Raspberry Pi.
# 2. Connect the LED circuit as shown in the circuit diagram.
# 3. Open the Python editor.
# 4. Import the required libraries.
# 5. Repeat the process continuously using a while loop.
# No separate circuit-diagram image is supplied among the available pages.
#
# Components Required:
# - Raspberry Pi3/4
# - LED
# -330-ohm resistor
# - Breadboard
#
# Connections:
# - Connect the GND pin of Raspberry Pi to the breadboard ground rail.
# - Connect the longer leg of the LED to one end of the330-ohm resistor.
# - Connect the shorter leg (cathode) of the LED to the ground rail.
# - Connect the other end of the resistor to GPIO17.
# - Code uses BOARD11, which is the same signal as BCM GPIO17.
# - Exact physical GND pin is not specified on this experiment's page.
#
# Python Program:

# Extracted and corrected (explicit exam timing adaptation of exp12, not a second original).
# BOARD11=BCM17. Original has1s ON/2s OFF; requested Set5 has1s ON/1s OFF.
# Only second sleep changed to1; API spelling/case fixed; Ctrl+C cleanup added.

import RPi.GPIO as PIN
from time import sleep

PIN.setwarnings(False)
PIN.setmode(PIN.BOARD)
PIN.setup(11, PIN.OUT, initial=PIN.LOW)
try:
    while True:
        PIN.output(11, PIN.HIGH)
        print("LED is ON")
        sleep(1)
        PIN.output(11, PIN.LOW)
        print("LED is OFF")
        sleep(1)
except KeyboardInterrupt:
    PIN.cleanup()

# Expected Output/Result:
# No separate original1s/1s result is available. Expected from this explicitly
# adapted code: LED is ON (1s), LED is OFF (1s), repeatedly. Not physically tested.
