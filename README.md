#LGP IoT Course Work

---
##  HW_Ex4.cpp
The purpose of this code is to control an online status LED as well as display a text output on the serial monitor. Sensors are used to detect whether an area is being covered or not. For example, if there's an important doorway, fire exit or any other entrance that's being blocked, the IR sensor would be able to alert someone about it.

What happens when the program is run:
The IR sensor inputs whether it's being blocked. If it is, then two things happen:
- An online status LED on the IoT platform turns red indicating that the entrance is blocked. This way someone not near the door can be alerted of its status.
- A textual output is created on the serial monitor as well to make it clear what's happening.
