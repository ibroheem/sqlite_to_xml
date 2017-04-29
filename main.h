#ifndef HEADER_EFA918B21E995151
#define HEADER_EFA918B21E995151

#include "mib/Qt/error_checking.h"
//#include "mib/pugi/operations.h"
#include "operations.h"
#include "mib/Qt/string_operations.h"
#include "mib/io.h"

using namespace mvc_utils::io;
using namespace mvc_utils::string_operations_Qt;
using namespace operations;
using namespace pugi;
using namespace std;

QString res;

namespace  db_to_xml
{
   QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE");
   cchar* db_name  = "/home/ibroheem/usr/devs/sql/books.db";
   cchar* db_name2  = "/home/ibroheem/usr/devs/sql/Book2.db";

   QString db_to_xml()
   {
      xml_document doc;

      xml_node header = doc.append_child ("header");
      append_attribute (header, "version", "0.1.1");
      append_attributes (header, {"book", "date"}, {"Books Catalogue", "20/03/2015"});

      vector<xml_node> nodes;

      nodes.push_back (append_child (header, "table") );
      nodes[0].append_attribute ("name").set_value ("bok");

      //nodes.push_back(append_child(nodes[0], "bok"));

      nodes.push_back (append_child (header, "table") );
      nodes[1].append_attribute ("name").set_value ("cat");

      db.open();
      db.setDatabaseName (db_name);

      is_sql_open (db);

      //QSqlQuery query ("SELECT bkid, bk, cat, betaka, inf, bkord, authno, auth, AuthInf FROM bok", db),
      QSqlQuery query ("SELECT * FROM bok", db),
                query2 ("SELECT id, name, catord, Lvl, _id, librayTotal, downloadTotal FROM bok");

      QString txt;
      QList<QByteArray> slist_bok = {}, slit_cat = {};
      /*std::initializer_list<cchar*> names_bok = {"bkid", "bk", "cat", "betaka", "inf", "bkord", "authno", "auth",
                                                 "AuthInf"
                                                },
    names_cat = {"id", "name", "catord", "Lvl", "_id", "librayTotal", "downloadTotal"}*/;

      auto column_name = [&] (int i) { return query.record().fieldName(i); };
      vector<cchar*> cols;
      for (int i = 0; i < query.record().count(); ++i)
         cols.push_back(column_name(i).toAscii());

      int i = 2, l = 0,  row_i = 0;
      while (query.next() || query2.next())
      {
         txt += query.value (1).toString() + "\n";
         for (int j = 0; j < 9; ++j)
         {
            slist_bok.append (query.value (j).toString().toUtf8() );
         }

         nodes.push_back (append_child(nodes[0], "row"));
         append_attribute(nodes[i], "value", ++row_i);
         //append_attributes_Qt (nodes[i], names_bok, slist_bok);
         //append_attributes_Qt(nodes[0], {"bkid", "bk"}, slist_bok);
         //append_child (nodes[i], pugi::node_pcdata, slist_bok[1]);
         append_children(nodes[i], cols, slist_bok);
         for (xml_node &child : nodes[i].children())
         {
            append_attribute(child, "value", slist_bok[l++]);
         }
         slist_bok.clear();
         ++i; l = 0;
      }

      doc.save_file ("book.xml");
      return txt;
   }

   void operations(uint opt)
   {
      switch (opt)
      {
         case 1:
         {
            db.setDatabaseName("/media/ibroheem/1BE7CD124123146F/usr/pkg/android/data/quran_android/quran.ensi.db");
            db.open();

            QSqlQuery query("SELECT * FROM verses_content");
            while (query.next())
            {
               //
            }

         } break;

         case 2:
         {

         } break;

         case 3:
         {

         } break;

         default:
            break;
      }
   }

   void select_all_columns()
   {
      db.open();
      db.setDatabaseName(db_name2);
      is_sql_open (db);

      //QSqlQuery query ("SELECT * FROM bok", db);
      QSqlQuery query ("SELECT * FROM b", db);
      auto value = [&] (int i) { return query.value(i); };

      int i = 0;
      vector<vector<QString>> col_vals;
      QStringList tlist = db.tables();
      int col_size = query.record().count();


      while (query.next())
      {
         for (int l = 0; l < col_size; ++l)
         {

         }
         res += value(0).toString(); //append elements in column 0
         ++i;
      }
   }
}

#endif // header guard
