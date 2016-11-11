#include <Keyboard.hpp>
#include <Keymap.hpp>
#include <Ports.hpp>
#include <Screen.hpp>
#include <IRQ.hpp>

#define MAX_STRING_SIZE 1024

unsigned int tmp;
unsigned int entero;
char stringBuffer[MAX_STRING_SIZE];
unsigned int stringPos=0;

void ND::Keyboard::Setup()
{
	
	ND_IRQ_InstallHandler(1,&ND_Keyboard_Handler);

	tmp = 1;
}
void ND::Keyboard::wait()
{

}
unsigned char ND::Keyboard::GetChar()
{
	unsigned char scancode;
	scancode=(unsigned char)ND::Ports::InputB(0x60);
		
	if(scancode & ND_KEYBOARD_KEY_RELEASE)
	{
		return 255;
	}else{
		return en_US[scancode];
	}
}
char* ND::Keyboard::GetString()
{
	while(stringBuffer[stringPos-1]!='\n')
	{
		
	}
	stringPos=0;
	
	return stringBuffer;
}

unsigned int ND::Keyboard::GetInt()
{
	while(stringBuffer[stringPos-1]!='\n')
	{
		
	}
	stringPos=0;
	
	return entero;
}

extern "C"
void ND_Keyboard_Handler(struct regs* r)
{
    unsigned char scancode = ND::Keyboard::GetChar();
    if(scancode!=255)
    {
		ND::Screen::PutChar(scancode);
		stringBuffer[stringPos]=scancode;
		stringPos++;
	}
}
