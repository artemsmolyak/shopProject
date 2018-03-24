#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <../TcpClient/client.h>
#include <QQmlContext>
#include <myimageprovider.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Client client;

    QQmlApplicationEngine engine;
    QQmlContext * context = engine.rootContext();
    context->setContextProperty("client", &client);
    client.setQmlRootContext(context);
    MyImageProvider *imageProvider = new MyImageProvider(&client);
    engine.addImageProvider("myprovider",imageProvider);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

   //engine.setOfflineStoragePath(QDir::homePath() + "/AndroidDiary");


    client.setQmlRoot(engine.rootObjects().value(0));


    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
