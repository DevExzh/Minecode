#ifndef EXZHOPENGLWIDGET_H
#define EXZHOPENGLWIDGET_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLFramebufferObject>
#include <glut.h>

class ExzhOpenGLWidget : public QOpenGLWidget , public QOpenGLFunctions
{
public:
    ExzhOpenGLWidget();

protected:
    //void initializeGL();
    //void paintGL();
    //void resizeGL(int w,int h);

private:
    /*
    void exDrawSpaceAxies();
    GLuint m_Base;                                  //储存绘制字体的显示列表的开始位置
    GLfloat m_Cnt1;                                 //字体移动计数器1
    GLfloat m_Cnt2;                                 //字体移动计数器2

    QString m_FileName[2];                          //图片的路径及文件名
    GLuint m_Texture[2];                            //储存两个纹理
    */

};

#endif // EXZHOPENGLWIDGET_H
