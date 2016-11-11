#ifndef TERMINAL_HPP
#define TERMINAL_HPP

namespace Terminal{
	
		int main();
		int EsperandoComando();
		int EjecutarComando(char* script);
		int IngresoNumero();
		int Calculo(char* valor1, char* valor2);
		int ComandosCalculadora(int valor1, int valor2);
		namespace Comandos{
			void Version();
			void Calculadora();
			void NoComando();
			void Apagar();
			void Sonido();
			void Beep();
			void Apagar_Proc();
			void Outside_Ram();	
	
	}
}

#endif
