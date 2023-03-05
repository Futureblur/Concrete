#pragma once

#include "Application.h"

#define CC_ENTRY_POINT(Application) 						\
Application* OnCreate(const struct ConcreteArgs* args)		\
{															\
	return new CC::Application;								\
}

struct ConcreteArgs
{
	int ArgumentCount;
	const char** Arguments;
};

extern int OnCreate(const ConcreteArgs* args);

int main(int argc, const char * argv[])
{
	ConcreteArgs args;
	args.ArgumentCount = argc;
	args.Arguments = argv;

	auto app = new CC::Application;
	app->OnInit();
	delete app;
	
	return 0;
}
