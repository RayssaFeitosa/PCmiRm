all: ReadFiles.o MiRNATargetMap.o Target.o MiRNA.o main.o
	g++ -std=c++11 -o identify_modules ReadFiles.o MiRNATargetMap.o Target.o MiRNA.o main.o
	
main.o: main.cpp 
	g++ -std=c++11 -c -Wall -g main.cpp

MiRNA.o: MiRNA.h MiRNA.cpp
	g++ -std=c++11 -c -Wall -g MiRNA.cpp

Target.o: Target.h Target.cpp 
	g++ -std=c++11 -c -Wall -g Target.cpp
	
MiRNATargetMap.o: MiRNATargetMap.h MiRNATargetMap.cpp
	g++ -std=c++11 -c -Wall -g MiRNATargetMap.cpp

ReadFiles.o: ReadFiles.h ReadFiles.cpp
	g++ -std=c++11 -c -Wall -g ReadFiles.cpp

clean:
	 rm -rf *.o identify_modules

