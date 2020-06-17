#-------------------------------------------------
#
# Project created by QtCreator 2020-02-17T16:56:11
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = final_2
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    admininterface.cpp \
    spadmininterface.cpp \
    spworkinterface.cpp \
    err.cpp \
    existingusers.cpp \
    success.cpp \
    iteminformation.cpp \
    pwderr.cpp \
    adduser.cpp \
    existingsaleuser.cpp \
    addsaleuser.cpp \
    itemchange.cpp \
    itemcreate.cpp \
    changepassword.cpp \
    javaconnect.cpp \
    iteminfo.cpp

HEADERS  += login.h \
    admininterface.h \
    spadmininterface.h \
    spworkinterface.h \
    err.h \
    existingusers.h \
    changepassword.h \
    success.h \
    iteminformation.h \
    pwderr.h \
    adduser.h \
    existingsaleuser.h \
    addsaleuser.h \
    itemchange.h \
    itemcreate.h \
    javaconnect.h \
    iteminfo.h

FORMS    += login.ui \
    admininterface.ui \
    spadmininterface.ui \
    spworkinterface.ui \
    err.ui \
    existingusers.ui \
    changepassword.ui \
    success.ui \
    iteminformation.ui \
    pwderr.ui \
    adduser.ui \
    existingsaleuser.ui \
    addsaleuser.ui \
    itemchange.ui \
    itemcreate.ui \
    iteminfo.ui
