#include "exzhopenglwidget.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

ExzhOpenGLWidget::ExzhOpenGLWidget()
{

}

/*
void ExzhOpenGLWidget::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);                   //黑色背景
    glShadeModel(GL_SMOOTH);                            //启用阴影平滑
    glClearDepth(1.0);                                  //设置深度缓存
    glEnable(GL_DEPTH_TEST);                            //启用深度测试
    glDepthFunc(GL_LEQUAL);                             //所作深度测试的类型
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  //告诉系统对透视进行修正
}

void ExzhOpenGLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
}

void ExzhOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);    
    glMatrixMode(GL_PROJECTION);                        //选择投影矩阵
    glLoadIdentity();
}

void ExzhOpenGLWidget::exDrawSpaceAxies()
{
GLUquadricObj *objCylinder =gluNewQuadric();
float AXES_LEN=0.1;
glPushMatrix();
glColor3f(1.0f,1.0f, 1.0f);
glutSolidSphere(0.25,6,6);
glColor3f(0.0f,0.0f, 1.0f);
gluCylinder(objCylinder,0.1, 0.1, AXES_LEN, 10, 5);         //Z
glTranslatef(0,0,AXES_LEN);
gluCylinder(objCylinder,0.3, 0.0, 0.6, 10, 5);                 //Z
glPopMatrix();

glPushMatrix();
glTranslatef(0,0.5,AXES_LEN);
glRotatef(90,0.0,1.0,0.0);                                      // Print GL Text ToThe Screen
glPopMatrix();


glPushMatrix();
glColor3f(0.0f,1.0f, 0.0f);
glRotatef(-90,1.0,0.0,0.0);
gluCylinder(objCylinder,0.1, 0.1, AXES_LEN, 10, 5);         //Y
glTranslatef(0,0,AXES_LEN);
gluCylinder(objCylinder,0.3, 0.0, 0.6, 10, 5);                 //Y
glPopMatrix();

glPushMatrix();
glTranslatef(0.5,AXES_LEN,0);                                            // Print GL Text ToThe Screen
glPopMatrix();


glPushMatrix();
glColor3f(1.0f,0.0f, 0.0f);
glRotatef(90,0.0,1.0,0.0);
gluCylinder(objCylinder,0.1, 0.1, AXES_LEN, 10, 5);         //X
glTranslatef(0,0,AXES_LEN);
gluCylinder(objCylinder,0.3, 0.0, 0.6, 10, 5);                 //X
glPopMatrix();

glPushMatrix();
glTranslatef(AXES_LEN,0.5,0);                                             // Print GL Text ToThe Screen
glPopMatrix();
}


void buildFont()                            //创建位图字体
{
    float cx, cy;                                       //储存字符的x、y坐标
    m_Base = glGenLists(256);                           //创建256个显示列表
    glBindTexture(GL_TEXTURE_2D, m_Texture[0]);         //选择字符纹理

    for (int i=0; i<256; i++)                           //循环256个显示列表
    {
        cx = float(i%16)/16.0f;                         //当前字符的x坐标
        cy = float(i/16)/16.0f;                         //当前字符的y坐标

        glNewList(m_Base+i, GL_COMPILE);                //开始创建显示列表
            glBegin(GL_QUADS);                          //使用四边形显示每一个字符
                glTexCoord2f(cx, 1-cy-0.0625f);
                glVertex2i(0, 0);
                glTexCoord2f(cx+0.0625f, 1-cy-0.0625f);
                glVertex2i(16, 0);
                glTexCoord2f(cx+0.0625f, 1-cy);
                glVertex2i(16, 16);
                glTexCoord2f(cx, 1-cy);
                glVertex2i(0, 16);
            glEnd();                                    //四边形字符绘制完成
            glTranslated(10, 0, 0);                     //绘制完一个字符，向右平移10个单位
        glEndList();                                    //字符显示列表完成
    }


void exDrawOpeningAnimation()
{

}
*/

