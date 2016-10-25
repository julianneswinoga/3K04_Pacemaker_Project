# 3K04_Pacemaker_Project

## Team TiC++ToC

Group Members:
* Cameron Swinoga
* Dillon Mulcahy
* Mackenzie Wiens
* Ricco Lam
* Nicholas Amorim
* Aleks Mercik
* Peter LaRue

## Compiling Instructions:

- Download & install [Cygwin](https://cygwin.com/install.html)
	- Make sure to install the `make` package
- Download & install [GNU Arm toolchain](https://launchpad.net/gcc-arm-embedded)
	- Add the $(install_dir)/bin to your system path (Use the checkbox at the end of the install)
- Open Cygwin and cd into the project
- Type `make`
	- A folder called `.build` should appear, with a `*.bin` file in it
- Type `make load MBED=$(MBED_location)`, where `$(MBED_location)` is the location of where the MBED flash is loaded
	- `$(MBED_location)` defaults to `/cygdrive/e`
	- This will load the program binary onto the ARM board
- Press the reset button