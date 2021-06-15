#include "Application.h"

int main()
{
	Application app("Pixel Game");
	if (app.Construct(160, 144, 4, 4))
		app.Start();

	return 0;
}
