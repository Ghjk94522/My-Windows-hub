main: main.o Einstein.o ClientSocket.o  
	g++ -o main mian.o Einstein.o ClientSocket.o
main.o: main.cpp Einstein.h
	g++ -c -o main.o main.cpp
Einstein.o: Einstein.cpp Einstein.h 
	g++ -c -o Einstein.o Einstein.cpp
ClientSocket.o: ClientSocket.cpp ClientSocket.h Define.h
	g++ -c -o ClientSocket.o ClientSocket.cpp

clean: 
	rm *.o main
cleano:
	rm *.o