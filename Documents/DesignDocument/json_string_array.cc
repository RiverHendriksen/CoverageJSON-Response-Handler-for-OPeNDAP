/**
 * String version of json_simple_type_array(). This version exists because of the differing
 * type signatures of the libdap::Vector::value() methods for numeric and c++ string types.
 *
 * @param strm Write to this stream
 * @param a Source Array - write out data or metadata from or about this Array
 * @param indent Indent the output so humans can make sense of it
 * @param sendData True: send data; false: send metadata
 */
void FoDapJsonTransform::json_string_array(std::ostream *strm, libdap::Array *a, string indent, bool sendData)
{
    *strm << indent << "{" << endl;\
    string childindent = indent + _indent_increment;

    writeLeafMetadata(strm, a, childindent);

    int numDim = a->dimensions(true);
    vector<unsigned int> shape(numDim);
    long length = fojson::computeConstrainedShape(a, &shape);

    *strm << childindent << "\"shape\": [";

    for (std::vector<unsigned int>::size_type i = 0; i < shape.size(); i++) {
        if (i > 0) *strm << ",";
        *strm << shape[i];
    }
    *strm << "]";

    if (sendData) {
        *strm << "," << endl;

        // Data
        *strm << childindent << "\"data\": ";
        unsigned int indx;

        // The string type utilizes a specialized version of libdap:Array.value()
        vector<std::string> sourceValues;
        a->value(sourceValues);
        indx = json_simple_type_array_worker(strm, (std::string *) (&sourceValues[0]), 0, &shape, 0);

        if (length != indx)
            BESDEBUG(FoDapJsonTransform_debug_key,
                "json_string_array() - indx NOT equal to content length! indx:  " << indx << "  length: " << length << endl);

    }

    *strm << endl << indent << "}";
}