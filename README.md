# WHITEBoard-DevKit-C

![20211028_104507](https://user-images.githubusercontent.com/30090189/139221452-00d8d0d5-d63f-49a0-a7ef-63cbf3fb517c.jpg)

WHITEBoard DevKitC is a development board based on ESP32-C3 module. Exact module is WROOM-02. Development board has all features that this module offers, plus some aditional. In this repo you will find all the data you need to make this board, that include schematic, gerber files, etc. In adition, there are examples for all features this DevKitC  variant offers.

## Features

* ESP32-C3-WROOM-02
  * MCU
    * ESP32-C3 embedded, 32-bit RISC-V single-coreprocessor, up to 160 MHz
    * 384 KB ROM
    * 400 KB SRAM (16 KB for cache)
    * 8 KB SRAM in RTC
  * Wi-Fi
    * IEEE 802.11 b/g/n-compliant
    * Center frequency range of operating channel:2412~2484 MHz
    * Supports 20 MHz, 40 MHz bandwidth in 2.4 GHzband
    * 1T1R mode with data rate up to 150 Mbps
    * Wi-Fi Multimedia (WMM)
    * TX/RX A-MPDU, TX/RX A-MSDU
    * Immediate Block ACK
    * Fragmentation and defragmentation
    * Transmit opportunity (TXOP)
    * Automatic Beacon monitoring (hardware TSF)
    * 4 × virtual Wi-Fi interfaces
    * Simultaneous support for Infrastructure BSS inStation mode, SoftAP mode, Station + SoftAPmode, and promiscuous modeNote that when ESP32-C3 family scans in Stationmode, the SoftAP channel will change along withthe Station channel.
    * Antenna diversity
    * 802.11mc FTM
  * Bluetooth
    * Bluetooth LE: Bluetooth 5, Bluetooth mesh
    * Speed: 125 Kbps, 500 Kbps, 1 Mbps, 2 Mbps
    * Advertising extensions
    * Multiple advertisement sets
    * Channel selection algorithm #2
  * Hardware
    * Interfaces: GPIO, SPI, UART, I2C, I2S, remotecontrol peripheral, LED PWM controller, general DMA controller, TWAI® controller (compatible withISO 11898-1), temperature sensor, SAR ADC
    * 40 MHz crystal oscillator
    * 4 MB SPI flash
    * Operating voltage/Power supply: 3.0~3.6 VDC
    * Operating ambient temperature: –40~85 °C (This is the 85 °C version module)
    * Dimensions: (18.0 × 20.0 × 3.2) mm
* All GPIO pins breaks into two header rows
* UART CP2102 chip with auto reset circuit
* User Buttons
  * BOOT
  * RST
* WS2812C LED
  * WS2812C is fully compatible with WS2812B
  * Operating Currentof 5 mA
  * Built-in signal reshaping circuit
  * Built-in electric reset circuit and power lost reset circuit
  * Send data at speeds of 800 Kbps
  * Scan frequency 2 KHz
  * 256 brightness display
  * 16777216 color
* Li-Po JST connector with MCP73831 charging circuit
* Micro USB UART port
* Micro USB OTG port
* Power switch

![20211028_104524](https://user-images.githubusercontent.com/30090189/139227883-e7e01f09-f225-4e84-8067-8fed0b2a7863.jpg)

## Getting started

WHITEBoard DevKitC is a development board that can be programmed through Arduino IDE. In time of writing this document, there is no support from CircuitPython or MicroPython.

### Arduino IDE C/C++

#### PROG PORT

For Arduino IDE, first you have to add ESP32-C3 support. This can be done by adding V2.0 Boards support:
-https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
in File->Preferences->URL and then install through board manager, or update existing. When done, just select ESP32C3 Dev Module in Boards, proper port and you are good to go. Here you can find some example sketches that will work with hardware on-board. They are not in a form of a library. By plugging into a computer through a PROG micro USB port, the upload will be done without the need to press BOOT or RST buttons.

#### OTG PORT

I haven't noticed any requests for drivers on WIN10. To use OTG PORT to upload sketches all you have to do is to connect DevKitC to a computer through the OTG PORT. There will pop up a short message of Setting up the device (We're setting up "USB JTAG/Serial debug unit"). After a few seconds, another short message Device is ready will pop up ("USB JTAG/Serial debug unit" is set up and ready to go). You should be able to see in Device Manager in Ports a new port - USB Serial Device on some of the ports. All you have to do is select this port in Arduino IDE and upload the sketch. There is a software reset method when uploading a sketch this way, so no need to press the RST button when done.

### CircuitPython

Not supported yet

### MicroPython

#### BETA SUPPORT!

If your choice is a MicroPython, you need to have installed the latest version of Python. To check what version you have, open Command Prompt and type in:

python --version

For erasing and uploading a firmware on ESP32-C3 you need Development mode Esptool, download it by typing:

git clone https://github.com/espressif/esptool.git

cd esptool

pip install -e .

If no problem you should get a message everything is ok. To check if everything is ok, type in:

esptool.py

You should get a list of commands with list of supported chips, in our case esp32c3. The next step is to download a BIN fajl of MicroPython. Go to https://micropython.org/download/esp32c3/ and download BIN fajl on some location on your PC. The next step is to erease Flash of Esp32-C3. To do so connect WHITEBoard DevKitC to a PC with PROG port, and type in:

esptool.py --chip esp32c3 erase_flash

Now it is time to upload the MicroPython firmware to the WHITEBoard DevKitC. To do so check on which COM port is DevKitC (say it is COM7). In prompt type:

esptool.py --chip esp32c3 --port COM7 --baud 460800 write_flash -z 0x0 C:{location}esp32c3-20210902-v1.17.bin

Here you should use the appropriate COM port and appropriate path to a downloaded file. The name of the file might not be as the one here. A version of the software will change in time to come. After successfully uploaded MicroPython unplugs DevKitC and plugs it again through the PROG port.

The next steps are to use your favorite MicroPython editor and program this board. I use Thonny. Select WHITEBoard DevKitC in Thonny by clicking Run->Select Interpreter, and then select proper Port. The name of a code to works automatically has to be main.py. When done, just Save, press Run, and DevKitC will automatically start running the code.

![Untitled](https://user-images.githubusercontent.com/30090189/139534406-d9e01307-9216-455c-9fd7-8b213dcffda6.png)

## Features

### RGB LED

RGB LED is tied to a GPIO8. You can chose between RGB LED or GPIO8 header usage. There is an open solder jumper which you can close in the way of your need. Of course, you can not have both.

### LiPo charging meter

There are two resistors, 22K and 5.6K as a voltage divider. They are tied to a GPIO01, which is Analog pin A0. As for RGB, under WHITEBoard DevKitC, there is a solder jumper. You can choose if you want to use GPIO01 on the header, or to measure battery voltage level.

## Power

For power management, this board uses two ICs. MCP73831 For battery management check the LiPo charging section below.
WHITEBoard DevKitC can be powered up by any of the micro USB connectors. 5V rail is going to the SE5218 voltage regulator. This is an LDO that provides 3.3V@500mA. While testing, I had ZERO issues with stability. But it also means that DevKitC can not directly power up some power-hungry sensors or modules. In such a case, use an external power supply.
There is no dedicated VIN pin to power WHITEBoard DevKitC through pinout. However, pin 5V can be used to power DevKitC with REGULATED 5V DC. Do not use pin 3V3 in a similar manner. However, you CAN NOT charge battery through 5V pin.
The switch under the board is manipulating with the EN pin of the LDO. This way powers up the board. There is a MOSFET for switching the power supply. DevKitC will cut the battery when there is 5V power on micro USBs or 5V pin. Charging the battery remains all the time when there is 5V. The same goes for the power switch position.

## LiPo charging

For Li-Po charging there is the MCP73831 IC. With a resistor R16 of 2K, charging is set to 500mA charging current. By replacing this resistor you can change the charging current. Here is the table:
* 10K - 100mA
* 5K  - 200mA 
* 2K  - 500mA
* 1K  - 1000mA

Onboard there is a JST 2.00mm pitch connector. As JST is NOT standardized, please check the battery polarity. Wrong polarity can destroy the board and/or battery. Supported batteries are standard Li-Ion/Li-Po with 3.7V nominal voltage. You can use a battery of any capacity.

If the project is for use with a battery, there is a switch on the right side that basically switch from VCC to GND on the EN pin of a voltage regulator. This way you can enable or disable power to the BOARD. In case you can not upload the sketch to a WHITEBoard DevKitC, please check the position of this switch. While turned OFF by this switch, you can still charge the battery by any of the micro USB ports.

![20211028_104623](https://user-images.githubusercontent.com/30090189/139232935-1ee0290c-6cb1-4ceb-a267-0687bad1c4c5.jpg)

## Pinout

WHITEBoard DevKitC has a two-row header with 42 pins in total. Here you can find the boards diagram so check it out. As I mention, WHITEBoard DevKitC has all ESP32-C3 pins break out. That is the reason for the size of the board, besides 0805 components and soldering on one side only. To power additional sensors and modules, there are two GND pins and two power pins (5V and 3.3V). There is no VIN pin (check the Power part above). As for special pins, special ones are considered GPIO09 as BOOT pin, GPIO1 (ADC1_0) where voltage divider for battery measurement is tied. There is a jumper selection under the board. I2C pins(GPIO8 and GPIO9), R for Reset, TX and RX for obvious reasons, and  GPIO08. This last one is used for RGB LED. The same goes as for GPIO1. GPIO pins are NOT 5V TOLERANT!!! Use some logic shifter, voltage divider, or OP-AMP when interfacing 5V devices. For interfacing I2C, I2S, SPI, etc. please check the datasheet https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/api-reference/peripherals/i2c.html

* First Row
  * G (GND)
  * R (RST)
  * GPIO4
  * GPIO5
  * GPIO6
  * GPIO7
  * GPIO8 (RGB LED)
  * GPIO9 (BOOT)
  * GPIO10
  * 5V
* Second Row
  * G
  * GPIO0
  * GPIO1 (Battery meter)
  * GPIO2
  * GPIO3
  * GPIO19
  * GPIO18
  * TX
  * RX
  * 3V3

![20211028_104538](https://user-images.githubusercontent.com/30090189/139231991-10e3ccfe-53c6-4f38-8d18-1432bd1ce26c.jpg)

## PROS

* LiPo battery
* RGB LED
* WiFi
* Bluetooth
* OTG and UART micro USB
* Complete GPIO pinout

## CONS

* One Core
* No USB Host

## Dimensions

Dimensions of this board are 28x65.5mm. The hight is 8mm (without headers).

## Disclaimer

WHITEBoard DevKitC is an open-source development board. My small contribution to the community, that gave me so much. Feel free to use and modify as you want. It would be nice to add some credits if you do.
