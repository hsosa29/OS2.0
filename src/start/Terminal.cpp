
#include <ND_Screen.hpp>
#include <ND_Keyboard.hpp>
#include "Terminal.hpp"
#include <ND_String.hpp>

void Terminal::Comandos::Version()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("\nProyecto Sistemas Operativo Version 2.0\n");
}

void Terminal::Comandos::Apagar()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("\nApagando el Sistema...\n");	
}

void Terminal::Comandos::Sonido()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_GREEN);
	ND::Screen::PutString("\nPreparando tarjeta de sonido...\n");	
}

void Terminal::Comandos::Calculadora()
{
	ND::Screen::PutString("\nCalculadora 2.0\n");
	ND::Screen::PutString("\nIngresa el primer numero: ");	
	int valor1 = (int)ND::Keyboard::GetString();
	ND::Screen::PutString("\nIngresa el segundo numero: ");	
	int valor2 = (int)ND::Keyboard::GetString();
	
	//Terminal::ComandosCalculadora(valor1, valor2);	
}
void Terminal::Comandos::NoComando()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_RED);
	ND::Screen::PutString("\nComando no existe. Intenta nuevamente\n");
	
}
int Terminal::ComandosCalculadora(int valor1, int valor2)
{
	//ND::Screen::PutString(char*(valor1 + valor2));
}
int Terminal::EjecutarComando(char* script)
{
	if(ND::String::Compare("version\n",script)==0)
		Terminal::Comandos::Version();
	else if(ND::String::Compare("calculadora\n",script)==0)
		Terminal::Comandos::Calculadora();
	else if(ND::String::Compare("apagar\n", script)==0)
		Terminal::Comandos::Apagar();
	else if(ND::String::Compare("sonar\n", script)==0)
		Terminal::Comandos::Sonido();
	else
		Terminal::Comandos::NoComando();
	Terminal::EsperandoComando();
}
int Terminal::EsperandoComando()
{
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Proyecto SO Shell:-> ");
	char* cmd=ND::Keyboard::GetString();
	Terminal::EjecutarComando(cmd);
	
}
int Terminal::main()
{
	ND::Screen::Clear(ND_COLOR_BLUE);
	ND::Screen::SetColor(ND_SIDE_BACKGROUND,ND_COLOR_BLUE);
	ND::Screen::SetColor(ND_SIDE_FOREGROUND,ND_COLOR_WHITE);
	ND::Screen::PutString("Grupo Elementary OS v2.0\nProyecto Sistemas Operativos v2.0\n________________________________________________________________________\n");
	
	
	Terminal::EsperandoComando();
}

