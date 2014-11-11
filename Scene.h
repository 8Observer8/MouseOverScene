#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QMouseEvent>

class Scene : public QGLWidget
{
    Q_OBJECT

signals:
    void signalCoordinates( const QPoint &p );

public:
    Scene( QWidget *parent = 0 );

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    void mouseMoveEvent( QMouseEvent *event );
};

#endif // SCENE_H
