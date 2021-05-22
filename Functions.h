#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include "studentData.h"
#include <cmath>
using namespace std;
void DataInitialization();
void DataEntry();
void DataReading(string fileName);
void Print(string fileName);
bool DataCleaning();
void DataChange();
void Copy();
int AmountOfData();	
void DeleteData();
void AddData();
void SaveData(string fileName);
void DataReading(Data* (&d), int& n);
void Print(Data* d, int& n);
void SaveData(Data* d, int n);
void SortingData(Data* d, int n);
float AverageMark(Data* d, int n);