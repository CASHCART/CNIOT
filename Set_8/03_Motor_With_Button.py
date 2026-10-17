# Experiment Name: Interface motor using relay with Raspberry Pi (experiment16)
# Source: photos at8.42.14PM (18),(19), page16 + continuation.
# The heading says relay; the listed SG90 and actual PWM code are for a servo.
#
# Aim:
# Interface motor using relay with Raspberry Pi; write a program to turn on motor.
#
# Required starting theory:
# No separate introductory theory/principle paragraph appears before the code.
# The record supplies components and connections below. The code uses50Hz PWM,
# with all five explicit duty stages preserved; it does not operate a relay.
#
# Components Required:
# - Raspberry Pi with screen, keyboard and mouse (model unspecified here)
# - SG90 servo
# - Jumper wires
#
# Connections (as actually written in the record):
# - Motor brown ->GND.
# - Motor red ->5V.
# - Motor yellow ->physical pin10.
# - Push button: one leg ->GND pin39, other ->physical pin40.
#
# Unresolved connection conflict:
# The actual code says GPIO.BCM, servo=18 and button=17. Those map to physical
# pins12 and11, respectively, and conflict with the written pins10 and40.
# Both are reported faithfully; resolve the actual lab wiring before execution.
# The button is used in the code/connections but omitted from the component list.
#
# Safety clarification (added, not record theory):
# Use an external servo supply rated for the actual unit, sharing ground with Pi;
# GPIO carries the signal, never motor power. The original duty range2.5..12.5%
# at50Hz means0.5..2.5ms pulses; confirm safe endpoints on the actual servo.
# The printed180-degree statement is not a verified angle calibration.
#
# Python Program:

# Extracted and corrected: exp16 p16 + continuation, photos14(18),(19).
# Preserve ORIGINAL BCM18/17, PWM50Hz, start2.5, five duties and1s waits.
# API capitalization/pull_up_down spelling corrected; ambiguous handwritten
# indentation normalized so the five consecutive stages belong to a press.
# Record prose physical10/40 CONFLICTS with code BCM18/17 (=physical12/11).
# Study transcription: calibrate actual servo endpoints and confirm wiring,
# external rated power + common ground before hardware execution.
# Printed180 is original text, NOT a verified measured angle.
import RPi.GPIO as GPIO
import time

servo = 18
button = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(button, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(servo, GPIO.OUT)
pwm = GPIO.PWM(servo, 50)
pwm.start(2.5)
try:
    while True:
        if GPIO.input(button) == 0:
            pwm.ChangeDutyCycle(2.5)
            time.sleep(1)
            pwm.ChangeDutyCycle(5)
            time.sleep(1)
            pwm.ChangeDutyCycle(7.5)
            time.sleep(1)
            pwm.ChangeDutyCycle(10)
            time.sleep(1)
            print("Servo at 180")
            pwm.ChangeDutyCycle(12.5)
            time.sleep(1)
except KeyboardInterrupt:
    pwm.stop()
    GPIO.cleanup()

# Expected Output/Result:
# Original output written on the continuation: Servo at180.
# The code prints this during its five-stage sequence. The actual angle is not
# measured/verified. Ambiguous indentation of the final two stages is normalized
# into the pressed branch, as disclosed in the source comments. Not physically tested.
