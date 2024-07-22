download arduino IDE:
https://www.arduino.cc/en/software

add  <USB.h> and <USBHIDGamepad.h> library to arduino ide. how to add library:
https://support.arduino.cc/hc/en-us/articles/5145457742236-Add-libraries-to-Arduino-IDE

add <esp32> in boardm manager to arduino ide.

To flash program to esp32 you first need to set it to boot0 mode.
That is done by shorting bootsel pins together - for example using piece of wire -
And plugging in USB C cable.
Then upload program and disconnect and connect USB cable to reset ESP32.
After that board should connect as USB gamepad (HID device).
