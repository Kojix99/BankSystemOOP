#include <iostream>

#include "clsLoginScreen.h"

#include "clsUtil.h"

#include "clsTesting.h"

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