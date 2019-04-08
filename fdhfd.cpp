include <windows.h>
#pragma comment(lib, "Winmm.lib")  
          
int main(int argc, char *argv[])
{
	mciSendString("play Data\\1.wav", 
	NULL,   
	0,  
	NULL);                              
    Sleep(50000);
	return 0;
}
