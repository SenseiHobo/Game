#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Connect to MySQL Server without a specific database
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("sammy");
    db.setPassword("#Superdeadcasp2004");

    if (!db.open()) {
        qDebug() << "Failed to connect to MySQL Server";
        return -1;
    }

    QSqlQuery query;
    // Check if the database exists and create it if it doesn't
    if (!query.exec("CREATE DATABASE IF NOT EXISTS `character`")) {  // Using backticks to escape reserved keyword
        qDebug() << "Failed to create database: " << query.lastError();
        return -1;
    } 

    // Close the connection and reconnect to the newly created database
    db.close();
    db.setDatabaseName("character");

    if (!db.open()) {
        qDebug() << "Failed to connect to the newly created database";
        return -1;
    }

    qDebug() << "Connected to the database and ready to go!";
    
    return 0;
}
