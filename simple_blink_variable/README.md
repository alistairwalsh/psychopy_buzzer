### Psychopy

/dev/cu.usbmodem000001 should be changed to the usb port that the Arduino is connected to

The Arduino is getting three values each run, stim1 time, stim2 time and ISI.

a range of values from 100 to 5000 in steps of 300 is created at the start of the experiment.

blank = '0,0,1000' sets the Arduino to display for 0 and wait 1000 between setting, to create an 'off' state.

The array of values is shuffled at the start of each routine and the first 2 values are used as stimulus times. ISI is set to 100.

### Arduino

The loop is triggered when there is information in the serial port.
It reads three values and then flashes the LEDs rapidly to indicate it has received new values.

It will then display the stim1 and stim2 values alternately with the ISI value between until more information appears at the serial port.




