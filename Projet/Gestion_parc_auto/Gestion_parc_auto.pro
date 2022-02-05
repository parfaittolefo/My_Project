QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT     += sql


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddNewCare.cpp \
    care_state.cpp \
    carehistory.cpp \
    choice_page_2.cpp \
    hircare_3.cpp \
    hireimg.cpp \
    image.cpp \
    login_1.cpp \
    main.cpp

HEADERS += \
    A_ll_H.h \
    AddNewCare.h \
    care_state.h \
    carehistory.h \
    choice_page_2.h \
    database.h \
    hircare_3.h \
    hireimg.h \
    image.h \
    login_1.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
