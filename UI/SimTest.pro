#-------------------------------------------------
#
# Project created by QtCreator 2014-01-03T16:02:30
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = SimTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../Library/KrisLibrary/GLdraw/QWidgetNavigationProgram.cpp \
    WorldViewProgram.cpp \
    SimViewProgram.cpp \
    simtest.cpp \
    ../Library/KrisLibrary/GLdraw/QGLScreenshotProgram.cpp \
    qcombobox2.cpp \
    logoptions.cpp \
    driveredit.cpp

HEADERS  += mainwindow.h \
    ../Library/KrisLibrary/GLdraw/QWidgetNavigationProgram.h \
    WorldViewProgram.h \
    SimViewProgram.h \
    simtest.h \
    ../Library/KrisLibrary/GLdraw/QGLScreenshotProgram.h \
    qcombobox2.h \
    logoptions.h \
    driveredit.h

FORMS    += mainwindow.ui \
    logoptions.ui \
    driveredit.ui

#LIBS += -L/usr/include/GL/ -L/usr/X11R6/lib -L/usr/X11R6/lib/modules/extentions -L/lib -L/usr/lib
#LIBS += -L../lib -L../Library/KrisLibrary/lib
#LIBS += -lglut -lglui -lglut -lKrisLibrary -lKlampt
#LIBS += -Llib  -L/usr/lib -LLibrary/glui-2.36/src//lib -L/usr/lib/glut -L/usr/X11R6/lib -L/usr/X11R6/lib/modules/extensions -L/src -LLibrary/KrisLibrary/lib -LLibrary/ode-0.11.1/ode/src/.libs -LLibrary/tinyxml  -lKrisLibrary -lglui -lglut -lGL -lm -lGLU -lXm -lXi -lXext -lXmu -lX11 -lode -ltinyxml -lglpk
LIBS += -L../lib -lKlampt  -L/usr/lib -L../Library/glui-2.36/src//lib -L/usr/lib/glut -L/usr/X11R6/lib -L/usr/X11R6/lib/modules/extensions -L/src -L../Library/KrisLibrary/lib -L../Library/ode-0.11.1/ode/src/.libs -L../Library/tinyxml
LIBS += -lKrisLibrary -lglut -lGL -lm -lGLU -lXm -lXi -lXext -lXmu -lX11 -lode -ltinyxml -lglpk
INCLUDEPATH +=/usr/include/GL ../ ../Library/KrisLibrary ../Library/glui-2.36/src ../Library/ode0.11.1/ode/src
DEFINES += dDOUBLE
#DEFINES += -DLINUX -DdDOUBLE -DTIXML
QMAKE_CFLAGE_DEGUG += -g

RESOURCES += \
    icons.qrc
