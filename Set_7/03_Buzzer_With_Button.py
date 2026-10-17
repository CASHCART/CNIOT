# Experiment Name: Buzzer with a push button (reconstructed)
# Source status: no exact combined experiment/program page was found.
# Built explicitly from experiment13 buzzer output and experiment14 button input.
#
# Aim:
# Reconstructed from the requested task: sound the buzzer when the button is pressed.
# No original combined aim can be copied because its page is missing.
#
# Required starting theory:
# The original combined introductory theory is unavailable. No invented theory is
# presented as record content. The code reuses the recorded active-low button
# decision and1-second ELSE delay, with the buzzer output replacing the LED.
#
# Components Required:
# No combined original list is available. Assumed from experiments13/14:
# Raspberry Pi3/4, buzzer, push button, breadboard and jumper wires.
# Buzzer type/current/driver and required resistor value remain unspecified.
#
# Connections (explicit reconstructed assumptions):
# - Buzzer control: physical13 (=experiment13 BCM27).
# - Button input: physical11 (=experiment14 BCM17); other side ->GND.
# - GPIO.BOARD, buzzer=13, button=11, internal PUD_UP; pressed=False/LOW.
# - Buzzer ground can use physical6 as recorded in experiment13.
# - Verify actual buzzer rating/driver before connecting an unknown bare load;
#   a driven active module with3.3V-compatible input is a safety assumption only.
# - The exact combined circuit is missing; never apply5V to a GPIO input.
#
# Python Program:

# RECONSTRUCTED because exact buzzer-with-button source is missing.
# Combine exp13 BCM27 output (=physical13) with exp14 BOARD11 button (=BCM17).
# BOARD13 buzzer/button11 are an explicit reconstructed mapping, not a found page.
# Mirrors exp14 original active-low branch and ELSE1s delay; no invented record claim.
# Buzzer rating/type/driver unspecified: check wiring notes before connecting.
import RPi.GPIO as GPIO
import time

buzzer = 13
button = 11
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(button, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(buzzer, GPIO.OUT)
try:
    while True:
        button_state = GPIO.input(button)
        if button_state == False:
            GPIO.output(buzzer, GPIO.HIGH)
        else:
            time.sleep(1)
            GPIO.output(buzzer, GPIO.LOW)
except KeyboardInterrupt:
    GPIO.cleanup()

# Expected Output/Result:
# No original combined output/result page is available. Expected from reconstructed
# code: press ->buzzer HIGH; released branch waits1s then sets LOW. No console
# message. Actual circuit/sound remains physically untested.
