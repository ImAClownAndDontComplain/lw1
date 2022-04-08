                                                    Done by Loginova Polina of PRO-227 
                                  README for LW1
	OpenGL is a platform independent (programming language independent) programming interface for writing applications that use 2D and 3D computer graphics. It does not have its own API (application programming interface - application programming interface) for creating and managing a window.

Explanations for the code:
  1.	Linked Libraries:
    a)	#include <GL/glew.h>
    OpenGL Extension Wrangler Library (GLEW) - used to manage extensions in OpenGL. Once initialized, it queries all extensions available on the platform, loading them dynamically and providing easy access through a single header file.

    b)	#include <GL/freeglut.h>
    The OpenGL utility library (GLUT) is the simplest API for managing the window system, as well as event handling, I/O control, and a few other features.

    c)	#include "glm/vec3.hpp"
    OpenGL Mathematics (GLM) - C++ math library for graphical programming
    vec3 is an utility class representing a 3D vector, there are also vec2, vec4 classes for 2D and 4D respectively.

  2.	void RenderSceneCB()
  Here the scene is drawn and rendered (the process of obtaining an image from the model using a computer program):

    a)	glClearColor(0.5f, 0.5f, 0.5f, 0.0f)
    Clearing the screen and then painting it gray.

    b)	glClear(GL_COLOR_BUFFER_BIT);
    Clearing the screen with the color we defined above (i.e. clearing the framebuffer).

    c)	glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_POINTS, 3, 2);
    Functions for drawing (in this case, a triangle and two points). The GPU iterates through the vertex buffer, passing through the vertices one by one, and interprets them according to the type specified in the function call.
    Options:
      •	what is drawn (triangle / point / something else);
      •	index of the first vertex to draw (zero vertex for a triangle, third vertex for points);
      •	the number of vertices to draw (three starting from zero for a triangle, two starting from the third - the third and fourth - for points).

    d)	glutSwapBuffers();
    The function asks GLUT to swap the background buffer and frame buffer. The next call will render to the current framebuffer and the backgroundbuffer will be rendered.

  3.	GLuintVBO;
   VBO is a buffer used to store vertices.
   GLuint is a global variable for storing a pointer to the vertex buffer. (almost all OpenGL objects are accessible through a variable of type GLuint.)

  4.	glutInit(&argc, argv);
  GLUT initialization:
  The first parameter is a pointer to the number of arguments on the command line, and the second is a pointer to an array of arguments. The values are taken from the main function of the program: int main(int argc, char **argv).

  5.	Setting window parameters and creating it:
    a)	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    Sets the display mode for the window (such as the color model used, the number of different buffers, etc.).
      •	GLUT_DOUBLE
    Output to the window is carried out using 2 buffers. Rendering happens to the background buffer while another buffer is being displayed. Used for animation to eliminate the flickering effect.
      •	GLUT_RGBA
    A color buffer. Three-channel RGB color model, supplemented with a fourth alpha channel that sets the transparency of the color. The value 0 corresponds to full transparency, 1 - opacity.

    b)	glutInitWindowSize(1024, 768);
    The first parameter width is the window width in pixels, the second height is the window height in pixels. If this command is omitted, then GLUT will set the default window size, usually 300x300.

    c)	glutInitWindowPosition(100, 100);
    You can set the position of the created window relative to the upper left corner of the screen.
 
    d)	glutCreateWindow("IDKWTD");
    This command creates a window with the title given as a parameter and returns the window handle as an int. This handler is typically used for subsequent operations on that window, such as changing window options and closing the window.

  6.	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

  We initialize GLEW and check for errors.

  7.	glm::vec3 TriangleWithPoints[5] = {
      {-0.8f, -0.8f, 0.0f}, //lower left corner
      {0.8f, -0.8f, 0.0f}, //lower right corner
      {0.0f, -0.2f, 0.0f}, //upper corner
      {0.0f, 0.0f, 0.0f},  //center of the screen
      {0.0f, 0.2f, 0.0f}  // slightly above center
};
  Creating an array of vertices for a triangle with points (the triangle is located in the lower part of the window, the first point is exactly in the center, the second is higher).

  8.	Functions responsible for drawing in the window:
  After the window into which the graphic information will be displayed has been prepared and created, it is necessary to associate procedures with it that will be responsible for displaying graphic information, monitor the window size, monitor keystrokes, etc.
    a)	glGenBuffers(1, &VBO);
    The glGen* functions are needed to generate objects of variable types. The first parameter specifies the number of objects we want to create, and the second is a reference to an array of type GLuints to store the pointer to which the data will be stored (in this case, one object is created - the vertex buffer).

    b)	glBindBuffer(GL_ARRAY_BUFFER, VBO);
    We bind the pointer to the name of the target and then run the command on the target. These commands restrict changes to a value by a pointer until another one is restricted to replace it, or the call accepts 0 as the pointer.
    The GL_ARRAY_BUFFER parameter means that the buffer will store an array of vertices (you can specify another GL_ELEMENT_ARRAY_BUFFER parameter, it indicates that the vertex indices are stored in a different buffer).

    c)	glBufferData(GL_ARRAY_BUFFER, sizeof(TriangleWithPoints), TriangleWithPoints, GL_STATIC_DRAW);
    We fill the object with data. The call above takes the name of the target (same as the binding), the size of the data in bytes, the address of the vertex array, and a flag that indicates whether to pattern the data. Since we are not going to change the buffer values, we specify GL_STATIC_DRAW.

    d)	glBindBuffer(GL_ARRAY_BUFFER, VBO);
    We bind the buffer, prepare it for rendering.

    e)	glEnableVertexAttribArray(0);
    Access to a generic array of vertex attributes. If this option is enabled, the values in the generic vertex attribute array will be available and used for rendering when calling vertex array commands such as glDrawArrays or glDrawElements.

     f)	glDisableVertexAttribArray(0);
    Disable each vertex attribute as soon as it is no longer needed.

    g)	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    This call tells the pipeline how to accept the data inside the buffer.
    Options:
      •	attribute index;
      •	the number of components in the attribute (3 for X, Y and Z);
      •	data type for each component (real);
      •	whether attributes need to be normalized before being used in the pipeline (no);
      •	"step" - the number of bytes between two instances of the attribute (0, because we only store one attribute - the vertex coordinates and the data are densely packed);
      •	specifying the offset in the structure that the pipeline receives.


  9.	glutDisplayFunc(RenderSceneCB);
  The function that is responsible for drawing. Called by the operating system to draw (redraw) the contents of a window. The only parameter of this function is a pointer to the function that will be responsible for drawing in the window - RenderSceneCB, described above.
  
  10.	Entering the main GLUT loop:
  glutMainLoop();
  To run our program is to enter the so-called main GLUT loop. This cycle provides the relationship between the operating system and those functions that are responsible for the window, receive information from the input / output devices.

