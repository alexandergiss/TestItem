#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "PdfEditorItem.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<PdfEditorItem>("qml.testmodule", 1, 0, "ImageItem");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/TestItem/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
