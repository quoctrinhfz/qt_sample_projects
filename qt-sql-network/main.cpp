#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Core and GUI Test
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Qt All Libs Test");

    QWidget *centralWidget = new QWidget(&mainWindow);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel("Testing Qt Modules...");
    layout->addWidget(label);

    QPushButton *button = new QPushButton("Click Me");
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [&]() {
        label->setText("Button Clicked!");
    });

    mainWindow.setCentralWidget(centralWidget);
    mainWindow.resize(400, 200);
    mainWindow.show();

    // Network Test
    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://www.example.com"));
    QNetworkReply *reply = manager.get(request);

    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Network Test Passed!";
        } else {
            qDebug() << "Network Test Failed:" << reply->errorString();
        }
        reply->deleteLater();
    });

    // SQL Test
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (db.open()) {
        QSqlQuery query;
        query.exec("CREATE TABLE test (id INTEGER PRIMARY KEY, value TEXT)");
        query.exec("INSERT INTO test (value) VALUES ('Hello, Qt!')");
        if (query.exec("SELECT value FROM test WHERE id = 1")) {
            while (query.next()) {
                qDebug() << "SQL Test Passed! Value:" << query.value(0).toString();
            }
        }
    } else {
        qDebug() << "SQL Test Failed!";
    }

    return app.exec();
}
