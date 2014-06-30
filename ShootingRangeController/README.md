## Shooting Range Controller

This was a project for my local shooting range. 
It basically is a massive breakout board for the Arduino Mega with some smoothing capacitors and reverse voltage protection.
Then there are the relay drivers, the motors to drive the targets backwards and forwards were thee phase and needed 2 relays per motor. These relays were powered by their own 24 volt power supply.
I could not find the code for the Arduino but in a nutshell it was a continuous loop which constantly checked for changes in input and if it changed then drive or stop the motors appropriately.
