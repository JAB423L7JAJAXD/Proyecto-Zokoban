#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

//GLOBALES
char mundo1[10][10];
char mundo2[10][10];
char mundo3[10][10];

bool INICIOPARTIDAM1 = false;
bool FINALM1 = false;
bool INICIOPARTIDAM2 = false;
bool FINALM2 = false;
bool INICIOPARTIDAM3 = false;
bool FINALM3 = false;

int PLAZO=0;
int PLAZOC = 0;
char terreno = '.';
char borde = 'X';
char jugador = 'K';
char caja = 'C';
char meta = 'F';
int pasos;
int cont;
int conf;

int Ubic;
int Ubif;
void MostrarMapa(char MAPA[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << MAPA[i][j] << " ";
		}
		cout << endl;
	}
}
bool verificar_metasM1(char MAPA[][10] ) {
	int metas_contadas = 0;
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			if (MAPA[i][j] == meta) {
				metas_contadas++;
				if (!((i == 1 && j == 8) || (i == 1 && j == 1) || (i == 4 && j == 5))) {
					return false;
				}
			}
		}
	}
	if (metas_contadas != 3) {
		return false;
	}
	return true;
}

void buscar_y_reemplazarM1(char MAPA[][10]) {
	// posición de las casillas que no deben modificarse
	

	if (MAPA[4][5]!=meta) 
	{
		if (MAPA[4][5]!=caja)
		{
			if (MAPA[4][5] != jugador)
			{
				MAPA[4][5] = meta;
			}
		}


	}
	if (MAPA[2][1] != meta)
	{
		if (MAPA[2][1] != caja)
		{
			if (MAPA[2][1] != jugador)
			{
				MAPA[2][1] = meta;
			}
		}


	}
	if (MAPA[1][8] != meta)
	{
		if (MAPA[1][8] != caja)
		{
			if (MAPA[1][8] != jugador)
			{
				MAPA[1][8] = meta;
			}
		}


	}
	
	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++)
		{
			if(MAPA[i][j]==meta)
			{
				if (!((i == 1 && j == 8) || (i == 2 && j == 1) || (i == 4 && j == 5)))
				{
					MAPA[i][j] = terreno;
				}
			}
			
		}
	}

	system("cls");
	
	MostrarMapa(MAPA);

	
}
void buscar_y_reemplazarM2(char MAPA[][10]) {
	// posición de las casillas que no deben modificarse

	if (MAPA[4][8] != meta)
	{
		if (MAPA[4][8] != caja)
		{
			if (MAPA[4][8] != jugador)
			{
				MAPA[4][8] = meta;
			}
		}


	}
	if (MAPA[6][8] != meta)
	{
		if (MAPA[6][8] != caja)
		{
			if (MAPA[6][8] != jugador)
			{
				MAPA[6][8] = meta;
			}
		}


	}
	if (MAPA[4][1] != meta)
	{
		if (MAPA[4][1] != caja)
		{
			if (MAPA[4][1] != jugador)
			{
				MAPA[4][1] = meta;
			}
		}


	}
	if (MAPA[1][1] != meta)
	{
		if (MAPA[1][1] != caja)
		{
			if (MAPA[1][1] != jugador)
			{
				MAPA[1][1] = meta;
			}
		}


	}

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++)
		{
			if (MAPA[i][j] == meta)
			{
				if (!((i == 4 && j == 8) || (i == 6 && j == 8) || (i == 4 && j == 1)||(i == 1 && j == 1)))
				{
					MAPA[i][j] = terreno;
				}
			}

		}
	}

	system("cls");

	MostrarMapa(MAPA);


}
void buscar_y_reemplazarM3(char MAPA[][10]) {
	// posición de las casillas que no deben modificarse
	if (MAPA[4][8] != meta)
	{
		if (MAPA[1][8] != caja)
		{
			if (MAPA[1][8] != jugador)
			{
				MAPA[1][8] = meta;
			}
		}


	}
	if (MAPA[5][2] != meta)
	{
		if (MAPA[5][2] != caja)
		{
			if (MAPA[5][2] != jugador)
			{
				MAPA[5][2] = meta;
			}
		}


	}


	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++)
		{
			if (MAPA[i][j] == meta)
			{
				if (!((i == 1 && j == 8) || (i == 5 && j == 2)))
				{
					MAPA[i][j] = terreno;
				}
			}

		}
	}

	system("cls");

	MostrarMapa(MAPA);


}
	


int UbicacionJugadorFila(char MAPA[][10])
{

	if (jugador < 0 || jugador > 99) {
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (MAPA[i][j] == jugador)
			{
				return i;
			}
		}
	}

	return -1;
}
int UbicacionJugadorColumna(char MAPA[][10])
{

	if (jugador < 0 || jugador > 99) {
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (MAPA[i][j] == jugador)
			{
				return j;
			}
		}
	}

	return -1;  // Player not found
}
void IniciarJugador(char MAPA[][10])
{
	MAPA[5][5] = jugador;
}
void CargarMapa(char MAPA[][10])
{

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MAPA[i][j] = terreno;
		}

	}
	cout << endl;
}

void Limites(char MAPA[][10])
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 9) {
				MAPA[i][j] = borde;
			}
		}
	}
	cout << endl;
}
bool Entorno(char MAPA[][10])
{
	if (UbicacionJugadorFila(MAPA) != 0 && UbicacionJugadorFila(MAPA) != 9 && UbicacionJugadorColumna(MAPA) != 0 && UbicacionJugadorColumna(MAPA) != 9) {
		if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] == borde)
		{
			return true;
		}
		else {
			return false;
		}
		if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] == borde)
		{
			return true;
		}
		else {
			return false;
		}
		if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] == borde)
		{
			return true;
		}
		else {
			return false;
		}
		if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA) + 1] == borde)
		{
			return true;
		}
		else {
			return false;
		}
	}
}
bool META(char MAPA[][10])
{
	bool M;
	if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] != meta || MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] != meta || MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] != meta || MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] != meta) {

		M = true;
		if (M == true && PLAZO == 2)
		{
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}




}

int UBIF(char MAPA[][10])
{
	int F;
	if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] == meta)
	{
		F = UbicacionJugadorFila(MAPA) + 1;
		return F;
	}
	if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] == meta)
	{
		F = UbicacionJugadorFila(MAPA) - 1;
		return F;
	}
	
}
int UBIC(char MAPA[][10])
{
	int F;
	if (MAPA[UbicacionJugadorFila(MAPA) ][UbicacionJugadorColumna(MAPA)+1] == meta)
	{
		F = UbicacionJugadorColumna(MAPA) + 1;
		return F;
	}
	if (MAPA[UbicacionJugadorFila(MAPA) ][UbicacionJugadorColumna(MAPA)-1] == meta)
	{
		F = UbicacionJugadorColumna(MAPA) - 1;
		return F;
	}

}


void GuardarMapa(char MAPA [10][10], string nombre_archivo) {
	ofstream archivo(nombre_archivo);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			archivo << MAPA[i][j] << " ";
		}
		archivo << endl;
	}
	archivo.close();
}
void leer_matriz(char MAPA[10][10], string nombre_archivo) {
	ifstream archivo(nombre_archivo);
	if (archivo.is_open()) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				archivo >> MAPA[i][j];
			}
		}
	}
	archivo.close();
}
void remplazar_matriz(char MAPA[10][10], string nombre_archivo) {
	leer_matriz(MAPA, nombre_archivo);
}

bool existe_archivo(string nombre_archivo) {
	ifstream archivo(nombre_archivo);
	return archivo.good();
}
bool borrar_archivo(const string& nombre_archivo) {
	if (remove(nombre_archivo.c_str()) == 0) {
		return true;
	}
}

void movimiento(char MAPA[][10])
{
	char M;
	cout << "Ingrese W==arriba, S==abajo, A==izquierda, D==derecha" << endl;
	cin >> M;
	if (UbicacionJugadorFila(MAPA) != 0 || UbicacionJugadorFila(MAPA) != 9 || UbicacionJugadorColumna(MAPA) != 0 || UbicacionJugadorColumna(MAPA) != 9)
	{
		if (M == 'W')//SUBIR---------------------------------------------------------------------------------------------------------------------------------------------------------
		{
			if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] != caja) {//caja
				if (Entorno) {//VALIDA BORDE
					if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] != borde  ) //verficamos que no choque //TE QUEDASTE ACA
					{
						if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] != meta)//METAAAAAAAAA
						{
							
								if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] == terreno)
								{

									MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;////METAA
									if (PLAZOC != 2)
									{
										if (PLAZO != 1)
										{
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
										else {
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = meta;
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
									}
									else
									{
										MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = meta;
										system("cls");
										MostrarMapa(MAPA);
										PLAZOC = 0;
									}

								}
						    
							
						}
						else 
						{
							if (PLAZO == 0) 
							{
								Ubif = UbicacionJugadorFila(MAPA);
								Ubic = UbicacionJugadorColumna(MAPA);
								MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
								MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;
								system("cls");
								MostrarMapa(MAPA);
								PLAZO++;
							}
						

						}
						
						

					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else {
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}
			}
			else {//caja

				if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] != borde)
				{
					if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] != caja && MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] != meta) ////METAAAA
						{
							if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] == terreno)
							{
								if (PLAZOC != 2 )
								{
									if (PLAZOC == 1)
									{
										if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)]==caja && M != 'W')
										{
											PLAZOC = 0;
										}
										else {

											MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZOC++;
										}

									}
									else
									{
										if (PLAZO == 1)
										{
											MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = meta;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
										else
										{

											MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
										PLAZOC = 0;
									}
								}
								else 
								{
									MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
									MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
									MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = meta;//
									system("cls");
									MostrarMapa(MAPA);
									PLAZOC=0;
								}
							}
						}
						else
						{
							if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] == meta)
							{
								MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
								MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
								MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;//
								system("cls");
								MostrarMapa(MAPA);
								PLAZOC++;
							}
							else
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
							}
						}
					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}

			}
			
		
		
        }
		if (M == 'S')//BAJAR-----------------------------------------------------------------------------------------------------------------------------------------------------
		{
			if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] != caja) {//caja
				if (Entorno) {//validamos borde
					if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] != borde) {
						if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] != meta)
						{
							if (MAPA[UbicacionJugadorFila(MAPA) +1][UbicacionJugadorColumna(MAPA)] == terreno)///METAAAAAAAA
							{
								if (PLAZOC != 2)
								{
									MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
									if (PLAZO != 1)
									{
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;
										system("cls");
										MostrarMapa(MAPA);
									}
									else
									{


										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;
										system("cls");
										MostrarMapa(MAPA);
										PLAZO = 0;

									}
								}
								else 
								{
									MAPA[UbicacionJugadorFila(MAPA)+1][UbicacionJugadorColumna(MAPA)] = jugador;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;
									system("cls");
									MostrarMapa(MAPA);
									PLAZOC = 0;
								}
							}
							
							
						}
						else
						{
							if (PLAZO == 0)
							{
								Ubif = UbicacionJugadorFila(MAPA);
								Ubic = UbicacionJugadorColumna(MAPA);
								MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;
								system("cls");
								MostrarMapa(MAPA);
								PLAZO++;
							}
						}
					}
					else {
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;

					}
				}
				else {
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}
			}
			else {//caja

				if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] != borde)
				{
					if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] != caja && MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] != meta) ////METAAAA
						{
							if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] == terreno)
							{
								if (PLAZOC != 2)
								{
									if (PLAZOC == 1)
									{
										if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] == caja && M != 'S')
										{
											PLAZOC = 0;
										}
										else
										{
											MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZOC++;
										}

									}
									else
									{
										if (PLAZO == 1) 
										{

											MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
										else 
										{
											MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
										PLAZOC = 0;
									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
									MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//
									system("cls");
									MostrarMapa(MAPA);
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] == meta)
							{
								MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
								MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
								system("cls");
								MostrarMapa(MAPA);
								PLAZOC++;
							}
							else
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
							}
						}
					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}

			}
		

		}
		if (M == 'A')//IZQUIERDA ------------------------------------------------------------------------------------------------------------------------------------------------------
		{
			if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] != caja) {//caja
				if (Entorno) {//validamos borde
					if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] != meta)
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] == terreno) //META
							{

								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
								if (PLAZOC != 2)
								{
									if (PLAZO != 1)
									{
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;
										system("cls");
										MostrarMapa(MAPA);
									}
									else {
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = meta;
										system("cls");
										MostrarMapa(MAPA);
										PLAZO = 0;

									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = meta;
									system("cls");
									MostrarMapa(MAPA);
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (PLAZO == 0)
							{
								Ubif = UbicacionJugadorFila(MAPA);
								Ubic = UbicacionJugadorColumna(MAPA);
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;
								system("cls");
								MostrarMapa(MAPA);
								PLAZO++;
							}
						}
					}
					else {
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}
			}
			else {//caja

				if (MAPA[UbicacionJugadorFila(MAPA) ][UbicacionJugadorColumna(MAPA)-2] != borde)
				{
					if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)-2] != caja && MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)-2] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA) ][UbicacionJugadorColumna(MAPA)-2] != meta) ////METAAAA
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)-2] == terreno)
							{
								if (PLAZOC != 2)
								{
									if (PLAZOC == 1)
									{
										if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)-2] == caja && M != 'A')
										{
											PLAZOC = 0;
									    }
										else {
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZOC++;
										}

									}
									else
									{
										if (PLAZO == 1)
										{
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = meta;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
										else
										{
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										
										}
										PLAZO = 0;
									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = meta;//
									system("cls");
									MostrarMapa(MAPA);
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)-2] == meta)
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;//
								system("cls");
								MostrarMapa(MAPA);
								PLAZOC++;
							}
							else
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
							}
						}
					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}

			}
	
		}
		if (M == 'D')//DERECHA----------------------------------------------------------------------------------------------------------------------------------------------------
		{
			if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] != caja) {
				if (Entorno) {//validamos borde
					if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] != borde) 
					{
						if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] != meta) 
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] == terreno) 
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
								if (PLAZOC != 2)
								{
									if (PLAZO != 1)
									{
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//CONDICIONAL
										system("cls");
										MostrarMapa(MAPA);
									}
									else
									{
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//CONDICIONAL
										system("cls");
										MostrarMapa(MAPA);
										PLAZO = 0;

									}
								}
								else {

									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//CONDICIONAL
									system("cls");
									MostrarMapa(MAPA);
									PLAZOC = 0;
								}
							}
						}
						else 
						{
							if (PLAZO == 0)
							{
								Ubif = UbicacionJugadorFila(MAPA);
								Ubic = UbicacionJugadorColumna(MAPA);
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//CONDICIONAL
								system("cls");
								MostrarMapa(MAPA);
								PLAZO++;
							}

						}
					}
					else {
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}
			}
			else {//caja

				if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] != borde)
				{
					if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] != caja && MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)+2] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] != meta) ////METAAAA
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] == terreno)
							{
								if (PLAZOC != 2)
								{
									if (PLAZOC == 1)
									{
										if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] == caja && M != 'D')
										{
											PLAZOC = 0;
									    }
										else {
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZOC++;

										}
										

									}
									else
									{
										if (PLAZO == 1)
										{
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
										else
										{
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											MostrarMapa(MAPA);
											PLAZO = 0;
										}
										PLAZOC = 0;
									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//
									system("cls");
									MostrarMapa(MAPA);
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] == meta)
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
								system("cls");
								MostrarMapa(MAPA);
								PLAZOC++;
							}
							else
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
							}
						}
					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}

			}
		
		}
	}//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


}
void movimiento2(char MAPA[][10])
{
	char M;
	cout << "Ingrese W==arriba, S==abajo, A==izquierda, D==derecha" << endl;
	cin >> M;
	if (UbicacionJugadorFila(MAPA) != 0 || UbicacionJugadorFila(MAPA) != 9 || UbicacionJugadorColumna(MAPA) != 0 || UbicacionJugadorColumna(MAPA) != 9)
	{
		if (M == 'W')//SUBIR---------------------------------------------------------------------------------------------------------------------------------------------------------
		{
			if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] != caja) {//caja
				if (Entorno) {//VALIDA BORDE
					if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] != borde) //verficamos que no choque //TE QUEDASTE ACA
					{
						if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] != meta)//METAAAAAAAAA
						{

							if (MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] == terreno)
							{

								MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;////METAA
								if (PLAZOC != 2)
								{
									if (PLAZO != 1)
									{
										MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;
										system("cls");
										
										PLAZO = 0;
									}
									else {
										MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = meta;
										system("cls");
										
										PLAZO = 0;
									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = meta;
									system("cls");
									
									PLAZOC = 0;
								}

							}


						}
						else
						{
							if (PLAZO == 0)
							{
								Ubif = UbicacionJugadorFila(MAPA);
								Ubic = UbicacionJugadorColumna(MAPA);
								MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
								MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;
								system("cls");
								
								PLAZO++;
							}


						}



					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else {
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}
			}
			else {//caja

				if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] != borde)
				{
					if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] != caja && MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] != meta) ////METAAAA
						{
							if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] == terreno)
							{
								if (PLAZOC != 2)
								{
									if (PLAZOC == 1)
									{
										if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] == caja && M != 'W')
										{
											PLAZOC = 0;
										}
										else {

											MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											
											PLAZOC++;
										}

									}
									else
									{
										if (PLAZO == 1)
										{
											MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = meta;//
											system("cls");
											
											PLAZO = 0;
										}
										else
										{

											MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											
											PLAZO = 0;
										}
										PLAZOC = 0;
									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
									MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
									MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = meta;//
									system("cls");
									
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] == meta)
							{
								MAPA[UbicacionJugadorFila(MAPA) - 2][UbicacionJugadorColumna(MAPA)] = caja;
								MAPA[UbicacionJugadorFila(MAPA) - 1][UbicacionJugadorColumna(MAPA)] = jugador;
								MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = terreno;//
								system("cls");
								
								PLAZOC++;
							}
							else
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
							}
						}
					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}

			}



		}
		if (M == 'S')//BAJAR-----------------------------------------------------------------------------------------------------------------------------------------------------
		{
			if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] != caja) {//caja
				if (Entorno) {//validamos borde
					if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] != borde) {
						if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] != meta)
						{
							if (MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] == terreno)///METAAAAAAAA
							{
								if (PLAZOC != 2)
								{
									MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
									if (PLAZO != 1)
									{
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;
										system("cls");
										
									}
									else
									{


										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;
										system("cls");
										
										PLAZO = 0;

									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;
									system("cls");
									
									PLAZOC = 0;
								}
							}


						}
						else
						{
							if (PLAZO == 0)
							{
								Ubif = UbicacionJugadorFila(MAPA);
								Ubic = UbicacionJugadorColumna(MAPA);
								MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;
								system("cls");
								
								PLAZO++;
							}
						}
					}
					else {
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;

					}
				}
				else {
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}
			}
			else {//caja

				if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] != borde)
				{
					if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] != caja && MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] != meta) ////METAAAA
						{
							if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] == terreno)
							{
								if (PLAZOC != 2)
								{
									if (PLAZOC == 1)
									{
										if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] == caja && M != 'S')
										{
											PLAZOC = 0;
										}
										else
										{
											MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											
											PLAZOC++;
										}

									}
									else
									{
										if (PLAZO == 1)
										{

											MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//
											system("cls");
											
											PLAZO = 0;
										}
										else
										{
											MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
											MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											
											PLAZO = 0;
										}
										PLAZOC = 0;
									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
									MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//
									system("cls");
									
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] == meta)
							{
								MAPA[UbicacionJugadorFila(MAPA) + 2][UbicacionJugadorColumna(MAPA)] = caja;
								MAPA[UbicacionJugadorFila(MAPA) + 1][UbicacionJugadorColumna(MAPA)] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
								system("cls");
							
								PLAZOC++;
							}
							else
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
							}
						}
					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}

			}


		}
		if (M == 'A')//IZQUIERDA ------------------------------------------------------------------------------------------------------------------------------------------------------
		{
			if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] != caja) {//caja
				if (Entorno) {//validamos borde
					if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] != meta)
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] == terreno) //META
							{

								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
								if (PLAZOC != 2)
								{
									if (PLAZO != 1)
									{
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;
										system("cls");
										
									}
									else {
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = meta;
										system("cls");
										
										PLAZO = 0;

									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = meta;
									system("cls");
									
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (PLAZO == 0)
							{
								Ubif = UbicacionJugadorFila(MAPA);
								Ubic = UbicacionJugadorColumna(MAPA);
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;
								system("cls");
								
								PLAZO++;
							}
						}
					}
					else {
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}
			}
			else {//caja

				if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] != borde)
				{
					if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] != caja && MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] != meta) ////METAAAA
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] == terreno)
							{
								if (PLAZOC != 2)
								{
									if (PLAZOC == 1)
									{
										if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] == caja && M != 'A')
										{
											PLAZOC = 0;
										}
										else {
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;//
											system("cls");
											
											PLAZOC++;
										}

									}
									else
									{
										if (PLAZO == 1)
										{
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = meta;//
											system("cls");
											
											PLAZO = 0;
										}
										else
										{
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;//
											system("cls");
											
											PLAZO = 0;

										}
										PLAZO = 0;
									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = meta;//
									system("cls");
									
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] == meta)
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 2] = caja;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) - 1] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = terreno;//
								system("cls");
								
								PLAZOC++;
							}
							else
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
							}
						}
					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}

			}

		}
		if (M == 'D')//DERECHA----------------------------------------------------------------------------------------------------------------------------------------------------
		{
			if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] != caja) {
				if (Entorno) {//validamos borde
					if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] != meta)
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] == terreno)
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
								if (PLAZOC != 2)
								{
									if (PLAZO != 1)
									{
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//CONDICIONAL
										system("cls");
										
									}
									else
									{
										MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//CONDICIONAL
										system("cls");
										
										PLAZO = 0;

									}
								}
								else {

									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//CONDICIONAL
									system("cls");
									
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (PLAZO == 0)
							{
								Ubif = UbicacionJugadorFila(MAPA);
								Ubic = UbicacionJugadorColumna(MAPA);
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//CONDICIONAL
								system("cls");
							
								PLAZO++;
							}

						}
					}
					else {
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}
			}
			else {//caja

				if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] != borde)
				{
					if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] != caja && MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] != borde)
					{
						if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] != meta) ////METAAAA
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] == terreno)
							{
								if (PLAZOC != 2)
								{
									if (PLAZOC == 1)
									{
										if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] == caja && M != 'D')
										{
											PLAZOC = 0;
										}
										else {
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
											
											PLAZOC++;

										}


									}
									else
									{
										if (PLAZO == 1)
										{
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//
											system("cls");
											
											PLAZO = 0;
										}
										else
										{
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
											MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
											system("cls");
										
											PLAZO = 0;
										}
										PLAZOC = 0;
									}
								}
								else
								{
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
									MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = meta;//
									system("cls");
									
									PLAZOC = 0;
								}
							}
						}
						else
						{
							if (MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] == meta)
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 2] = caja;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA) + 1] = jugador;
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = terreno;//
								system("cls");
								
								PLAZOC++;
							}
							else
							{
								MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
							}
						}
					}
					else
					{
						MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
					}
				}
				else
				{
					MAPA[UbicacionJugadorFila(MAPA)][UbicacionJugadorColumna(MAPA)] = jugador;
				}

			}

		}
	}//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------


}

bool FINAL_M1(char MAPA[][10])
{
	if (MAPA[1][8] == caja && MAPA[2][1] == caja && MAPA[4][5] == caja)
	{
		return true;
	}
	else
		return false;
		
		
}
bool FINAL_M2(char MAPA[][10])
{
	if (MAPA[4][8] == caja&& MAPA[6][8] == caja && MAPA[4][1] == caja && MAPA[1][1] == caja)	
		
	{
		return true; 
	}
	else
		return false;


}
bool FINAL_M3(char MAPA[][10])
{
	if (MAPA[1][8] ==caja && MAPA[5][2] == caja)
		
		
	{
		return true;
	}
	else
		return false;


}




int main()
{
	int OP;
	cout << "SUPER MEGA HIPER GENIAL ZOKOBAN" << endl;
	cout << "juego en vivo== 1" << endl;
	cout << "juego en cargado== 2" << endl;
	cout << "borrar juego== 3" << endl;
	cout << "salir== 4" << endl;
	cin >> OP;
	while (OP != 1 && OP != 2 && OP != 3&& OP != 4)
	{
		cout << "ingrese un valor valido" << endl;
		cin >> OP;
	}
	system("cls");
	if (OP == 4)
	{
		return 0;
	}
	if (OP == 3)
	{
		borrar_archivo("currentGameM1.txt");
		borrar_archivo("currentGameM2.txt");
		borrar_archivo("currentGameM3.txt");
	}
	if (OP == 1)
	{
		//ESTO ES MUNDO 1-------------------------------------------------------------------
		CargarMapa(mundo1);
		Limites(mundo1);
		IniciarJugador(mundo1);
		cout << "MUNDO 1  !!!!" << endl;
		mundo1[7][3] = caja;
		mundo1[5][6] = caja;

		mundo1[7][7] = caja;

		mundo1[1][8] = meta;
		mundo1[2][1] = meta;
		mundo1[4][5] = meta;

		mundo1[6][4] = borde;
		mundo1[7][4] = borde;
		mundo1[8][4] = borde;
		mundo1[3][2] = borde;
		mundo1[3][3] = borde;
		mundo1[2][3] = borde;
		mundo1[3][6] = borde;
		mundo1[3][7] = borde;
		mundo1[3][8] = borde;

		MostrarMapa(mundo1);
		if (existe_archivo("currentGameM1.txt"))
		{
			remplazar_matriz(mundo1, ("currentGameM1.txt"));
		}
		if (INICIOPARTIDAM1 != true)
		{
			while (!FINAL_M1(mundo1))
			{

				Entorno(mundo1);
				movimiento(mundo1);
				buscar_y_reemplazarM1(mundo1);
				GuardarMapa(mundo1, "currentGameM1.txt");


			}
		}

		borrar_archivo("currentGameM1.txt");
		cout << "MUNDO 1 COMPLETADO.....FELICITACIONES--------------------------------------------------------------------------" << endl;
		system("pause");
		system("cls");
		//ESTO ES MUNDO 2-------------------------------------------------------------------
		cout << "MUNDO 2   !!!!!" << endl;
		CargarMapa(mundo2);
		Limites(mundo2);
		IniciarJugador(mundo2);

		mundo2[2][4] = caja;
		mundo2[7][2] = caja;
		mundo2[2][6] = caja;
		mundo2[7][4] = caja;

		mundo2[4][8] = meta;
		mundo2[6][8] = meta;
		mundo2[4][1] = meta;
		mundo2[1][1] = meta;

		mundo2[2][1] = borde;
		mundo2[3][2] = borde;
		mundo2[3][1] = borde;
		mundo2[2][2] = borde;
		mundo2[4][3] = borde;
		mundo2[4][2] = borde;
		mundo2[5][2] = borde;

		mundo2[5][8] = borde;
		mundo2[5][7] = borde;
		mundo2[5][6] = borde;
		mundo2[4][6] = borde;
		mundo2[3][6] = borde;
		mundo2[8][6] = borde;
		mundo2[6][6] = borde;

		MostrarMapa(mundo2);

		if (existe_archivo("currentGameM2.txt"))
		{
			remplazar_matriz(mundo2, ("currentGameM2.txt"));
		}
		while (!FINAL_M2(mundo2))
		{

			Entorno(mundo2);
			movimiento(mundo2);
			buscar_y_reemplazarM2(mundo2);
			GuardarMapa(mundo2, "currentGameM2.txt");
		}
		borrar_archivo("currentGameM2.txt");
		cout << "MUNDO 2 COMPLETADO.....FELICITACIONES-------------------------------------------------------------------------------------------" << endl;
		system("pause");
		system("cls");

		//ESTO ES MUNDO 3----------------------------------------------------------------------------------------------------------------
		cout << "MUNDO 3   !!!!!!!!!!!!!!" << endl;
		CargarMapa(mundo3);
		Limites(mundo3);
		IniciarJugador(mundo3);

		mundo3[3][2] = caja;
		mundo3[7][7] = caja;

		mundo3[1][8] = meta;
		mundo3[5][2] = meta;



		mundo3[8][1] = borde;
		mundo3[7][1] = borde;
		mundo3[6][1] = borde;
		mundo3[5][1] = borde;
		mundo3[4][1] = borde;
		mundo3[4][2] = borde;
		mundo3[4][3] = borde;
		mundo3[5][3] = borde;
		mundo3[3][5] = borde;
		mundo3[3][5] = borde;
		mundo3[2][5] = borde;
		mundo3[1][5] = borde;
		mundo3[3][6] = borde;
		mundo3[3][7] = borde;


		mundo3[7][5] = borde;
		mundo3[8][5] = borde;

		mundo3[6][8] = borde;
		mundo3[6][7] = borde;

		mundo3[8][4] = borde;
		
		mundo3[7][4] = borde;
		

		MostrarMapa(mundo3);
		if (existe_archivo("currentGameM3.txt"))
		{
			remplazar_matriz(mundo3, ("currentGameM3.txt"));
		}
		while (!FINAL_M3(mundo3))
		{

			Entorno(mundo3);
			movimiento(mundo3);
			buscar_y_reemplazarM3(mundo3);
			GuardarMapa(mundo2, "currentGameM3.txt");
		}
		borrar_archivo("currentGameM2.txt");
		cout << "MUNDO 3 COMPLETADO.....FELICITACIONES" << endl;

		system("pause");
		system("cls");
		cout << "GRACIAS POR JUGAR AL SUPER ZOKOBAN" << endl;
		cout << "creditos: " << endl;
		cout << "JORGE LUIS ARIAS ALVARADO" << endl << "CI: 30.245.916" << endl;

	}
	if (OP == 2)
	{
		//ESTO ES MUNDO 1-------------------------------------------------------------------
		CargarMapa(mundo1);
		Limites(mundo1);
		IniciarJugador(mundo1);
		cout << "MUNDO 1  !!!!" << endl;
		mundo1[7][3] = caja;
		mundo1[5][6] = caja;

		mundo1[7][7] = caja;

		mundo1[1][8] = meta;
		mundo1[2][1] = meta;
		mundo1[4][5] = meta;

		mundo1[6][4] = borde;
		mundo1[7][4] = borde;
		mundo1[8][4] = borde;
		mundo1[3][2] = borde;
		mundo1[3][3] = borde;
		mundo1[2][3] = borde;
		mundo1[3][6] = borde;
		mundo1[3][7] = borde;
		mundo1[3][8] = borde;

		MostrarMapa(mundo1);
		if (existe_archivo("currentGameM1.txt"))
		{
			remplazar_matriz(mundo1, ("currentGameM1.txt"));
		}
		if (INICIOPARTIDAM1 != true)
		{
			while (!FINAL_M1(mundo1))
			{

				Entorno(mundo1);
				movimiento2(mundo1);
				buscar_y_reemplazarM1(mundo1);
				GuardarMapa(mundo1, "currentGameM1.txt");
				cont++;
				if (cont == 10)
				{
					cout << "Desea ver el mapa?" << endl;
					cout << "1== SI,  2==NO" << endl;
					cin >> conf;
					if (conf == 1)
					{
						MostrarMapa(mundo1);
					}
					while (conf != 1 && conf != 2)
					{
						cout << "ingrese una entrada valida" << endl;
						cin >> conf;
					}
				
				}
			}
		}

		borrar_archivo("currentGameM1.txt");
		cout << "MUNDO 1 COMPLETADO.....FELICITACIONES--------------------------------------------------------------------------" << endl;
		system("pause");
		system("cls");
		//ESTO ES MUNDO 2-------------------------------------------------------------------
		cout << "MUNDO 2   !!!!!" << endl;
		CargarMapa(mundo2);
		Limites(mundo2);
		IniciarJugador(mundo2);

		mundo2[2][4] = caja;
		mundo2[7][2] = caja;
		mundo2[2][6] = caja;
		mundo2[7][4] = caja;

		mundo2[4][8] = meta;
		mundo2[6][8] = meta;
		mundo2[4][1] = meta;
		mundo2[1][1] = meta;

		mundo2[2][1] = borde;
		mundo2[3][2] = borde;
		mundo2[3][1] = borde;
		mundo2[2][2] = borde;
		mundo2[4][3] = borde;
		mundo2[4][2] = borde;
		mundo2[5][2] = borde;

		mundo2[5][8] = borde;
		mundo2[5][7] = borde;
		mundo2[5][6] = borde;
		mundo2[4][6] = borde;
		mundo2[3][6] = borde;
		mundo2[8][6] = borde;
		mundo2[6][6] = borde;

		MostrarMapa(mundo2);

		if (existe_archivo("currentGameM2.txt"))
		{
			remplazar_matriz(mundo2, ("currentGameM2.txt"));
		}
		while (!FINAL_M2(mundo2))
		{

			Entorno(mundo2);
			movimiento2(mundo2);
			buscar_y_reemplazarM2(mundo2);
			GuardarMapa(mundo2, "currentGameM2.txt");
			cont++;
			if (cont == 10)
			{
				cout << "Desea ver el mapa?" << endl;
				cout << "1== SI,  2==NO" << endl;
				cin >> conf;
				if (conf == 1)
				{
					MostrarMapa(mundo2);
				}
				while (conf != 1 && conf != 2)
				{
					cout << "ingrese una entrada valida" << endl;
					cin >> conf;
				}

			}
		}
		borrar_archivo("currentGameM2.txt");
		cout << "MUNDO 2 COMPLETADO.....FELICITACIONES-------------------------------------------------------------------------------------------" << endl;
		system("pause");
		system("cls");

		//ESTO ES MUNDO 3----------------------------------------------------------------------------------------------------------------
		cout << "MUNDO 3   !!!!!!!!!!!!!!" << endl;
		CargarMapa(mundo3);
		Limites(mundo3);
		IniciarJugador(mundo3);

		mundo3[3][2] = caja;
		mundo3[7][7] = caja;

		mundo3[1][8] = meta;
		mundo3[5][2] = meta;



		mundo3[8][1] = borde;
		mundo3[7][1] = borde;
		mundo3[6][1] = borde;
		mundo3[5][1] = borde;
		mundo3[4][1] = borde;
		mundo3[4][2] = borde;
		mundo3[4][3] = borde;
		mundo3[5][3] = borde;
		mundo3[3][5] = borde;
		mundo3[3][5] = borde;
		mundo3[2][5] = borde;
		mundo3[1][5] = borde;
		mundo3[3][6] = borde;
		mundo3[3][7] = borde;


		mundo3[7][5] = borde;
		mundo3[8][5] = borde;

		mundo3[6][8] = borde;
		mundo3[6][7] = borde;

		mundo3[8][4] = borde;
		
		mundo3[7][4] = borde;
		

		MostrarMapa(mundo3);
		if (existe_archivo("currentGameM3.txt"))
		{
			remplazar_matriz(mundo3, ("currentGameM3.txt"));
		}
		while (!FINAL_M3(mundo3))
		{

			Entorno(mundo3);
			movimiento2(mundo3);
			buscar_y_reemplazarM3(mundo3);
			GuardarMapa(mundo2, "currentGameM3.txt");
			cin >> conf;
			if (conf == 1)
			{
				MostrarMapa(mundo3);
			}
			while (conf != 1 && conf != 2)
			{
				cout << "ingrese una entrada valida" << endl;
				cin >> conf;
			}

		}
		borrar_archivo("currentGameM2.txt");
		cout << "MUNDO 3 COMPLETADO.....FELICITACIONES" << endl;

		system("pause");
		system("cls");
		cout << "GRACIAS POR JUGAR AL SUPER ZOKOBAN" << endl;
		cout << "creditos: " << endl;
		cout << "JORGE LUIS ARIAS ALVARADO" << endl << "CI: 30.245.916" << endl;

	}
	
	




	return 0;
}
