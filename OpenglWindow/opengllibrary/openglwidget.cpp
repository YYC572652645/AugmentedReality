#include "openglwidget.h"
#include <QMouseEvent>

OpenglWidget::OpenglWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}

OpenglWidget::~OpenglWidget()
{
}

void OpenglWidget::initializeGL()
{
    this->initializeOpenGLFunctions();
}

void OpenglWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void OpenglWidget::paintGL()
{
    // 清除颜色
    glClearColor(0.2, 0.3, 0.6, 1.0);

    // 清除颜色和深度缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
