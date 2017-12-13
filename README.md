# catpoo-drive
CATPOO drive code for Arduino

## Recognized Commands

This is the minimal amount of commands necessary to implement the
functionality necessary to get the robot moving. Will probably add more
in the future that use this internally.

| Commands          | Description                                             |
|-------------------|---------------------------------------------------------|
| `RESET`           | Halt all movement and reset all internal variables      |
| `STOP`            | Immediately halt all movemnet                           |
| `TURN d`          | Turn `d` degrees (positive=counter clockwise)           |
| `MOVE x y`        | Move `x` millimeters right, and `y` millimeters forward |
| `SPEED n`         | How fast should the robot go in millimeters per second  |
| `GET v`           | Get Arduino interval value `v`.                         |
