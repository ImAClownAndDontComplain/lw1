#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm/vec3.hpp"
#include <iostream>

void RenderSceneGB() {
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_POINTS, 3, 2);
    glutSwapBuffers();
}
GLuint VBO;
GLuint AAA;
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("IDKWTD");


    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    /*glm::vec3 Vertices[1];
    Vertices[0] = glm::vec3(0.0f, 0.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);*/

    glm::vec3 TriangleWithPoints[5] = {
        {-0.8f, -0.8f, 0.0f},
        {0.8f, -0.8f, 0.0f},
        {0.0f, -0.2f, 0.0f},
        {0.0f, 0.0f, 0.0f},
        {0.0f, 0.2f, 0.0f}
    };
    GLuint buf[2];
    buf[0] = VBO;
    buf[1] = AAA;
    glGenBuffers(2, buf);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(TriangleWithPoints), TriangleWithPoints, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

   /*glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(TriangleWithPoints), TriangleWithPoints, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);*/


    glutDisplayFunc(RenderSceneGB);

    glutMainLoop();
}
