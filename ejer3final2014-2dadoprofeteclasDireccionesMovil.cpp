#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>
#include<string.h>
using namespace std;
using namespace System;
void generamatriz(int **matriz)
{
	int mapa[20][23] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	};
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 23; j++)
		{
			matriz[i][j] = mapa[i][j];
			Console::SetCursorPosition(j, i);
			if (matriz[i][j] == 0)
			{
				Console::ForegroundColor = ConsoleColor::White;
				cout << char(219);
			}
			if (matriz[i][j] == 1)
			{
				Console::ForegroundColor = ConsoleColor::Black;
				cout << char(219);
			}
		}
}
void dibujajugador(int &x, int &y)
{
	Console::SetCursorPosition(x, y);
	Console::BackgroundColor = ConsoleColor::White;
	Console::ForegroundColor = ConsoleColor::Blue;
	cout <<"*";
}

void dibujacaja(int &xc, int &yc)
{
	Console::SetCursorPosition(xc, yc);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << char(219);
}
void eliminarjugador(int &x, int &y)
{
	Console::SetCursorPosition(x, y);
	cout << " ";
}
void eliminarcaja(int &xc, int &yc, int **matriz)
{
	Console::SetCursorPosition(xc, yc);
	cout << " ";
}

void GANASTE() {
	Console::Clear();
	Console::SetCursorPosition(35, 12);
	cout << "ERES UN CAMPEON" << endl;
	_sleep(2000);
	exit(0);
	_getch();
}
void juego(int **matriz, int &x, int &y, int &xc, int &yc)
{
	char tecla;
	dibujajugador(x, y);
	dibujacaja(xc, yc);
	while (1)
	{
		if (kbhit())
		{
			eliminarjugador(x, y);
			tecla = _getch();
			if (tecla == 72)//arriba
			{
				y--;
				if (matriz[y][x] == 1)
				{
					x = 11; y = 8;
					dibujajugador(x, y);
				}
				if (x == xc && y == yc)
				{
					yc--;
					dibujacaja(xc, yc);
				}
			}
			if (tecla == 75)//izquierda
			{
				x--;
				if (matriz[y][x] == 1)
				{
					x = 11; y = 8;
					dibujajugador(x, y);
				}
				if (x == xc && y == yc)
				{
					xc--;
					dibujacaja(xc, yc);
				}
			}
			if (tecla == 77)//derecha
			{
				x++;
				if (matriz[y][x] == 1)
				{
					x = 11; y = 8;
					dibujajugador(x, y);
				}
				if (x == xc && y == yc)
				{
					xc++;
					dibujacaja(xc, yc);
				}

			}
			if (tecla == 80)//abajo
			{
				y++;
				if (matriz[y][x] == 1)
				{
					x = 11; y = 8;
					dibujajugador(x, y);
				}
				if (x == xc && y == yc)
				{
					yc++;
					dibujacaja(xc, yc);
				}
			}
			dibujajugador(x, y);
			if (matriz[yc][xc] == 1)
			{
				xc = 10; yc = 7;
				dibujacaja(xc, yc);
			}
			if (xc== 11 && yc==18)
				GANASTE();
		}
	}
}
int main()
{
	Console::CursorVisible = false;
	int x, y;
	cout << "ingrese posicion inicial x del jugador: "; cin >> x; cout << endl;
	cout << "ingrese posicion inicial y del jugador: "; cin >> y; cout << endl;
	int xc, yc;
	cout << "ingrese posicion inicial x de la caja: "; cin >> xc; cout << endl;
	cout << "ingrese posicion inicial y  de la caja: "; cin >> yc; cout << endl;
	int **matriz = new int*[20];
	for (int i = 0; i < 20; i++)
		matriz[i] = new int[23];
	generamatriz(matriz);
	juego(matriz, x, y, xc, yc);
	for (int i = 0; i < 20; i++)
		delete[]matriz[i];
	delete[]matriz;
	system("pause");
}
