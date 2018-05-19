# catpoo-drive
CATPOO drive code for Arduino

## Recognized Serial Line Commands

This is the minimal amount of commands necessary to implement the
functionality necessary to get the robot moving.

## Commands

* `0x00` - `RESET`
    * Halt all movement and reset all internal variables

* `0x01` - `ROTATE d`
    * Rotate a certain number of millimeters.
	* Positive = counter-clockwise
	* Negative = clockwise

* `0x02` - `TRANSLATE x y`
    * Move a certain number of millimeters along the X and Y axis
	* Positive X => right
	* Negative X => left
	* Positive Y => forward
	* Negative Y => backward

* `0x03` - `SPEED s`
	* Speed that the `TRANSLATE` and `ROTATE` commands use

* `0X04` - `TURN ds`
	* Begin turning at a particular speed `ds`
	* Positive = counter-clockwise
	* Negative = clockwise

* `0X05` - `MOVE xs ys`
	* Begin moving in a particular direction and speed specified by `xs` and `ys`
	* Positive X => right
	* Negative X => left
	* Positive Y => forward
	* Negative Y => backward

## Thoughts

* Both serial and I2C communication needs to have the same commands.
  Parity of abilities is extremely important.
* Serial communications is only for debugging and can be abandoned
  soon as I get the I2C shit worked out.
* The simplest high level interface should allow me to specify a
  direction with a rotation for holonomic drives.
* Simpler two wheel drives should also be kept in mind. I do want to Have
  an army of cheaper drones to accompany the main bot.
