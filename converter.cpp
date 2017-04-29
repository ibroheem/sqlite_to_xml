#include "converter.h"
#include "mib/algorithm.h"
//#include "main.h"

using namespace mvc_utils::io;
using namespace mvc_utils::string_operations;
using namespace std;
using namespace conversion;

int main (int argc, char *argv[])
{
  if (argc > 1)
  {
    uint out_start_pos = 0;
    string o_option = "-o";
    sqlite_to_xml_Qt conv;

    for ( uint index_args = 1; index_args < static_cast<uint> (argc); ++index_args )
    {
      if (o_option  == argv[index_args])
      {
        out_start_pos = index_args + 1; //out_start_pos is the start of output args, one past -o pos
        if ( index_args - 1 == ( (argc - out_start_pos) ) ) // no of src db args == to output args
        {
          for ( uint index_db = 1, index_output = out_start_pos; index_db < index_args ; ++index_db, ++index_output )
          {
            conv.set_db_name (argv[index_db]);
            //conv.set_output_name (argv[index_output]);
            conv.convert_n_write(argv[index_output]);
            conv.reset_xml_doc_w_child ("header");
          }
        }
        break;
      }
    }
  }

  else
  {
    print_ln ("Too few arguements");
    print_ln ("Usage: converter [options] file(s)");
  }

  return 0;
}

