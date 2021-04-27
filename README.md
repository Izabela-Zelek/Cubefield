# README #

This is LAB 14 Project I StarterKit. This project defines an Cube, Vertex and Fragment Shaders, Texture and uses the GLM Math Library to perform transformations. As such its a completed 3D cube project with rotations.
Modify this example and experiment with rotate, scale and translate functions (see https://glm.g-truc.net/0.9.2/api/a00245.html#ga4683c446c8432476750ade56f2537397)


### What is this repository for? ###

* Lab 14 Experiment with a Cube Texturing All Sides Textured

### How do I get set up? ###

* Clone repository
* Ensure `SFML_SDK` environment variable exits
* Ensure SFML Version SFML 2.3.2 Visual C++ 14 (2015) - 32-bit is installed 
http://www.sfml-dev.org/files/SFML-2.3.2-windows-vc14-32-bit.zip "SFML-2.3.2-windows-vc14-32-bit.zip"
* Download extensions wrangler GLEW from http://glew.sourceforge.net/index.html and obtain Binaries for  Windows 32-bit and 64-bit
	* FreeGLUT can be used as an alternative to GLEW http://freeglut.sourceforge.net 
* Set environment variable for GLEW
	* Follow this guide https://support.microsoft.com/en-us/kb/310519
	* Alternatively `SET GLEW_SDK="C:\Users\#####\glew-1.13.0-win32\glew-1.13.0"`
* To check environment variable is set correctly open a command prompt and type `echo %GLEW_SDK%` the path to glew sdk should be show.
* Download GLM Math Library from https://github.com/g-truc/glm/tags
* Set environment variable for GLM
	* Follow this guide https://support.microsoft.com/en-us/kb/310519
	* Alternatively `SET GLM_SDK="C:\Users\#####\glm-0.9.7.2"`
* Select a project default target `x86` when running executable
* If the project builds but does not `xcopy` the required dll's try moving your project to a directory you have full access to, see http://tinyurl.com/SFMLStarter for a guide on post build events.
* Alternatively set the Environment Variable in Configuration Properties | Debugging | Environment to `PATH=%PATH%;%SFML_SDK%\bin;%GLEW_SDK%\bin\Release\Win32` this will ensure DLL's are discoverable when running in debug mode with copying the DLL's to the executable directory

### Cloning Repository ###
* Run GitBash and type the Follow commands into GitBash

* Check Present Working Directory `pwd`

* Change to the C drive or other drive `cd c:`

* Make a projects Directory `mkdir projects`

* Change to the projects directory by `cd projects`

* Clone the project `git clone https://MuddyGames@bitbucket.org/MuddyGames/gameplay-programming-i-lab-14.git`

* Change to the project directory `cd projects gameplay-programming-i-lab14`

* List files that were downloaded `ls`

### Installation and Environment Notes ###
* OpenGL runtime DLL's ( `opengl32.dll` and `glu32.dll`) are located within `C:\Windows\System32` directory on 32-bit and `C:\Windows\SysWOW64` directory on 64-bit

* Header files for GLUT (avoid GLUT use GLEW http://stackoverflow.com/questions/15613978/difference-of-freeglut-vs-glew) `GL.h` and `GLU.h` are located in `C:\Program Files\Microsoft SDKs\Windows\v7.1A\Include` on 32 bit `C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Include` on 64-bit

* Linker library files `OpenGL32.lib` and `GlU32.lib` are located in `C:\Program Files\Microsoft SDKs\Windows\v7.1A\Lib` on 32-bit `C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1A\Lib` on 64-bit

### Who do I talk to? ###

* philip.bourke@itcarlow.ie