this program calculates the numbers of primes numbers between a certain range of numbers
stored inside a text file. it does so by spawning multiple in an attempt to accelerate 
the process. this project was developed on a linux machine running Ubuntu

to run this program you must complie the by using the command

			"make"

you then create a text file filled with number between a certain range. that range
can be adjusted by going into the main.cpp file and adjusting the lower and upper bound 
variables then recompilling the source code.
	
		"./Homework3 --createDataFile numbers.txt"

once the data file has been created you can now run the main function of the program by 
using this command

		"./Homework3 --processDataFile numbers.txt"

the program should spawn 2x + 1 amount of threads with x being the numbers of cores avaible
on your machine and an extra thread for io
			
