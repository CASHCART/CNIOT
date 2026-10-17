# Experiment Name: Interface Buzzer with Raspberry Pi (experiment13)
# Source: photos at8.42.14PM (14),(15), record pages10-11.
#
# Aim:
# Interface Buzzer with Raspberry Pi, write a program to display a beep message
# whenever buzzer makes a sound.
#
# Required starting theory:
# No separate introductory theory/principle paragraph appears before the code.
# The record supplies the aim, components and connections reproduced here.
# The actual record program prints Buzzer is ON/OFF, with no literal Beep print;
# those original messages and HIGH/LOW behavior are preserved below.
#
# Components Required:
# - Raspberry Pi4
# - Breadboard
# - Buzzer
# - Jumper wires
# - Resistor (value not specified)
#
# Connections:
# - Buzzer positive leg (long) ->GPIO27 (physical pin13).
# - Buzzer negative leg (short) ->GND pin6.
# - GPIO.BCM numbering is used;27 does not mean physical pin27.
# - Missing record details: active/passive type, model, current rating, resistor
#   value and driver circuit. The written connection is reported, not verified.
# - Safety clarification: confirm rating/driver before attaching a bare buzzer
#   load. A3.3V-compatible driven active-buzzer module can receive the logic signal,
#   but such a module is an assumption, not a component specified by the record.
#
# Python Program:

# Extracted and corrected: exp13 pp10-11, photos14(14),(15).
# Original BCM27, HIGH/LOW, messages and1s/2s delays retained. No added Beep message.
# False capitalization fixed; Ctrl+C cleanup handler added.
# Record's bare-buzzer wiring is unverified: type/current/driver not specified.
# See Connections above before connecting an unknown buzzer load to GPIO.

import RPi.GPIO as GPIO
from time import sleep

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(27, GPIO.OUT, initial=GPIO.LOW)
try:
    while True:
        GPIO.output(27, GPIO.HIGH)
        print("Buzzer is ON")
        sleep(1)
        GPIO.output(27, GPIO.LOW)
        print("Buzzer is OFF")
        sleep(2)
except KeyboardInterrupt:
    GPIO.cleanup()

# Expected Output/Result:
# No separate written result/output section is available on these buzzer pages.
# Expected from code: Buzzer is ON for1s, Buzzer is OFF for2s, repeatedly.
# Actual sound depends on the unspecified buzzer type/driver. Not physically tested.
