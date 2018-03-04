QT += qml quick

CONFIG += c++11

SOURCES += main.cpp\
                ../TcpClient/client.cpp\
                ../CommonFiles/product.cpp\
                myimageprovider.cpp

HEADERS += \
                ../TcpClient/client.h\
                ../CommonFiles/product.h\
                ../CommonFiles/const.h\
                myimageprovider.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    Page3.qml
