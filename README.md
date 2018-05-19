# catpoo-drive
CATPOO drive code for Arduino

## Recognized Serial Line Commands

This is the minimal amount of commands necessary to implement the
functionality necessary to get the robot moving.

| Serial Command    | I2C  |  Description                                             |
|-------------------|------|----------------------------------------------------------|
| `RESET`           | 0x0 | Halt all movement and reset all internal variables        |
| `TURN d`          | 0x1 | Turn `d` degrees (positive=counter clockwise)             |
| `MOVE x y`        | 0x2 | Move `x` millimeters right, and `y` millimeters forward   |
| `SPEED n`         | 0x4 | How fast should the robot go in millimeters per second    |
| `GET v`           | 0x8 | Get Arduino interval value `v`.                           |

## Thoughts

* Both serial and I2C communication needs to have the same commands.
  Parity of abilities is extremely important.
* Serial communications is only for debugging and can be abandoned
  soon as I get the I2C shit worked out.
* The simplest high level interface should allow me to specify a
  direction with a rotation for holonomic drives.
* Simpler two wheel drives should also be kept in mind. I do want to Have
  an army of cheaper drones to accompany the main bot.
