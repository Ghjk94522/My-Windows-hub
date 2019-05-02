main: main_ui.o creat.o login.o order.o head1.h
	g++ -o main main_ui.o creat.o login.o order.o head1.h
main_ui.o: main_ui.cpp head1.h
	g++ -c -o main_ui.o main_ui.cpp
creat.o: creat.cpp head1.h
	g++ -c -o creat.o creat.cpp
login.o: login.cpp head1.h
	g++ -c -o login.o login.cpp
order.o: order.cpp head1.h
	g++ -c -o order.o order.cpp
clean:
	rm *.o
 

