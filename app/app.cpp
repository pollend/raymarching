
#include <GL/glew.h>
#include <GL/glut.h>
#include <Transforms/Transform.h>
#include <Objects/MeshObject.h>
#include <Objects/Loader/MeshLoader.h>
#include <View/PerspectiveView.h>
#include <boost/qvm/mat.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/mat_operations.hpp>
#include <boost/qvm/map_mat_vec.hpp>
#include <boost/qvm/map_vec_mat.hpp>
#include <Objects/Plane.h>
#include <boost/log/trivial.hpp>

GLfloat width = 800;
GLfloat height = 600;

Transform* teapot;
MeshObject* meshObject;
Plane* plane;
PerspectiveView* view;
Transform* plane_transform;
void display();
void init();
void reshape(GLint width, GLint height);

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize((GLint)width, (GLint)height);
	glutCreateWindow("Teapot");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


// Initialize the application.
void init() {
	glewInit();
	glClearColor(1.0, 1.0, 1.0, 1.0);
	int size = 0;

	meshObject = LoadObj("./assets/Teapot.obj",size);
	plane = new Plane();

	Source* vs = new Source("./assets/simple.vs");
	Source* fs = new Source("./assets/red.fs");
	Program* program = new Program();

	program->AttachSource(vs);
	program->AttachSource(fs);
	program->IntalizeShader();

	view = new PerspectiveView(3.14f/2.0f,1.0f,0.5f,20.0f);

	plane_transform = new Transform(plane,program);
	//teapot = new Transform(meshObject,program);

	boost::qvm::vec<float,3> v={0,-3,-30};
	//teapot->Local = boost::qvm::translation_mat(v);
	plane_transform->Local = boost::qvm::translation_mat(v);
}




// Clears the window and draws the tetrahedron.
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//teapot->Draw(0.0f,view);
	plane_transform->Draw(0.0f,view);

    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        BOOST_LOG_TRIVIAL(error) << "OpenGL error:" <<  err << "--"<< glewGetErrorString(err);
    }


	glutSwapBuffers();
	glutPostRedisplay();
}



//reshape screen
void reshape(GLint width, GLint height)
{
	glViewport(0, 0, width, height);
}

