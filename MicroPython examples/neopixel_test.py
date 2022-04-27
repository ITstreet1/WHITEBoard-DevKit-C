from machine import Pin
from neopixel import NeoPixel
import time

pin = Pin(8, Pin.OUT)   # set GPIO0 to output to drive NeoPixels
np = NeoPixel(pin, 1)   # create NeoPixel driver on GPIO for n pixels

while True:
    np[0] = (255, 0, 0)
    np.write()
    time.sleep(0.5)
    np[0] = (0, 255, 0)
    np.write()
    time.sleep(0.5)
    np[0] = (0, 0, 255)
    np.write()
    time.sleep(0.5)