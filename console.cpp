#ifndef __cplusplus
#define __cplusplus 201402L
#endif

#include <QApplication>
#include <QVariant>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>

#include <pugi/pugixml.hpp>

#include "main.h"

int main(int argc, char *argv[])
{
  db_to_xml::operations(1);
}
