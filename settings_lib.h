#ifndef HEADER_74B0B7EF3E283065
#define HEADER_74B0B7EF3E283065

#include <pugi/pugixml.hpp>
#include <string>

using namespace pugi;
using namespace std;

namespace settings_lib
{
  enum read_mode { buffer, file };

  class settings_base
  {
    public:
      settings_base() = default;
      settings_base(cchar *_fname_or_buffer, read_mode rd_md = read_mode::file);
      settings_base(const string& , read_mode rd_md = read_mode::file );
      settings_base (settings_base &&);
      settings_base (const settings_base &);
      settings_base& operator= (settings_base &&rhs);
      settings_base& operator= (const settings_base &rhs);

      ~settings_base();

      void read() { read(m_buffer); }
      void read(cchar *);
      void read(const string &);

      void read_file() { read_file(m_file_name); }
      void read_file(cchar *);
      void read_file(const string &in_file) { read_file(in_file.c_str()); }

      void clear() { if (!doc.empty()) doc.reset(); }
      xml_document& clear_and_replce_w(xml_document &);

    private:
      read_mode m_read_mode = read_mode::file;
      cchar * m_file_name =  "";
      cchar * m_buffer =  "";
      xml_document doc;
      xml_node header;// = doc.load_file(m_file_name);
  };

  settings_base::settings_base(cchar *_fn_or_buf, read_mode rd_md ) :
      m_file_name(rd_md == read_mode::file ? _fn_or_buf : ""),
      m_buffer(rd_md == read_mode::buffer ? _fn_or_buf : "")
  {

  }

  settings_base::settings_base(const string& fname, read_mode rd_md) :  settings_base(fname.c_str(), rd_md)
  {

  }

  void settings_base::read(cchar * in_buf)
  {
    this->clear();
    m_buffer = in_buf;
    doc.load(m_buffer);
  }

  void settings_base::read_file(cchar * in_file)
  {
    this->clear();
    m_file_name = in_file;
    doc.load_file(m_file_name);
  }

  xml_document& settings_base::clear_and_replce_w(xml_document &_node)
  {
    if(_node == doc)
      return doc;
    else
      doc.reset(_node);

    return doc;
  }

  class settings : public settings_base
  {
    setting() = default;


  };
}

#endif // header guard
