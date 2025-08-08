/********************************************************************
 * Project: Banking Management System
 * Author : Sohail Zoraibi
 * Date   : June 27, 2025
 * Description:
 *   A simple console-based banking system in C++ that manages users,
 *   clients, permissions, and transactions with file storage.
 ********************************************************************/


#include <iostream>

#include "clsLoginScreen.h"
#include "clsUtil.h"

using namespace std;


int main() {
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
}
