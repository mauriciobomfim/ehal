= Ehal =
:Author: Marcelo Politzer Couto
:Email: <mpolitzer.c@gmail.com>
:Date: Sat Sep 11 17:08:39 UTC 2010
:Author Initials: MPC
:Revision: 0.1

== Introduction ==

Ehal stands for Embedded Hardware Abstraction Layer, the goal of the project
is to create a simple to use hardware interfaces to the various
architectures and MCUs available in the market.

That will make possible create a driver only once and reuse it in any of the
supported hardware by the ehal. This second step is planed to be called
genlib - Generic Lib.

But for that...

== Roadmap ==

- Finish ARCH and MCU independent building process.
- Create the abstract interfaces for MCU peripherals.
- Installation to make the various tool chains find the libs and headers.
- Find people to help with the project.
- Create drivers with the unified API for common HW like: displays, RTCs,
  etc.
- God knows....

== Planned Architectures and MCUs ==

|===========================================================================
|avr:		|attinys 25, 45, 85, atmegas: 8, 16, 32, 88, 48, 168, 128
|msp430:	|?
|arm7:		|lpc2101 to lpc2106, str711fr2, ...
|arm9:		|?
|arm-cortex-m3:	|?
|===========================================================================
