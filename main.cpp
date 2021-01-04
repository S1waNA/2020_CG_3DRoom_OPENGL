#include<iostream>
#include<vector>

#define GLEW_STATIC
#include<GL/glew.h>	
#include<GLFW/glfw3.h>
#include"Shader.h"

#include "Camera.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#define hex 0.8660254037844386f

float vertices1[] = {//huaji cube
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
};

float vertices2[] = {//room
	-2.0f, -0.5f, -1.2f,  0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
	 2.0f, -0.5f, -1.2f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
	 2.0f,  0.5f, -1.2f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f,
	 2.0f,  0.5f, -1.2f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f,
	-2.0f,  0.5f, -1.2f,  0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
	-2.0f, -0.5f, -1.2f,  0.0f, 0.0f, 0.0f,  0.0f, 1.0f,

	-2.0f, -0.5f,  1.2f,  0.0f, 0.0f, 0.0f,  0.0f,  -1.0f,
	 2.0f, -0.5f,  1.2f,  1.0f, 0.0f, 0.0f,  0.0f,  -1.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 1.0f, 0.0f,  0.0f,  -1.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 1.0f, 0.0f,  0.0f,  -1.0f,
	-2.0f,  0.5f,  1.2f,  0.0f, 1.0f, 0.0f,  0.0f,  -1.0f,
	-2.0f, -0.5f,  1.2f,  0.0f, 0.0f, 0.0f,  0.0f,  -1.0f,
	 			   
	-2.0f,  0.5f,  1.2f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	-2.0f,  0.5f, -1.2f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	-2.0f, -0.5f, -1.2f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	-2.0f, -0.5f, -1.2f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	-2.0f, -0.5f,  1.2f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	-2.0f,  0.5f,  1.2f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 			   
	 2.0f,  0.5f,  1.2f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	 2.0f,  0.5f, -1.2f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	 2.0f, -0.5f, -1.2f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	 2.0f, -0.5f, -1.2f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	 2.0f, -0.5f,  1.2f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	 
	 /*
	-2.0f, -0.5f, -1.2f,  0.0f, 1.0f, 0.0f, 1.0f,  0.0f,
	 2.0f, -0.5f, -1.2f,  1.0f, 1.0f, 0.0f, 1.0f,  0.0f,
	 2.0f, -0.5f,  1.2f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f,
	 2.0f, -0.5f,  1.2f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f,
	-2.0f, -0.5f,  1.2f,  0.0f, 0.0f, 0.0f, 1.0f,  0.0f,
	-2.0f, -0.5f, -1.2f,  0.0f, 1.0f, 0.0f, 1.0f,  0.0f,
	 */
	 	
	/*
	-2.0f,  0.5f, -1.2f,  0.0f, 1.0f, 0.0f,  -1.0f,  0.0f,
	 2.0f,  0.5f, -1.2f,  1.0f, 1.0f, 0.0f,  -1.0f,  0.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 0.0f, 0.0f,  -1.0f,  0.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 0.0f, 0.0f,  -1.0f,  0.0f,
	-2.0f,  0.5f,  1.2f,  0.0f, 0.0f, 0.0f,  -1.0f,  0.0f,
	-2.0f,  0.5f, -1.2f,  0.0f, 1.0f, 0.0f,  -1.0f,  0.0f
	*/
};

float vertices3[] = {//TVscreen
	-0.7f, -0.5f, -0.08f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.7f, -0.5f, -0.08f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.7f,  0.5f, -0.08f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 0.7f,  0.5f, -0.08f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.7f,  0.5f, -0.08f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.7f, -0.5f, -0.08f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,

	-0.7f, -0.5f,  0.08f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.7f, -0.5f,  0.08f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.7f,  0.5f,  0.08f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 0.7f,  0.5f,  0.08f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.7f,  0.5f,  0.08f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.7f, -0.5f,  0.08f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,

	-0.7f,  0.5f,  0.08f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.7f,  0.5f, -0.08f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.7f, -0.5f, -0.08f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.7f, -0.5f, -0.08f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.7f, -0.5f,  0.08f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.7f,  0.5f,  0.08f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,

	 0.7f,  0.5f,  0.08f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.7f,  0.5f, -0.08f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.7f, -0.5f, -0.08f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.7f, -0.5f, -0.08f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.7f, -0.5f,  0.08f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.7f,  0.5f,  0.08f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,

	-0.7f, -0.5f, -0.08f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.7f, -0.5f, -0.08f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.7f, -0.5f,  0.08f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 0.7f, -0.5f,  0.08f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.7f, -0.5f,  0.08f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.7f, -0.5f, -0.08f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,

	-0.7f,  0.5f, -0.08f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.7f,  0.5f, -0.08f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.7f,  0.5f,  0.08f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 0.7f,  0.5f,  0.08f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.7f,  0.5f,  0.08f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.7f,  0.5f, -0.08f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
};

float vertices4[] = {//tvbase
	-0.5f, -0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.0f,  0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,

	-0.5f, -0.5f, -0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, -0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.0f,  0.5f, -0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,

	-0.5f, -0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.0f,  0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,

	-0.5f, -0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.0f,  0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.0f,  0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,

	 0.5f, -0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.0f,  0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,

	 0.5f, -0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.0f,  0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.0f,  0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,

	-0.5f, -0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 
	-0.5f, -0.5f, 0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f,
	 0.5f, -0.5f,-0.05f, 1.0f,1.0f, 0.0f, 0.0f, 1.0f
};

float vertices5[] = {//bed
	-0.5f, -0.1f, -1.0f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.5f, -0.1f, -1.0f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.5f,  0.1f, -1.0f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 0.5f,  0.1f, -1.0f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.5f,  0.1f, -1.0f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.5f, -0.1f, -1.0f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,

	-0.5f, -0.1f,  1.0f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.5f, -0.1f,  1.0f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.5f,  0.1f,  1.0f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 0.5f,  0.1f,  1.0f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.5f,  0.1f,  1.0f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.5f, -0.1f,  1.0f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,

	-0.5f,  0.1f,  1.0f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.1f, -1.0f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.1f, -1.0f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.1f, -1.0f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.1f,  1.0f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.1f,  1.0f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,

	 0.5f,  0.1f,  1.0f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.5f,  0.1f, -1.0f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.1f, -1.0f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.1f, -1.0f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.1f,  1.0f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.5f,  0.1f,  1.0f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,

	-0.5f, -0.1f, -1.0f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.1f, -1.0f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.1f,  1.0f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.1f,  1.0f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.5f, -0.1f,  1.0f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.5f, -0.1f, -1.0f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,

	-0.5f,  0.1f, -1.0f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.1f, -1.0f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.1f,  1.0f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.1f,  1.0f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.5f,  0.1f,  1.0f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.5f,  0.1f, -1.0f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
};

float vertices6[] = {//fan blade
	-0.25f, -1.0f, 0.0f, 1.0f,1.0f, 0.0f, 1.0f, 0.0f,
	 0.25f, -1.0f, 0.0f, 0.0f,1.0f, 0.0f, 1.0f, 0.0f,
	 0.0f,  0.0f, 0.0f, 1.0f,0.0f,  0.0f, 1.0f, 0.0f

	 /*
	-0.25f, -0.5f, -0.05f, 1.0f,1.0f,
	 0.25f, -0.5f, -0.05f, 1.0f,1.0f,
	 0.0f,  0.5f, -0.05f, 1.0f,1.0f,

	-0.25f, -0.5f, 0.05f, 1.0f,1.0f,
	-0.25f, -0.5f,-0.05f, 1.0f,1.0f,
	 0.0f,  0.5f, 0.05f, 1.0f,1.0f,

	-0.25f, -0.5f,-0.05f, 1.0f,1.0f,
	 0.0f,  0.5f,-0.05f, 1.0f,1.0f,
	 0.0f,  0.5f, 0.05f, 1.0f,1.0f,

	 0.25f, -0.5f, 0.05f, 1.0f,1.0f,
	 0.25f, -0.5f,-0.05f, 1.0f,1.0f,
	 0.0f,  0.5f,-0.05f, 1.0f,1.0f,

	 0.25f, -0.5f, 0.05f, 1.0f,1.0f,
	 0.0f,  0.5f, 0.05f, 1.0f,1.0f,
	 0.0f,  0.5f,-0.05f, 1.0f,1.0f,

	-0.25f, -0.5f, 0.05f, 1.0f,1.0f,
	 0.25f, -0.5f, 0.05f, 1.0f,1.0f,
	 0.25f, -0.5f,-0.05f, 1.0f,1.0f,

	-0.25f, -0.5f, 0.05f, 1.0f,1.0f,
	-0.25f, -0.5f,-0.05f, 1.0f,1.0f,
	 0.25f, -0.5f,-0.05f, 1.0f,1.0f,
	 */
};

float vertices7[] = {//hexagon
	0.5f, hex, 0.0f,  0.0f,0.0f, 0.0f, 0.0f, 1.0f,
   -0.5f, hex, 0.0f,  1.0f,0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f, 1.0f,

	0.5f, -hex, 0.0f,  0.0f,0.0f, 0.0f, 0.0f, 1.0f,
   -0.5f, -hex, 0.0f,  1.0f,0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f, 1.0f,

	-0.5f, hex, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	-1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f, 1.0f,

	0.5f, hex, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f, 1.0f,

	-0.5f, -hex, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	-1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f, 1.0f,

	0.5f, -hex, 0.0f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f,1.0f, 0.0f, 0.0f, 1.0f
};

float vertices8[] = {//door
	-0.05f, -1.0f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.05f, -1.0f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.05f,  1.0f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 0.05f,  1.0f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.05f,  1.0f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.05f, -1.0f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,

	-0.05f, -1.0f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.05f, -1.0f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.05f,  1.0f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 0.05f,  1.0f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.05f,  1.0f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.05f, -1.0f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,

	-0.05f,  1.0f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.05f,  1.0f, -0.5f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.05f, -1.0f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.05f, -1.0f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.05f, -1.0f,  0.5f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.05f,  1.0f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,

	 0.05f,  1.0f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.05f,  1.0f, -0.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.05f, -1.0f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.05f, -1.0f, -0.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.05f, -1.0f,  0.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.05f,  1.0f,  0.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,

	-0.05f, -1.0f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.05f, -1.0f, -0.5f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.05f, -1.0f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 0.05f, -1.0f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.05f, -1.0f,  0.5f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.05f, -1.0f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,

	-0.05f,  1.0f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.05f,  1.0f, -0.5f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.05f,  1.0f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 0.05f,  1.0f,  0.5f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.05f,  1.0f,  0.5f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.05f,  1.0f, -0.5f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
};

float vertices9[] = {//pillow
	-0.75f, -0.2f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 0.75f, -0.2f, -0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	-0.75f,  0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	-0.75f, -0.2f, -0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,

	-0.75f, -0.2f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 0.75f, -0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f,  0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	-0.75f,  0.2f,  0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	-0.75f, -0.2f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,

	-0.75f,  0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	-0.75f,  0.2f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	-0.75f, -0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	-0.75f, -0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	-0.75f, -0.2f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	-0.75f,  0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,

	 0.75f,  0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f, -0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f, -0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f, -0.2f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,

	-0.75f, -0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f, -0.2f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f, -0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 0.75f, -0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	-0.75f, -0.2f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	-0.75f, -0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,

	-0.75f,  0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f, -0.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 0.75f,  0.2f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	-0.75f,  0.2f,  0.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	-0.75f,  0.2f, -0.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f
};

float vertices10[] = {//desktop
	-1.5f, -0.05f, -1.0f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 1.5f, -0.05f, -1.0f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 1.5f,  0.05f, -1.0f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 1.5f,  0.05f, -1.0f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-1.5f,  0.05f, -1.0f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-1.5f, -0.05f, -1.0f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
				
	-1.5f, -0.05f,  1.0f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 1.5f, -0.05f,  1.0f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 1.5f,  0.05f,  1.0f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 1.5f,  0.05f,  1.0f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-1.5f,  0.05f,  1.0f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-1.5f, -0.05f,  1.0f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 				
	-1.5f,  0.05f,  1.0f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-1.5f,  0.05f, -1.0f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-1.5f, -0.05f, -1.0f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-1.5f, -0.05f, -1.0f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-1.5f, -0.05f,  1.0f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-1.5f,  0.05f,  1.0f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
				
	 1.5f,  0.05f,  1.0f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 1.5f,  0.05f, -1.0f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 1.5f, -0.05f, -1.0f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 1.5f, -0.05f, -1.0f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 1.5f, -0.05f,  1.0f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 1.5f,  0.05f,  1.0f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
				
	-1.5f, -0.05f, -1.0f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 1.5f, -0.05f, -1.0f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 1.5f, -0.05f,  1.0f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 1.5f, -0.05f,  1.0f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-1.5f, -0.05f,  1.0f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-1.5f, -0.05f, -1.0f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
					
	-1.5f,  0.05f, -1.0f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 1.5f,  0.05f, -1.0f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 1.5f,  0.05f,  1.0f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 1.5f,  0.05f,  1.0f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-1.5f,  0.05f,  1.0f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-1.5f,  0.05f, -1.0f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
};

float vertices11[] = {//deskleg
	-0.035f, -0.5f, -0.035f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.035f, -0.5f, -0.035f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.035f,  0.5f, -0.035f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 0.035f,  0.5f, -0.035f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.035f,  0.5f, -0.035f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.035f, -0.5f, -0.035f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
					 
	-0.035f, -0.5f,  0.035f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.035f, -0.5f,  0.035f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.035f,  0.5f,  0.035f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 0.035f,  0.5f,  0.035f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.035f,  0.5f,  0.035f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.035f, -0.5f,  0.035f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
					 
	-0.035f,  0.5f,  0.035f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.035f,  0.5f, -0.035f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.035f, -0.5f, -0.035f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.035f, -0.5f, -0.035f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.035f, -0.5f,  0.035f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.035f,  0.5f,  0.035f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
					 
	 0.035f,  0.5f,  0.035f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.035f,  0.5f, -0.035f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.035f, -0.5f, -0.035f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.035f, -0.5f, -0.035f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.035f, -0.5f,  0.035f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.035f,  0.5f,  0.035f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
					 
	-0.035f, -0.5f, -0.035f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.035f, -0.5f, -0.035f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.035f, -0.5f,  0.035f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 0.035f, -0.5f,  0.035f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.035f, -0.5f,  0.035f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.035f, -0.5f, -0.035f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
					 
	-0.035f,  0.5f, -0.035f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.035f,  0.5f, -0.035f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.035f,  0.5f,  0.035f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 0.035f,  0.5f,  0.035f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.035f,  0.5f,  0.035f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.035f,  0.5f, -0.035f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
};

float vertices12[] = {//chairleg
	-0.02f, -1.0f, -0.02f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.02f, -1.0f, -0.02f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.02f,  1.0f, -0.02f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 0.02f,  1.0f, -0.02f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.02f,  1.0f, -0.02f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.02f, -1.0f, -0.02f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
		 	 
	-0.02f, -1.0f,  0.02f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.02f, -1.0f,  0.02f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.02f,  1.0f,  0.02f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 0.02f,  1.0f,  0.02f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.02f,  1.0f,  0.02f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.02f, -1.0f,  0.02f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
			
	-0.02f,  1.0f,  0.02f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.02f,  1.0f, -0.02f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.02f, -1.0f, -0.02f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.02f, -1.0f, -0.02f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.02f, -1.0f,  0.02f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.02f,  1.0f,  0.02f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
			
	 0.02f,  1.0f,  0.02f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.02f,  1.0f, -0.02f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.02f, -1.0f, -0.02f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.02f, -1.0f, -0.02f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.02f, -1.0f,  0.02f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.02f,  1.0f,  0.02f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
			
	-0.02f, -1.0f, -0.02f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.02f, -1.0f, -0.02f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.02f, -1.0f,  0.02f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 0.02f, -1.0f,  0.02f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.02f, -1.0f,  0.02f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.02f, -1.0f, -0.02f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
			
	-0.02f,  1.0f, -0.02f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.02f,  1.0f, -0.02f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.02f,  1.0f,  0.02f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 0.02f,  1.0f,  0.02f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.02f,  1.0f,  0.02f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.02f,  1.0f, -0.02f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f
};

float vertices13[] = {//chairtop
	-1.5f, -0.05f, -1.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 1.5f, -0.05f, -1.5f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 1.5f,  0.05f, -1.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 1.5f,  0.05f, -1.5f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-1.5f,  0.05f, -1.5f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-1.5f, -0.05f, -1.5f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
					
	-1.5f, -0.05f,  1.5f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 1.5f, -0.05f,  1.5f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 1.5f,  0.05f,  1.5f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 1.5f,  0.05f,  1.5f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-1.5f,  0.05f,  1.5f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-1.5f, -0.05f,  1.5f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
					
	-1.5f,  0.05f,  1.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-1.5f,  0.05f, -1.5f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-1.5f, -0.05f, -1.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-1.5f, -0.05f, -1.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-1.5f, -0.05f,  1.5f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-1.5f,  0.05f,  1.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
					
	 1.5f,  0.05f,  1.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 1.5f,  0.05f, -1.5f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 1.5f, -0.05f, -1.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 1.5f, -0.05f, -1.5f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 1.5f, -0.05f,  1.5f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 1.5f,  0.05f,  1.5f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
					
	-1.5f, -0.05f, -1.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 1.5f, -0.05f, -1.5f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 1.5f, -0.05f,  1.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 1.5f, -0.05f,  1.5f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-1.5f, -0.05f,  1.5f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-1.5f, -0.05f, -1.5f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
					
	-1.5f,  0.05f, -1.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 1.5f,  0.05f, -1.5f,  1.0f, 1.0f, 0.0f,  0.0f,  0.0f,
	 1.5f,  0.05f,  1.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	 1.5f,  0.05f,  1.5f,  1.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	-1.5f,  0.05f,  1.5f,  0.0f, 0.0f, 0.0f,  0.0f,  0.0f,
	-1.5f,  0.05f, -1.5f,  0.0f, 1.0f, 0.0f,  0.0f,  0.0f

};

float vertices14[] = {//chairback
	-0.5f, -0.02f, -0.02f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.5f, -0.02f, -0.02f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.5f,  0.02f, -0.02f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 0.5f,  0.02f, -0.02f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.5f,  0.02f, -0.02f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.5f, -0.02f, -0.02f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
					
	-0.5f, -0.02f,  0.02f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.5f, -0.02f,  0.02f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.5f,  0.02f,  0.02f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 0.5f,  0.02f,  0.02f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.5f,  0.02f,  0.02f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.5f, -0.02f,  0.02f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
					
	-0.5f,  0.02f,  0.02f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.02f, -0.02f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.02f, -0.02f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.02f, -0.02f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.02f,  0.02f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.02f,  0.02f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
					
	 0.5f,  0.02f,  0.02f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.5f,  0.02f, -0.02f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.02f, -0.02f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.02f, -0.02f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.02f,  0.02f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.5f,  0.02f,  0.02f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
					
	-0.5f, -0.02f, -0.02f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.02f, -0.02f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.02f,  0.02f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.02f,  0.02f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.5f, -0.02f,  0.02f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.5f, -0.02f, -0.02f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
					
	-0.5f,  0.02f, -0.02f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.02f, -0.02f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.02f,  0.02f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.02f,  0.02f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.5f,  0.02f,  0.02f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.5f,  0.02f, -0.02f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f

};

float vertices15[] = {//celling
	-2.0f,  0.5f, -1.2f,  0.0f, 1.0f, 0.0f,  -1.0f,  0.0f,
	 2.0f,  0.5f, -1.2f,  1.0f, 1.0f, 0.0f,  -1.0f,  0.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 0.0f, 0.0f,  -1.0f,  0.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 0.0f, 0.0f,  -1.0f,  0.0f,
	-2.0f,  0.5f,  1.2f,  0.0f, 0.0f, 0.0f,  -1.0f,  0.0f,
	-2.0f,  0.5f, -1.2f,  0.0f, 1.0f, 0.0f,  -1.0f,  0.0f
};

float vertices16[] = {//floor
	-2.0f, -0.5f, -1.2f,  0.0f, 1.0f, 0.0f, 1.0f,  0.0f,
	 2.0f, -0.5f, -1.2f,  1.0f, 1.0f, 0.0f, 1.0f,  0.0f,
	 2.0f, -0.5f,  1.2f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f,
	 2.0f, -0.5f,  1.2f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f,
	-2.0f, -0.5f,  1.2f,  0.0f, 0.0f, 0.0f, 1.0f,  0.0f,
	-2.0f, -0.5f, -1.2f,  0.0f, 1.0f, 0.0f, 1.0f,  0.0f
};

float vertices17[] = {//mural
	-2.0f, -0.5f,  1.2f,  0.0f, 0.0f, 0.0f,  0.0f,  -1.0f,
	 2.0f, -0.5f,  1.2f,  1.0f, 0.0f, 0.0f,  0.0f,  -1.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 1.0f, 0.0f,  0.0f,  -1.0f,
	 2.0f,  0.5f,  1.2f,  1.0f, 1.0f, 0.0f,  0.0f,  -1.0f,
	-2.0f,  0.5f,  1.2f,  0.0f, 1.0f, 0.0f,  0.0f,  -1.0f,
	-2.0f, -0.5f,  1.2f,  0.0f, 0.0f, 0.0f,  0.0f,  -1.0f
};

float vertices18[] = {
	-0.5f, -0.2f, -0.05f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.5f, -0.2f, -0.05f,  1.0f, 0.0f, 0.0f,  0.0f, -1.0f,
	 0.5f,  0.2f, -0.05f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	 0.5f,  0.2f, -0.05f,  1.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.5f,  0.2f, -0.05f,  0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
	-0.5f, -0.2f, -0.05f,  0.0f, 0.0f, 0.0f,  0.0f, -1.0f,
				
	-0.5f, -0.2f,  0.05f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.5f, -0.2f,  0.05f,  1.0f, 0.0f, 0.0f,  0.0f,  1.0f,
	 0.5f,  0.2f,  0.05f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	 0.5f,  0.2f,  0.05f,  1.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.5f,  0.2f,  0.05f,  0.0f, 1.0f, 0.0f,  0.0f,  1.0f,
	-0.5f, -0.2f,  0.05f,  0.0f, 0.0f, 0.0f,  0.0f,  1.0f,
			
	-0.5f,  0.2f,  0.05f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.2f, -0.05f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.2f, -0.05f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.2f, -0.05f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f,
	-0.5f, -0.2f,  0.05f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
	-0.5f,  0.2f,  0.05f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f,
			
	 0.5f,  0.2f,  0.05f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.5f,  0.2f, -0.05f,  1.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.2f, -0.05f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.2f, -0.05f,  0.0f, 1.0f, 1.0f,  0.0f,  0.0f,
	 0.5f, -0.2f,  0.05f,  0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
	 0.5f,  0.2f,  0.05f,  1.0f, 0.0f, 1.0f,  0.0f,  0.0f,
			
	-0.5f, -0.2f, -0.05f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.2f, -0.05f,  1.0f, 1.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.2f,  0.05f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	 0.5f, -0.2f,  0.05f,  1.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.5f, -0.2f,  0.05f,  0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
	-0.5f, -0.2f, -0.05f,  0.0f, 1.0f, 0.0f, -1.0f,  0.0f,
			
	-0.5f,  0.2f, -0.05f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.2f, -0.05f,  1.0f, 1.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.2f,  0.05f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	 0.5f,  0.2f,  0.05f,  1.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.5f,  0.2f,  0.05f,  0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
	-0.5f,  0.2f, -0.05f,  0.0f, 1.0f, 0.0f,  1.0f,  0.0f

};

float vertices19[] = {//cubic cone
	-0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 0,0,0,
	-0.5f, 0.0f,-0.5f, 0.0f, 1.0f, 0,0,0,
	 0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0,0,0,

	 0.5f, 0.0f,-0.5f, 1.0f, 1.0f, 0,0,0,
	-0.5f, 0.0f,-0.5f, 0.0f, 1.0f, 0,0,0,
	 0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0,0,0,

	-0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 0,0,0,
	-0.5f, 0.0f,-0.5f, 0.0f, 1.0f, 0,0,0,
	 0.0f, 1.5f, 0.0f, 0.5f, 1.0f, 0,0,0,

	-0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 0,0,0,
	 0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0,0,0,
	 0.0f, 1.5f, 0.0f, 0.5f, 1.0f, 0,0,0,

	 0.5f, 0.0f,-0.5f, 1.0f, 1.0f, 0,0,0,
	 0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0,0,0,
	 0.0f, 1.5f, 0.0f, 0.5f, 1.0f, 0,0,0,

	-0.5f, 0.0f,-0.5f, 0.0f, 1.0f, 0,0,0,
	 0.5f, 0.0f,-0.5f, 1.0f, 1.0f, 0,0,0,
	 0.0f, 1.5f, 0.0f, 0.5f, 1.0f, 0,0,0
};

//Instantiate Camera Class
Camera camera(glm::vec3(10.0f, 0, 10.0f), glm::radians(0.0f), glm::radians(180.0f), glm::vec3(0, 1.0f, 0));

//create a window
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.speedZ = 0.1f;
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.speedZ = -0.1f;
	else camera.speedZ = 0.0f;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.speedX = -0.1f;
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.speedX = 0.1f;
	else camera.speedX = 0.0f;

}

//mouse controll
float lastX;
float lastY;
bool firstMouse = true;

void mouse_callback(GLFWwindow * window, double xPos, double yPos)//mousecallback
{
	if (firstMouse == true)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}
	float deltaX, deltaY;
	deltaX = xPos - lastX;
	deltaY = yPos - lastY;

	lastX = xPos;
	lastY = yPos;
	camera.ProcessMouseMovement(deltaX, deltaY);
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//openGL GLEW window
	GLFWwindow* window = glfwCreateWindow(1000, 1000, "my opengl game", NULL, NULL);
	if (window == NULL)
	{
		printf("open window failed\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);

	//Init GLEW
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		printf("init glew failed\n");
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, 1000, 1000);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//线框画图模式
	glEnable(GL_DEPTH_TEST);//深度缓存

	Shader* myShader = new Shader("vertexSource.txt", "fragmentSource.txt");

	glm::mat4 trans = glm::mat4(1.0f);//viewportchange
	glm::mat4 trans1 = glm::mat4(1.0f);//"huaji"cube change
	glm::mat4 idenMat = glm::mat4(1.0f);//identity matrix
	glm::mat4 trans2 = glm::mat4(1.0f);//fan blade
	glm::mat4 trans3 = glm::mat4(1.0f);//spin hexagon

	glm::mat4 viewMat = glm::mat4(1.0f);//viewmat
	
	glm::mat4 projMat = glm::mat4(1.0f);//projmat
	projMat = glm::perspective(glm::radians(45.0f), 1000.0f / 1000.0f, 1.0f, 100.0f);

	//above is viewMAT&PROJMAT&other trans

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer;
	glGenTextures(1, &TexBuffer);
	glBindTexture(GL_TEXTURE_2D, TexBuffer);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("huaji.jpg", &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, TexBuffer);
	glBindVertexArray(VAO);

	glm::mat4 modelMat = glm::mat4(1.0f);
	modelMat = glm::scale(modelMat, glm::vec3(0.5f, 0.5f, 0.5f));
	modelMat = glm::translate(modelMat, glm::vec3(2.3f, -2.3f, -1.0f));

	glm::mat4 modelMat8 = glm::mat4(1.0f);
	modelMat8 = glm::translate(modelMat8, glm::vec3(-3.9f, 1.67f, 1.0f));
	modelMat8 = glm::scale(modelMat8, glm::vec3(0.15f, 0.15f, 0.15f));

	//above is "huaji"cube

	unsigned int VAO1;
	glGenVertexArrays(1, &VAO1);
	glBindVertexArray(VAO1);

	unsigned int VBO1;
	glGenBuffers(1, &VBO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性
	//create texture
	unsigned int TexBuffer1;
	glGenTextures(1, &TexBuffer1);
	glBindTexture(GL_TEXTURE_2D, TexBuffer1);

	int width1, height1, nrChannels1;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data1 = stbi_load("wall.jpg", &width1, &height1, &nrChannels1, 0);

	if (data1)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB, GL_UNSIGNED_BYTE, data1);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic1 failed\n");
	}

	stbi_image_free(data1);
	glBindTexture(GL_TEXTURE_2D, TexBuffer1);
	glBindVertexArray(VAO1);

	glm::mat4 modelMat1 = glm::mat4(1.0f);
	modelMat1 = glm::scale(modelMat1, glm::vec3(3.5f, 3.5f, 3.5f));

	//above is room VAO&VBO

	unsigned int VAO2;
	glGenVertexArrays(1, &VAO2);
	glBindVertexArray(VAO2);

	unsigned int VBO2;
	glGenBuffers(1, &VBO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer2;
	glGenTextures(1, &TexBuffer2);
	glBindTexture(GL_TEXTURE_2D, TexBuffer2);

	int width2, height2, nrChannels2;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data2 = stbi_load("tvscreen.jpg", &width2, &height2, &nrChannels2, 0);

	if (data2)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, data2);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic2 failed\n");
	}

	stbi_image_free(data2);

	glBindTexture(GL_TEXTURE_2D, TexBuffer2);
	glBindVertexArray(VAO2);

	glm::mat4 modelMat2 = glm::mat4(1.0f);
	modelMat2 = glm::scale(modelMat2, glm::vec3(0.8f, 0.8f, 0.8f));
	modelMat2 = glm::translate(modelMat2, glm::vec3(0, -0.8f, -5.0f));

	//above is TVscreen VAO&VBO

	unsigned int VAO3;
	glGenVertexArrays(1, &VAO3);
	glBindVertexArray(VAO3);

	unsigned int VBO3;
	glGenBuffers(1, &VBO3);
	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer3;
	glGenTextures(1, &TexBuffer3);
	glBindTexture(GL_TEXTURE_2D, TexBuffer3);

	int width3, height3, nrChannels3;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data3 = stbi_load("black.jpg", &width3, &height3, &nrChannels3, 0);

	if (data3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width3, height3, 0, GL_RGB, GL_UNSIGNED_BYTE, data3);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(data3);

	glBindTexture(GL_TEXTURE_2D, TexBuffer3);
	glBindVertexArray(VAO3);

	glm::mat4 modelMat3 = glm::mat4(1.0f);
	modelMat3 = glm::scale(modelMat3, glm::vec3(0.8f, 0.8f, 0.8f));
	modelMat3 = glm::translate(modelMat3, glm::vec3(0, -1.68f, -5.0f));

	//above is tvbase

	unsigned int VAO4;
	glGenVertexArrays(1, &VAO4);
	glBindVertexArray(VAO4);

	unsigned int VBO4;
	glGenBuffers(1, &VBO4);
	glBindBuffer(GL_ARRAY_BUFFER, VBO4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices5), vertices5, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer4;
	glGenTextures(1, &TexBuffer4);
	glBindTexture(GL_TEXTURE_2D, TexBuffer4);

	int width4, height4, nrChannels4;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data4 = stbi_load("bed.jpg", &width4, &height4, &nrChannels4, 0);

	if (data4)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width4, height4, 0, GL_RGB, GL_UNSIGNED_BYTE, data4);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic4 failed\n");
	}

	stbi_image_free(data4);

	glBindTexture(GL_TEXTURE_2D, TexBuffer4);
	glBindVertexArray(VAO4);

	glm::mat4 modelMat4 = glm::mat4(1.0f);
	modelMat4 = glm::scale(modelMat4, glm::vec3(2.0f, 2.0f, 2.0f));
	modelMat4 = glm::translate(modelMat4, glm::vec3(-3.0f,-0.76f, -0.96f));

	//above is bed

	unsigned int VAO5;
	glGenVertexArrays(1, &VAO5);
	glBindVertexArray(VAO5);

	unsigned int VBO5;
	glGenBuffers(1, &VBO5);
	glBindBuffer(GL_ARRAY_BUFFER, VBO5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices6), vertices6, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer5;
	glGenTextures(1, &TexBuffer5);
	glBindTexture(GL_TEXTURE_2D, TexBuffer5);

	int width5, height5, nrChannels5;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data5 = stbi_load("black.jpg", &width5, &height5, &nrChannels5, 0);

	if (data5) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width5, height5, 0, GL_RGB, GL_UNSIGNED_BYTE, data5);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(data5);

	glBindTexture(GL_TEXTURE_2D, TexBuffer5);
	glBindVertexArray(VAO5);

	glm::mat4 modelMat5 = glm::mat4(1.0f);
	modelMat5 = glm::translate(modelMat5, glm::vec3(0, 1.5f, 0));
	modelMat5 = glm::rotate(modelMat5, glm::radians(90.0f), glm::vec3(1.0f, 0, 0));

	//above is a fan

	unsigned int VAO6;
	glGenVertexArrays(1, &VAO6);
	glBindVertexArray(VAO6);

	unsigned int VBO6;
	glGenBuffers(1, &VBO6);
	glBindBuffer(GL_ARRAY_BUFFER, VBO6);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices7), vertices7, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer6;
	glGenTextures(1, &TexBuffer6);
	glBindTexture(GL_TEXTURE_2D, TexBuffer6);

	int width6, height6, nrChannels6;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data6 = stbi_load("black.jpg", &width6, &height6, &nrChannels6, 0);

	if (data6) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width6, height6, 0, GL_RGB, GL_UNSIGNED_BYTE, data6);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(data6);

	glBindTexture(GL_TEXTURE_2D, TexBuffer6);
	glBindVertexArray(VAO6);

	glm::mat4 modelMat6 = glm::mat4(1.0f);
	modelMat6 = glm::scale(modelMat6, glm::vec3(0.25f, 0.25f, 0.25f));
	modelMat6 = glm::translate(modelMat6, glm::vec3(12.0f, 1.0f, -2.0f));


	//above is an hexagon

	unsigned int VAO7;
	glGenVertexArrays(1, &VAO7);
	glBindVertexArray(VAO7);

	unsigned int VBO7;
	glGenBuffers(1, &VBO7);
	glBindBuffer(GL_ARRAY_BUFFER, VBO7);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices8), vertices8, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer7;
	glGenTextures(1, &TexBuffer7);
	glBindTexture(GL_TEXTURE_2D, TexBuffer7);

	int width7, height7, nrChannels7;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data7 = stbi_load("door.jpg", &width7, &height7, &nrChannels7, 0);

	if (data7) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width7, height7, 0, GL_RGB, GL_UNSIGNED_BYTE, data7);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(data7);

	glBindTexture(GL_TEXTURE_2D, TexBuffer7);
	glBindVertexArray(VAO7);

	glm::mat4 modelMat7 = glm::mat4(1.0f);
	modelMat7 = glm::translate(modelMat7, glm::vec3(7.0f, -0.75f, 0));

	//above is a door

	unsigned int VAO8;
	glGenVertexArrays(1, &VAO8);
	glBindVertexArray(VAO8);

	unsigned int VBO8;
	glGenBuffers(1, &VBO8);
	glBindBuffer(GL_ARRAY_BUFFER, VBO8);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices9), vertices9, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer8;
	glGenTextures(1, &TexBuffer8);
	glBindTexture(GL_TEXTURE_2D, TexBuffer8);

	int width8, height8, nrChannels8;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data8 = stbi_load("planet.jpg", &width8, &height8, &nrChannels8, 0);

	if (data8)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width8, height8, 0, GL_RGB, GL_UNSIGNED_BYTE, data8);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data8);

	glBindTexture(GL_TEXTURE_2D, TexBuffer8);
	glBindVertexArray(VAO8);

	glm::mat4 modelMat9 = glm::mat4(1.0f);
	modelMat9 = glm::scale(modelMat9, glm::vec3(0.5f, 0.5f, 0.5f));
	modelMat9 = glm::translate(modelMat9, glm::vec3(-12.0f, -2.4f, -7.0f));

	//above is pillow

	unsigned int VAO9;
	glGenVertexArrays(1, &VAO9);
	glBindVertexArray(VAO9);

	unsigned int VBO9;
	glGenBuffers(1, &VBO9);
	glBindBuffer(GL_ARRAY_BUFFER, VBO9);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices10), vertices10, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer9;
	glGenTextures(1, &TexBuffer9);
	glBindTexture(GL_TEXTURE_2D, TexBuffer9);

	int width9, height9, nrChannels9;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data9 = stbi_load("iron.jpg", &width9, &height9, &nrChannels9, 0);

	if (data9)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width9, height9, 0, GL_RGB, GL_UNSIGNED_BYTE, data9);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data9);

	glBindTexture(GL_TEXTURE_2D, TexBuffer9);
	glBindVertexArray(VAO9);

	glm::mat4 modelMat10 = glm::mat4(1.0f);
	modelMat10 = glm::scale(modelMat10, glm::vec3(0.7f, 0.7f, 0.7f));
	modelMat10 = glm::translate(modelMat10, glm::vec3(-1.3f, -1.3f, 0.0f));

	//above is desktop

	unsigned int VAO10;
	glGenVertexArrays(1, &VAO10);
	glBindVertexArray(VAO10);

	unsigned int VBO10;
	glGenBuffers(1, &VBO10);
	glBindBuffer(GL_ARRAY_BUFFER, VBO10);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices11), vertices11, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer10;
	glGenTextures(1, &TexBuffer10);
	glBindTexture(GL_TEXTURE_2D, TexBuffer10);

	int width10, height10, nrChannels10;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data10 = stbi_load("iron.jpg", &width10, &height10, &nrChannels10, 0);

	if (data10)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width10, height10, 0, GL_RGB, GL_UNSIGNED_BYTE, data10);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data10);

	glBindTexture(GL_TEXTURE_2D, TexBuffer10);
	glBindVertexArray(VAO10);

	glm::mat4 modelMat11 = glm::mat4(1.0f);
	modelMat11 = glm::translate(modelMat11, glm::vec3(0.0f, -1.38f, 0.5f));

	glm::mat4 modelMat12 = glm::mat4(1.0f);
	modelMat12 = glm::translate(modelMat12, glm::vec3(0.0f, -1.38f, -0.5f));

	glm::mat4 modelMat13 = glm::mat4(1.0f);
	modelMat13 = glm::translate(modelMat13, glm::vec3(-1.8f, -1.38f, 0.5f));

	glm::mat4 modelMat14 = glm::mat4(1.0f);
	modelMat14 = glm::translate(modelMat14, glm::vec3(-1.8f, -1.38f, -0.5f));

	//above is desklegs

	unsigned int VAO11;
	glGenVertexArrays(1, &VAO11);
	glBindVertexArray(VAO11);

	unsigned int VBO11;
	glGenBuffers(1, &VBO11);
	glBindBuffer(GL_ARRAY_BUFFER, VBO11);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices12), vertices12, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer11;
	glGenTextures(1, &TexBuffer11);
	glBindTexture(GL_TEXTURE_2D, TexBuffer11);

	int width11, height11, nrChannels11;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data11 = stbi_load("iron.jpg", &width11, &height11, &nrChannels11, 0);

	if (data11)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width11, height11, 0, GL_RGB, GL_UNSIGNED_BYTE, data11);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data11);

	glBindTexture(GL_TEXTURE_2D, TexBuffer11);
	glBindVertexArray(VAO11);

	glm::mat4 modelMat15 = glm::mat4(1.0f);
	modelMat15 = glm::translate(modelMat15, glm::vec3(-0.5f, -1.0f, 2.2f));

	glm::mat4 modelMat16 = glm::mat4(1.0f);
	modelMat16 = glm::translate(modelMat16, glm::vec3(-1.3f, -1.0f, 2.2f));

	glm::mat4 modelMat17 = glm::mat4(1.0f);
	modelMat17 = glm::scale(modelMat17, glm::vec3(1.0f, 0.5f, 1.0f));
	modelMat17 = glm::translate(modelMat17, glm::vec3(-0.5f, -3.0f, 1.5f));

	glm::mat4 modelMat18 = glm::mat4(1.0f);
	modelMat18 = glm::scale(modelMat18, glm::vec3(1.0f, 0.5f, 1.0f));
	modelMat18 = glm::translate(modelMat18, glm::vec3(-1.3f, -3.0f, 1.5f));

	//above is chairlegs

	unsigned int VAO12;
	glGenVertexArrays(1, &VAO12);
	glBindVertexArray(VAO12);

	unsigned int VBO12;
	glGenBuffers(1, &VBO12);
	glBindBuffer(GL_ARRAY_BUFFER, VBO12);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices13), vertices13, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer12;
	glGenTextures(1, &TexBuffer12);
	glBindTexture(GL_TEXTURE_2D, TexBuffer12);

	int width12, height12, nrChannels12;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data12 = stbi_load("iron.jpg", &width12, &height12, &nrChannels12, 0);

	if (data12)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width12, height12, 0, GL_RGB, GL_UNSIGNED_BYTE, data12);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data12);

	glBindTexture(GL_TEXTURE_2D, TexBuffer12);
	glBindVertexArray(VAO12);

	glm::mat4 modelMat19 = glm::mat4(1.0f);
	modelMat19 = glm::scale(modelMat19, glm::vec3(0.28f, 0.28f, 0.28f));
	modelMat19 = glm::translate(modelMat19, glm::vec3(-3.2f, -3.6f, 6.3f));

	//above is chairtop

	unsigned int VAO13;
	glGenVertexArrays(1, &VAO13);
	glBindVertexArray(VAO13);

	unsigned int VBO13;
	glGenBuffers(1, &VBO13);
	glBindBuffer(GL_ARRAY_BUFFER, VBO13);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices14), vertices14, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer13;
	glGenTextures(1, &TexBuffer13);
	glBindTexture(GL_TEXTURE_2D, TexBuffer13);

	int width13, height13, nrChannels13;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data13 = stbi_load("iron.jpg", &width13, &height13, &nrChannels13, 0);

	if (data13)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width13, height13, 0, GL_RGB, GL_UNSIGNED_BYTE, data13);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data13);

	glBindTexture(GL_TEXTURE_2D, TexBuffer13);
	glBindVertexArray(VAO13);

	glm::mat4 modelMat20 = glm::mat4(1.0f);
	modelMat20 = glm::scale(modelMat20, glm::vec3(0.8f, 1.0f, 1.0f));
	modelMat20 = glm::translate(modelMat20, glm::vec3(-1.13f, -0.2f, 2.2f));

	glm::mat4 modelMat21 = glm::mat4(1.0f);
	modelMat21 = glm::scale(modelMat21, glm::vec3(0.8f, 1.0f, 1.0f));
	modelMat21 = glm::translate(modelMat21, glm::vec3(-1.13f, -0.35f, 2.2f));

	glm::mat4 modelMat22 = glm::mat4(1.0f);
	modelMat22 = glm::scale(modelMat22, glm::vec3(0.8f, 1.0f, 1.0f));
	modelMat22 = glm::translate(modelMat22, glm::vec3(-1.13f, -0.5f, 2.2f));

	//above is chairback

	unsigned int VAO14;
	glGenVertexArrays(1, &VAO14);
	glBindVertexArray(VAO14);

	unsigned int VBO14;
	glGenBuffers(1, &VBO14);
	glBindBuffer(GL_ARRAY_BUFFER, VBO14);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices15), vertices15, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer14;
	glGenTextures(1, &TexBuffer14);
	glBindTexture(GL_TEXTURE_2D, TexBuffer14);

	int width14, height14, nrChannels14;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data14 = stbi_load("starlight.jpg", &width14, &height14, &nrChannels14, 0);

	if (data14)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width14, height14, 0, GL_RGB, GL_UNSIGNED_BYTE, data14);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data14);

	glBindTexture(GL_TEXTURE_2D, TexBuffer14);
	glBindVertexArray(VAO14);

	glm::mat4 modelMat23 = glm::mat4(1.0f);
	modelMat23 = glm::scale(modelMat23, glm::vec3(3.5f, 3.5f, 3.5f));

	//above is celling

	unsigned int VAO15;
	glGenVertexArrays(1, &VAO15);
	glBindVertexArray(VAO15);

	unsigned int VBO15;
	glGenBuffers(1, &VBO15);
	glBindBuffer(GL_ARRAY_BUFFER, VBO15);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices16), vertices16, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer15;
	glGenTextures(1, &TexBuffer15);
	glBindTexture(GL_TEXTURE_2D, TexBuffer15);

	int width15, height15, nrChannels15;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data15 = stbi_load("floor.jpg", &width15, &height15, &nrChannels15, 0);

	if (data15)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width15, height15, 0, GL_RGB, GL_UNSIGNED_BYTE, data15);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data15);

	glBindTexture(GL_TEXTURE_2D, TexBuffer15);
	glBindVertexArray(VAO15);

	glm::mat4 modelMat24 = glm::mat4(1.0f);
	modelMat24 = glm::scale(modelMat24, glm::vec3(3.5f, 3.5f, 3.5f));

	//above is floor

	unsigned int VAO16;
	glGenVertexArrays(1, &VAO16);
	glBindVertexArray(VAO16);

	unsigned int VBO16;
	glGenBuffers(1, &VBO16);
	glBindBuffer(GL_ARRAY_BUFFER, VBO16);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices17), vertices17, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer16;
	glGenTextures(1, &TexBuffer16);
	glBindTexture(GL_TEXTURE_2D, TexBuffer16);

	int width16, height16, nrChannels16;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data16 = stbi_load("btw.jpg", &width16, &height16, &nrChannels16, 0);

	if (data16)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width16, height16, 0, GL_RGB, GL_UNSIGNED_BYTE, data16);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data16);

	glBindTexture(GL_TEXTURE_2D, TexBuffer16);
	glBindVertexArray(VAO16);

	glm::mat4 modelMat25 = glm::mat4(1.0f);
	modelMat25 = glm::scale(modelMat25, glm::vec3(1.5f, 2.0f, 3.5f));
	modelMat25 = glm::translate(modelMat25, glm::vec3(0.0f, 0.0f, -0.0001f));

	//above is mural

	unsigned int VAO17;
	glGenVertexArrays(1, &VAO17);
	glBindVertexArray(VAO17);

	unsigned int VBO17;
	glGenBuffers(1, &VBO17);
	glBindBuffer(GL_ARRAY_BUFFER, VBO17);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices18), vertices18, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer17;
	glGenTextures(1, &TexBuffer17);
	glBindTexture(GL_TEXTURE_2D, TexBuffer17);

	int width17, height17, nrChannels17;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data17 = stbi_load("bed.jpg", &width17, &height17, &nrChannels17, 0);

	if (data17)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width17, height17, 0, GL_RGB, GL_UNSIGNED_BYTE, data17);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic4 failed\n");
	}

	stbi_image_free(data17);

	glBindTexture(GL_TEXTURE_2D, TexBuffer17);
	glBindVertexArray(VAO17);

	glm::mat4 modelMat26 = glm::mat4(1.0f);
	modelMat26 = glm::scale(modelMat26, glm::vec3(2.0f, 2.0f, 2.0f));
	modelMat26 = glm::translate(modelMat26, glm::vec3(-3.0f, -0.667f, -2.0f));

	//above is bedback

	unsigned int VAO18;
	glGenVertexArrays(1, &VAO18);
	glBindVertexArray(VAO18);

	unsigned int VBO18;
	glGenBuffers(1, &VBO18);
	glBindBuffer(GL_ARRAY_BUFFER, VBO18);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices19), vertices19, GL_STATIC_DRAW);

	//vertexattributepointer
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);//位置属性

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);//贴图属性

	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);//光照属性

	//create texture
	unsigned int TexBuffer18;
	glGenTextures(1, &TexBuffer18);
	glBindTexture(GL_TEXTURE_2D, TexBuffer18);

	int width18, height18, nrChannels18;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data18 = stbi_load("dizzy.jpg", &width18, &height18, &nrChannels18, 0);

	if (data18)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width18, height18, 0, GL_RGB, GL_UNSIGNED_BYTE, data18);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	else
	{
		printf("print pic failed\n");
	}

	stbi_image_free(data18);

	glBindTexture(GL_TEXTURE_2D, TexBuffer18);
	glBindVertexArray(VAO18);

	glm::mat4 modelMat27 = glm::mat4(1.0f);
	modelMat27 = glm::translate(modelMat27, glm::vec3(3.0f, -1.7f, 1.0f));

	//above is cubic cone

	//render loop
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		//render
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		viewMat = camera.GetViewMatrix();

		if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
			trans1 = glm::rotate(trans1, (float)glfwGetTime(), glm::vec3(1.0f, 0, 0));
		if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
			trans1 = glm::scale(trans1, glm::vec3(1.005f, 1.005f, 1.005f));
		if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
			trans1 = glm::scale(trans1, glm::vec3(0.995f, 0.995f, 0.995f));
		if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
			trans1 = glm::translate(trans1, glm::vec3(0.1f, 0, 0));
		if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
			trans1 = glm::translate(trans1, glm::vec3(-0.1f, 0, 0));
		if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
			trans1 = glm::translate(trans1, glm::vec3(0, 0, 0.1f));
		if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
			trans1 = glm::translate(trans1, glm::vec3(0, 0, -0.1f));

		//above is keypress

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(trans1));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
		glUniform3f(glGetUniformLocation(myShader->ID, "ambientColor"), 0.6f, 0.6f, 0.6f);
		glUniform3f(glGetUniformLocation(myShader->ID, "lightPos"), -3.9f, 1.55f, 1.0f);
		glUniform3f(glGetUniformLocation(myShader->ID, "lightColor"), 1.2f, 1.2f, 1.2f);
		glUniform3f(glGetUniformLocation(myShader->ID, "cameraPos"), camera.Position.x, camera.Position.y, camera.Position.z);

		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat8));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw "huaji" box

		glBindVertexArray(VAO1);
		glBindBuffer(GL_ARRAY_BUFFER, VBO1);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer1);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat1));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 24);

		//above draw the wall

		glBindVertexArray(VAO2);
		glBindBuffer(GL_ARRAY_BUFFER, VBO2);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer2);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat2));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));
	
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw tvscreen

		glBindVertexArray(VAO3);
		glBindBuffer(GL_ARRAY_BUFFER, VBO3);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer3);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat3));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 24);

		//above draw tvbase

		glBindVertexArray(VAO4);
		glBindBuffer(GL_ARRAY_BUFFER, VBO4);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices5), vertices5, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer4);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat4));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw a bed

		glBindVertexArray(VAO5);
		glBindBuffer(GL_ARRAY_BUFFER, VBO5);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices6), vertices6, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer5);

		trans2 = glm::rotate(trans, 100 * (float)glfwGetTime(), glm::vec3(0, 0, 1.0f));

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(trans2));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat5));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 3);

		//above draw a fan 

		glBindVertexArray(VAO6);
		glBindBuffer(GL_ARRAY_BUFFER, VBO6);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices7), vertices7, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer6);

		trans3 = glm::rotate(trans, 5 * (float)glfwGetTime(), glm::vec3(0, 1.0f, 0));

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(trans3));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat6));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 18);

		//above draw a  spinning hexagon

		glBindVertexArray(VAO7);
		glBindBuffer(GL_ARRAY_BUFFER, VBO7);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices8), vertices8, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer7);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat7));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw a door

		glBindVertexArray(VAO8);
		glBindBuffer(GL_ARRAY_BUFFER, VBO8);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices9), vertices9, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer8);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat9));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw pillow

		glBindVertexArray(VAO9);
		glBindBuffer(GL_ARRAY_BUFFER, VBO9);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices10), vertices10, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer9);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat10));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw desktop

		glBindVertexArray(VAO10);
		glBindBuffer(GL_ARRAY_BUFFER, VBO10);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices11), vertices11, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer10);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat11));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat12));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat13));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat14));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw desklegs

		glBindVertexArray(VAO11);
		glBindBuffer(GL_ARRAY_BUFFER, VBO11);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices12), vertices12, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer10);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat15));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat16));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat17));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat18));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw chairlegs

		glBindVertexArray(VAO12);
		glBindBuffer(GL_ARRAY_BUFFER, VBO12);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices13), vertices13, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer12);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat19));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw chairtop

		glBindVertexArray(VAO13);
		glBindBuffer(GL_ARRAY_BUFFER, VBO13);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices14), vertices14, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer13);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat20));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat21));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat22));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw chairback

		glBindVertexArray(VAO14);
		glBindBuffer(GL_ARRAY_BUFFER, VBO14);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices15), vertices15, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer14);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat23));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 6);

		//above draw celling

		glBindVertexArray(VAO15);
		glBindBuffer(GL_ARRAY_BUFFER, VBO15);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices16), vertices16, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer15);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat24));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 6);

		//above draw floor

		glBindVertexArray(VAO16);
		glBindBuffer(GL_ARRAY_BUFFER, VBO16);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices17), vertices17, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer16);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat25));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 6);

		//above draw mural

		glBindVertexArray(VAO17);
		glBindBuffer(GL_ARRAY_BUFFER, VBO17);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices18), vertices18, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer17);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat26));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 36);

		//above draw a bedback

		glBindVertexArray(VAO18);
		glBindBuffer(GL_ARRAY_BUFFER, VBO18);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices19), vertices19, GL_STATIC_DRAW);
		glBindTexture(GL_TEXTURE_2D, TexBuffer18);

		myShader->use();

		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "spin"), 1, GL_FALSE, glm::value_ptr(idenMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "modelMat"), 1, GL_FALSE, glm::value_ptr(modelMat27));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "viewMat"), 1, GL_FALSE, glm::value_ptr(viewMat));
		glUniformMatrix4fv(glGetUniformLocation(myShader->ID, "projMat"), 1, GL_FALSE, glm::value_ptr(projMat));

		glDrawArrays(GL_TRIANGLES, 0, 18);

		//above draw a cubic cone

		glfwSwapBuffers(window);
		glfwPollEvents();

		camera.UpdateCameraPos();
	}

	glfwTerminate();

	return 0;
}


