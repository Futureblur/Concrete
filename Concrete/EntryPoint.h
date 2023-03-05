#pragma once

struct ConcreteArgs
{
	int ArgumentCount;
	const char** Arguments;
};

extern int ConcreteEntryPoint(const ConcreteArgs* args);

int main(int argc, const char * argv[])
{
	ConcreteArgs args;
	args.ArgumentCount = argc;
	args.Arguments = argv;
	
	return ConcreteEntryPoint(&args);
}
