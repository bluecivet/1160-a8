main : Node.cpp Node.h Set.h Set.cpp main.cpp

clean : 
	del *.exe

run : 
	mingw32-make && start cmd /c "main.exe & pause"