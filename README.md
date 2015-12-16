EECS573 final project: Hardware Based Shadow Stack Scheme
=======

This is a shadow stack implementation based on Gem5.

Gem5-stable folder contains our modification to gem5 simulator.

Test_case folder contains the sample programs that overwrite the return address during execution

-----------------------------
1. Build Gem5:

		$ scons build/X86/gem5.opt


2. Run program with System Emulation

		$ build/X86/gem5.opt configs/example/se.py --cpu-type=detailed --caches -c BINARY_EXECUTABLE

5. Compile and run the test case

		$ gcc -fno-stack-protector example.c -static -g  -o example
		$ execstack -s example

