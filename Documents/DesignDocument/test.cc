void FoDapJsonTransform::transform(ostream *strm, libdap::AttrTable &attr_table, string indent)
{

    string child_indent = indent + _indent_increment;

    // Start the attributes block
    *strm << indent << "\"attributes\": [";

//	if(attr_table.get_name().length()>0)
//		*strm  << endl << child_indent << "{\"name\": \"name\", \"value\": \"" << attr_table.get_name() << "\"},";

// Only do more if there are actually attributes in the table
    if (attr_table.get_size() != 0) {
        *strm << endl;
        libdap::AttrTable::Attr_iter begin = attr_table.attr_begin();
        libdap::AttrTable::Attr_iter end = attr_table.attr_end();

        for (libdap::AttrTable::Attr_iter at_iter = begin; at_iter != end; at_iter++) {

            switch (attr_table.get_attr_type(at_iter)) {
            case libdap::Attr_container: {
                libdap::AttrTable *atbl = attr_table.get_attr_table(at_iter);

                // not first thing? better use a comma...
                if (at_iter != begin) *strm << "," << endl;

                // Attribute Containers need to be opened and then a recursive call gets made
                *strm << child_indent << "{" << endl;

                // If the table has a name, write it out as a json property.
                if (atbl->get_name().length() > 0)
                    *strm << child_indent + _indent_increment << "\"name\": \"" << atbl->get_name() << "\"," << endl;

                // Recursive call for child attribute table.
                transform(strm, *atbl, child_indent + _indent_increment);
                *strm << endl << child_indent << "}";

                break;

            }
            default: {
                // not first thing? better use a comma...
                if (at_iter != begin) *strm << "," << endl;

                // Open attribute object, write name
                *strm << child_indent << "{\"name\": \"" << attr_table.get_name(at_iter) << "\", ";

                // Open value array
                *strm << "\"value\": [";
                vector<std::string> *values = attr_table.get_attr_vector(at_iter);
                // write values
                for (std::vector<std::string>::size_type i = 0; i < values->size(); i++) {

                    // not first thing? better use a comma...
                    if (i > 0) *strm << ",";

                    // Escape the double quotes found in String and URL type attribute values.
                    if (attr_table.get_attr_type(at_iter) == libdap::Attr_string
                        || attr_table.get_attr_type(at_iter) == libdap::Attr_url) {
                        *strm << "\"";
                        // string value = (*values)[i] ;
                        *strm << fojson::escape_for_json((*values)[i]);
                        *strm << "\"";
                    }
                    else {

                        *strm << (*values)[i];
                    }

                }
                // close value array
                *strm << "]}";
                break;
            }

            }
        }

        *strm << endl << indent;
    }

    // close AttrTable JSON

    *strm << "]";
}