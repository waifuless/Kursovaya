#pragma once
#include <fstream>
#include <iostream>
#include <conio.h>
#include "sha256.h"

class Authorization
{
public:
	static bool isUserExist(const char* fileName);
	static bool createAccount(const char* fileName);
	static bool singIn(const char* fileName);
};

