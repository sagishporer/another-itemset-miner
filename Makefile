CC = g++
CFLAGS = -O3
LIBS = -lm -lc
TARGET  = fim_all

default:	$(TARGET) 

clean:
	rm -rf *~ *.o $(TARGET)

SparseBitArray.o: SparseBitArray.cpp SparseBitArray.h
	$(CC) $(CFLAGS) -c -o SparseBitArray.o SparseBitArray.cpp 

SortedIntArray.o: SortedIntArray.cpp SortedIntArray.h
	$(CC) $(CFLAGS) -c -o SortedIntArray.o SortedIntArray.cpp 

ObjectPool.o: ObjectPool.cpp ObjectPool.h
	$(CC) $(CFLAGS) -c -o ObjectPool.o ObjectPool.cpp 

SimpleBitArray.o: SimpleBitArray.cpp SimpleBitArray.h
	$(CC) $(CFLAGS) -c -o SimpleBitArray.o SimpleBitArray.cpp 

MinerBase.o: MinerBase.cpp MinerBase.h
	$(CC) $(CFLAGS) -c -o MinerBase.o MinerBase.cpp 

Itemset.o: Itemset.cpp Itemset.h
	$(CC) $(CFLAGS) -c -o Itemset.o Itemset.cpp 

Items.o: Items.cpp Items.h
	$(CC) $(CFLAGS) -c -o Items.o Items.cpp 

Item.o: Item.cpp Item.h
	$(CC) $(CFLAGS) -c -o Item.o Item.cpp 

DFSMiner.o: DFSMiner.cpp DFSMiner.h
	$(CC) $(CFLAGS) -c -o DFSMiner.o DFSMiner.cpp 

datatest.o: datatest.cpp data.h
	$(CC) $(CFLAGS) -c -o datatest.o datatest.cpp 

data.o: data.cpp data.h
	$(CC) $(CFLAGS) -c -o data.o data.cpp 

FileWriter.o: FileWriter.cpp FileWriter.h
	$(CC) $(CFLAGS) -c -o FileWriter.o FileWriter.cpp

fim_all: AIM.cpp data.o datatest.o DFSMiner.o Item.o Items.o FileWriter.o Itemset.o MinerBase.o SimpleBitArray.o SparseBitArray.o ObjectPool.o SortedIntArray.o StdAfx.h
	$(CC) $(CFLAGS) -o fim_all AIM.cpp data.o datatest.o DFSMiner.o Item.o FileWriter.o Items.o Itemset.o MinerBase.o SimpleBitArray.o SparseBitArray.o ObjectPool.o SortedIntArray.o $(LIBS)
