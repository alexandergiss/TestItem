QT += core gui quick quickcontrols2 widgets quickwidgets

SOURCES += \
        PdfEditorItem.cpp \
        main.cpp

HEADERS += \
        PdfEditorItem.h

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
