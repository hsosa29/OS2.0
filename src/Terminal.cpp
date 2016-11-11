#include <Screen.hpp>
#include <Keyboard.hpp>
#include "Terminal.hpp"
#include <String.hpp>

extern "C"  {int speaker_beep();}


void Terminal::Comandos::Version()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,GREEN);
	ND::Screen::PutString("\nProyecto Sistemas Operativo Version 2.0\n");
}

void Terminal::Comandos::Apagar()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,GREEN);
	ND::Screen::PutString("\nApagando el Sistema...\n");	
	//Terminal::Comandos::Apagar_Proc();
	Terminal::Comandos::Outside_Ram();
	
	
}

void Terminal::Comandos::Apagar_Proc()
{
	__asm__ volatile(
		
		/* ".code16 \n" 

		"jmp main \n"

		"Shutdown: \n"
			"mov $0x1000, %ax \n"
			"mov %ax, %ss \n"
			"mov $0xf000, %sp \n"
		    	"mov $0x5307, %ax \n"
		    	"mov $0x0001, %bx \n"
		    	"mov $0x0003, %cx \n"
		    	"int $0x15 \n"
		
		"WaitForEnter: \n"
		    "mov %ah, 0 \n"
		    "int $0x16 \n"
		    "cmp $0x0D, %al \n"
		    "jne WaitForEnter \n"
		    "ret \n"
		
		"main: \n"   
		    "call WaitForEnter \n"
		    "call Shutdown \n" */

		"cli \n"                   
		    	
		"halt: \n"
		    	"hlt \n"                     
    			"jmp     halt \n"
		
	
	);
}

void Terminal::Comandos::Outside_Ram()
{
	__asm__(
	
	"speaker_tone:"
		"mov %cx, %ax;"
		"mov %al, 182;"
		"out %al, $0x43;"
		"mov %ax, %cx;"
		"out %al, $0x42;"
		"mov %al, %ah;"
		"out %al, $0x42;"
		"in $0x61, %al;"
		"or $0x03, %al;"
		"out %al, $0x61;"
		
		"ret"

	"speaker_off:"
		"in $0x61, %al;"
		"and $0xFC, %al;"
		"out %al, $0x61;"
		
		"ret"

	"speaker_beep:"
		"xor %eax,%eax;"
		"mov %ax, 0x0C80;"
		"call speaker_tone;"
		"mov %ax, 2;"
		
		"call speaker_off;"
		
		"ret"

	
	);

	speaker_beep();	
}

void Terminal::Comandos::Sonido()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,GREEN);
	ND::Screen::PutString("\nPreparando tarjeta de sonido...\n");	

	__asm__(
		"xor %eax,%eax;"
		"mov %ax, 0x0C80;"

		"mov %cx, %ax;"
		"mov %al, 182;"
		"out %al, $0x43;"
		"mov %ax, %cx;"
		"out %al, $0x42;"
		"mov %al, %ah;"
		"out %al, $0x42;"
		"in $0x61, %al;"
		"or $0x03, %al;"
		"out %al, $0x61;"

		"mov %ax, 2;"
		);

speaker_beep();

}

void Terminal::Comandos::Beep()
{
	
}

void Terminal::Comandos::Calculadora()
{
	ND::Screen::PutString("\nCalculadora 2.0\n");
	ND::Screen::PutString("\nIngresa el primer numero: ");	
	char* str = 0;
	*str = 0; 
	str = ND::Keyboard::GetString();
	
	int x = ND::Screen::atoi(str);
	
	ND::Screen::PutString("\nIngresa el segundo numero: ");	

	str = 0;
	*str = 0;
	str = ND::Keyboard::GetString();
	
	int y = ND::Screen::atoi(str);
	
	ND::Screen::PutString("\nSuma: ");
	ND::Screen::PutString(ND::String::itoa(x+y));
	ND::Screen::PutString("\nResta: ");
	ND::Screen::PutString(ND::String::itoa(x-y));
	ND::Screen::PutString("\nProducto: ");
	ND::Screen::PutString(ND::String::itoa(x*y));
	ND::Screen::PutString("\nDivision: ");
	ND::Screen::PutString(ND::String::itoa(x/y));
	ND::Screen::PutString("\n");
	

	//Terminal::ComandosCalculadora(valor1, valor2);	
}
void Terminal::Comandos::NoComando()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,RED);
	ND::Screen::PutString("\nComando no existe. Intenta nuevamente\n");
	
}
int Terminal::ComandosCalculadora(int valor1, int valor2)
{
	//ND::Screen::PutString(char*(valor1 + valor2));
}
int Terminal::EjecutarComando(char* script)
{
	if(ND::String::Compare("version\n",script)==0)
	{	
		Terminal::Comandos::Version();
		script = 0;
		*script = 0;
	}
	else if(ND::String::Compare("\n",script)==0)
	{
		Terminal::Comandos::Calculadora();
		script = 0;
		*script = 0;
	}
	else if(ND::String::Compare("apagar\n", script)==0)
	{
		Terminal::Comandos::Apagar();
		script = 0;
		*script = 0;
	}
	else if(ND::String::Compare("sonar\n", script)==0)
	{
		Terminal::Comandos::Sonido();
		script = 0;
		*script = 0;
	}
	else
	{
		Terminal::Comandos::NoComando();
		script = 0;
		*script = 0;
	}

	Terminal::EsperandoComando();
}
int Terminal::EsperandoComando()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,WHITE);
	ND::Screen::PutString("Proyecto SO Shell:-> ");
	char* cmd=ND::Keyboard::GetString();
	Terminal::EjecutarComando(cmd);
	
}
int Terminal::main()
{
	ND::Screen::Clear(BLUE);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND,BLUE);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,WHITE);
	ND::Screen::PutString("Grupo Elementary OS v2.0\nProyecto Sistemas Operativos v2.0\n________________________________________________________________________\n");
	
	
	Terminal::EsperandoComando();
}

