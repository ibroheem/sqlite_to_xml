#ifndef __cplusplus
#define __cplusplus 201402L
#endif

#include <QApplication>
#include <QVariant>

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

#include <pugi/pugixml.hpp>

#include "main.h"

using namespace pugi;

int main (int argc, char *argv[])
{
  //db_to_xml::select_all_columns();
  //db_to_xml::db_to_xml();
  QApplication app (argc, argv);


  app.setStyleSheet (QString (R"(QTextEdit {
    background-color: #a57c58;
    background-position: top right;
    background-repeat: repeat-y;
  }

  QMainWindow {
    background-color: #a57c58;
    background-position: top right;
    background-repeat: repeat-y;
  })") );

  QMainWindow *mwin = new QMainWindow;
  QTextEdit *tedit = new QTextEdit;
  QTextOption opt;
  QMenuBar *mnu = new QMenuBar;

  mnu->addAction ("Open");

  //tedit->setText(db_to_xml());

  opt.setAlignment(Qt::AlignHCenter);

  tedit->setText (res);
  tedit->setFont (QFont ("Droid sans", 14, 14) );
  tedit->document()->setDefaultTextOption(opt);

  mwin->setMenuBar (mnu);
  mwin->setCentralWidget (tedit);
  mwin->resize (660,  600);
  mwin->show();

  return app.exec();
}
