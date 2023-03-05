#pragma once

namespace CC
{
	class Application
	{
	public:
		Application() = default;
		virtual ~Application() = default;

		virtual void OnInit();
		
	protected:
		virtual void OnUpdate();
		virtual void OnQuit();
	};
	
	Application* OnCreate(const struct ConcreteArgs* args);
}
