// practice.cpp: определяет точку входа для консольного приложения.
//



#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <codecvt>
#include <stdlib.h>
#include <cstdio>

using namespace std;
//locale;

struct TALM_GLN {
#pragma pack(1)
	__int16 NOM_KA;  /*НОМЕР КА*/
	__int16 CHAN;    /*ЧАСТОТНЫЙ КАНАЛ;*/
	__int16 HEALTH;  /*ПРИЗНАК ЗДОРОВЬЯ;*/
	float E;          /*!ЭКСЦЕНТРИСИТЕТ*/
	__int32 N_DAY;   /*НОМЕР ДНЯ 4-Х ЛЕТНЕГО ПЕРИОДА*/
	float I_CORR;    /*ПОПРАВКА К НАКЛОНЕНИЮ (РАД)*/
	float LAMBDA;    /*ДОЛГОТА 1-ГО В СУТКАХ ВОСХОДЯЩЕГО УЗЛА
					 (РАД)*/
	float T_LAMBDA;  /*ВРЕМЯ (СЕК) ОТ НАЧАЛА СУТОК 1-ГО ВОСХ.
					 УЗЛА (РАД)*/
	float OMEGA;    /*АРГУМЕНТ ПЕРИГЕЯ (РАД) */
	float DT_DRAC;   /*ПОПРАВКА К ПЕРИОДУ 43200 (СЕК)*/
	float AF1;      /*СКОРОСТЬ УХОДА ВРЕМЕНИ БОРТА (СЕК/СЕК)*/
	float AF0;      /*УХОД ВРЕМЕНИ БОРТА (СЕК)*/
	__int16 CHECK_;  /*КОНТРОЛЬНАЯ СУММА*/
	double MJD;     /* MJD (ТАЙМЕР ПК)*/
};

struct TALM_GPS {
#pragma pack(1)
	__int16 NOM_KA;   //НОМЕР КА
	__int16 HEALTH;   //ПРИЗНАК ЗДОРОВЬЯ
	float E;          //ЭКСЦЕНТРИСИТЕТ
	__int32 TOA;      //ВРЕМЯ ЗАДАНИЯ АЛЬМАНАХА (СЕК)
	float I_ANGLE;    //НАКЛОНЕНИЕ (РАД)
	float OMEGADOT;   //СКОРОСТЬ ПРЯМОГО ВОСХОЖДЕНИЯ (РАД/СЕК)
	double ROOTA;     //SQRT(A), КОРЕНЬ КВ.(МЕТР)
	double OMEGA0;    //ДОЛГОТА ВОСХОДЯЩЕГО УЗЛА (РАД)
	double OMEGA;     //АРГУМЕНТ ПЕРИГЕЯ (РАД)
	double M0;        //СРЕДНЯЯ АНОМАЛИЯ НА ВРЕМЯ ЗАДАНИЯ АЛЬМАНАХА(РАД)
	float AF0;        //УХОД ВРЕМЕНИ БОРТА (СЕК)
	float AF1;        //СКОРОСТЬ УХОДА ВРЕМЕНИ БОРТА (СЕК/СЕК)
	__int16 WNA;      //НОМЕР НЕДЕЛИ АЛЬМАНАХА
	__int16 WN;       //НОМЕР НЕДЕЛИ
	__int32 TOW;      //ВРЕМЯ В СЕКУНДАХ ОТ НАЧАЛА GPS-НЕДЕЛИ
	__int16 CHECK_;   //КОНТРОЛЬНАЯ СУММА
	double MJD;       //MJD (ТАЙМЕР ПК)
};


int main()
{
	TALM_GPS y[25];
	TALM_GLN x[25];
	//fstream y;
	FILE *in;
	
	fopen_s(&in, "C://Users/kenx/source/repos/practice/practice/Альманах/18062700.sag.alm", "rb");
	FILE *tx;
	fopen_s(&tx, "18062700sag.txt","w");
	for (int i = 0; i < 24; i++)
	{
		fseek(in, i * 78, SEEK_SET);
		fread(&y[i], 78, 1, in);
		cout << y[i].NOM_KA<<"_"<< y[i].HEALTH << "_" << y[i].E << "_" << y[i].TOA << "_" << y[i].I_ANGLE << endl;
		
		fwrite(&y[i], 78, 1, tx);
	}
	
	fclose(in);
	FILE *in2;
	fopen_s(&in2, "C://Users/kenx/source/repos/practice/practice/Альманах/18062700.sal.alm", "rb");
	for (int i = 0; i < 24; i++)
	{
		fseek(in2, i * 52, SEEK_SET);
		fread(&x[i], 52, 1, in2);
		cout << x[i].NOM_KA << "_" << x[i].HEALTH << "_" << x[i].E << "_" << x[i].N_DAY << "_" << x[i].I_CORR << endl;

		//fwrite(&x[i], 78, 1, tx);
	}
	


	

	system("pause");


	return 0;
}
