#include <iostream>
#include <GL/freeglut.h>

void RenderSceneGB() {
    glClearColor(0.0f, 0.3f, 0.5f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("IDKWTD");

    glutDisplayFunc(RenderSceneGB);
    glutMainLoop();
}
