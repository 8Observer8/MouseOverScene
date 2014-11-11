#include "Scene.h"
#include <QDebug>

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent )
{
    this->setMouseTracking( true );
}

void Scene::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void Scene::paintGL()
{
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    // Set current drawing color to red
    //		   R	 G	   B
    glColor3f( 0.0f, 1.0f, 0.0f );

    // Draw a filled rectangle with current color
    glBegin( GL_QUADS );
    {
        glVertex2f( 250, 250 );
        glVertex2f( 300, 250 );
        glVertex2f( 300, 300 );
        glVertex2f( 250, 300 );
    }
    glEnd();

}

void Scene::resizeGL( int w, int h )
{
    // Prevent a divide by zero
    if( h == 0 ) {
        h = 1;
    }

    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    glOrtho( 0, this->width(), this->height(), 0, -1.0, 1.0);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Scene::mouseMoveEvent( QMouseEvent *event )
{
    emit signalCoordinates( event->pos() );
}
