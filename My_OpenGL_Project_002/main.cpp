#include <Windows.h>
#include <GL/GL.h>
#include <iostream>
#include <SDL.h>

bool isAppRunning = true;	// for main loop
SDL_Window* window = nullptr;
SDL_GLContext context = nullptr;

int main(int argc, char* argv[])
{
	//if (SDL_Init(SDL_INIT_EVERYTHING) == -1); 
	//{
	//	std::cout << "Error initializing SDL!\n";
	//}
	std::cout << SDL_Init(SDL_INIT_EVERYTHING)<<std::endl;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);  // 8 bits
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  //1 is true

	// Choose one of them , you can not have both.
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

	// OpenGL Version
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	window = SDL_CreateWindow("OpenGL Window",
					SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					1280, 720, SDL_WINDOW_OPENGL );

	if (!window)
	{
		std::cout<< "Error creating window!\n";
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cout<<"Error creating context!\n";
	}


	//===========================================================================
	// Main Loop
	//===========================================================================
	while (isAppRunning)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		// Update render stuff

		SDL_GL_SwapWindow(window);	// coz we have double buffer enabled.
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}