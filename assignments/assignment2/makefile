program.exe: runminers.o minermgr.o Miner.o GenericMiner.o WaterMiner.o SodiumChlorideMiner.o IronMiner.o SiliconMiner.o MagnesiumPotassiumMiner.o
	g++ -o program.exe runminers.o minermgr.o Miner.o GenericMiner.o WaterMiner.o SodiumChlorideMiner.o IronMiner.o SiliconMiner.o MagnesiumPotassiumMiner.o

runminers.o: runminers.cpp minermgr.h
	g++ -c -std=c++11 runminers.cpp

minermgr.o: minermgr.cpp minermgr.h WaterMiner.h SodiumChlorideMiner.h IronMiner.h SiliconMiner.h MagnesiumPotassiumMiner.h
	g++ -c -std=c++11 minermgr.cpp

Miner.o: Miner.cpp Miner.h
	g++ -c -std=c++11 Miner.cpp

GenericMiner.o: GenericMiner.cpp GenericMiner.h
	g++ -c -std=c++11 GenericMiner.cpp

WaterMiner.o: WaterMiner.cpp WaterMiner.h Miner.h
	g++ -c -std=c++11 WaterMiner.cpp

SodiumChlorideMiner.o: SodiumChlorideMiner.cpp SodiumChlorideMiner.h GenericMiner.h
	g++ -c -std=c++11 SodiumChlorideMiner.cpp

IronMiner.o: IronMiner.cpp IronMiner.h GenericMiner.h
	g++ -c -std=c++11 IronMiner.cpp

SiliconMiner.o: SiliconMiner.cpp SiliconMiner.h GenericMiner.h
	g++ -c -std=c++11 SiliconMiner.cpp

MagnesiumPotassiumMiner.o: MagnesiumPotassiumMiner.cpp MagnesiumPotassiumMiner.h GenericMiner.h
	g++ -c -std=c++11 MagnesiumPotassiumMiner.cpp

.phony: run
run: program.exe
	./program.exe 1000

.phony: clean
clean:
	rm program.exe *.o
