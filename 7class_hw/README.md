
## 7class_hw
The Dashboard_HW.html and arduinocode_LED&IR.cpp files are both part of this. They are meant to create a dashboard which is connected to a WEMOS Mini which has an infrared sensor and an LED connected to it. There are 2 modes which can be controlled via the dashboard: Automatic and manual.

**Manual**
The LED on the dashboard is not controlled by the IR sensor. It completely depends on the position of the toggle switch on the dashboard.

**Automatic**
The toggle switch is not functional. If the IR sensor detects an object nearby, the LED turns on automatically. Otherwise, it remains turned off.

In both cases, the IR sensor output on the dashboard will be present and will turn red if it detects an object nearby.

---
##BUGS

The LED is perpetually on and doesn't get affected by the IR sensor. But at the same time, the pin is transmitting a value of 0 as the LED's status which is wrong, since the LED is on.
