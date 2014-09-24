#include <QCoreApplication>
#include <QDebug>
#include <QScriptEngine>
#include <QScriptValue>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QScriptContext>
#include <QStringList>
#include <QtGlobal>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList args = a.arguments();

    qDebug() << "QT-Version: " << QT_VERSION_STR << endl;

    const int as(args.size());
    if(as < 2)
    {
        qDebug() << "not enough arguments" << endl;
        return 1;
    }
    QString FilePath = args[1];
    bool DebugMode = args.contains("-d");
    QFile file(FilePath);
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString source = "";
        QTextStream stream(&file);
        source = stream.readAll();

        if(DebugMode)
        {
            qDebug() << source << endl;
        }

        QScriptEngine engine;
        QScriptContext* context = engine.pushContext();
        context->parentContext();
        engine.evaluate(source);
        engine.popContext();

        qDebug() << "end of script-eval" << endl;
    }
    else
    {
        qDebug() << QString("file does not exists %1").arg(FilePath) << endl;
        return 2;
    }

    return 0;
}
