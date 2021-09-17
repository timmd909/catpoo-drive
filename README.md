# catpoo-drive

CATPOO drive code for Raspberry Pi

## Purpose

To control and relay information about the robot via REST over port 58008.

## Main Features

1. Web server for providing a REST API for remote control
   (note: the actual user interface a user sees isn't part of this. This is
   only for low level control.
2. Terminal application that displays the internal state and
   tails an internal console log. Will display 7 main sections:
   1. System stats (CPU utilization, temperature, etc)
   2. Wheel motor status (direction and speed)
   3. Desired movement (forward/back, left/right, and rotation)
   4. Network info (connected to internet? and IP addresses of all NICs)
   5. Range finder (front, right, back, and left)
   6. Orientation (acceleration and rotation)
   7. Console log showing the last `n` entries

## Planned Features

1. Basic collision avoidance (ex: if there's no space in front of the robot, don't
   keep moving forward)

## REST API Notes

1. I only need the following things to start:
   1. `$HOSTNAME:58008/stop` Stops all motion immediately
   2. `$HOSTNAME:58008/move` Move and rotate
   3. `$HOSTNAME:58008/info?topics=...` Get info on any of the 7 main topics
      * Having separate URLs `$HOSTNAME:58008/info/system`, `$HOSTNAME:58008/info/wheels`,
	    and so on might be a good idea, if it's not necessary to refresh them
		all at the same time.
      * I'm a bit torn on which way to go
2. Once the above are stable, I want to add:
   1. `$HOSTNAME:58008/fart` Using the speaker attached at the back, play one
      of however many fart sounds.
   2. `$HOSTNAME:58008/speak` Using the speaker at the front of the robot
      and [festival](http://festvox.org/) or anything else I can, have the
	  robot speak the supplied text
3. Optional ideas
   1. `$HOSTNAME:58008/dance` Have the robot perform a predefined routine.
      This may be useful during early development. If so, do this out of order.
   2. `$HOSTNAME:58008/hunt` Wander around like a broken Roomba, looking
      for whatever I can train it. This is where I may dip my toes into
	  OpenCV for some fun examples:
	  * `$HOSTNAME:58008/hunt/cat` Find a cat, and then follow it relentlessly
	  * `$HOSTNAME:58008/hunt/wife` Find wife and speak something, fart, then
	  run away as fast as possible.
	  * `$HOSTNAME:58008/hunt/god` Random walk while looking for for pictures
	    of Nietzsche, and meaning in life.
4. Now would be a good time to research if there's any good REST API
   documentation generators.


## Helpful Pages

* https://raspberrypi-aa.github.io/session2/bash.html
