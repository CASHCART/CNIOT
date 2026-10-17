# Experiment Name: Interfacing an LED with Raspberry Pi (experiment12)
# Source: photos at8.42.14PM (12),(13), record pages8-9.
#
# Aim:
# To interface an LED with Raspberry Pi and write a Python program to turn the
# LED ON for1second and OFF for2seconds, continuously.
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

# Extracted and corrected: exp12 pp8-9, photos14(12),(13); BOARD11 = BCM17.
# Only API spelling/case fixed; cleanup handler added. Original1s ON/2s OFF.

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
        sleep(2)
except KeyboardInterrupt:
    PIN.cleanup()

# Expected Output/Result:
# No separate written result/output section is available on these LED pages.
# Expected from the recorded code: LED is ON (1s), LED is OFF (2s), repeatedly.
# This is expected behavior, not a physical test.
