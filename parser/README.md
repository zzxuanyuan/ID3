Data Set Parser:

This API is meant to help streamline the process of retrieving data from
the data set text files and getting Attributes and Instances out of them.

The first thing you want to do is create a Parser object. This Parser object
will have two useful methods, parseFormat and parseData. parseFormat takes
inputs of a std::vector<Attribute>* which will be the end format it output,
and an std::string, which contains the path to the format file. After parsing
through the format, you will run parseData, which takes a pointer to the
format you just parsed, as well as an std::vector< std::vector<Instance> >*
which will be a pointer to the data it fills out. You will also need to pass
the path of the data file to this function.

Formatting:
Formatting is handled by a separate file that you need to make for each data
set. The format for monks-1 is included and follows this general formula:

d(C?{/...,N,ID}) )+

d = single character delimiter for different attributes in the data set
C = classification. Classifications can be numeric => CN, or domain based
    C/0,1.
/... = domains, which look like /0,1,2 if the domain was to be {0, 1, 2}.
       / is used to start a domain and it ends with the string.
N = numerical value. These are internally handled as floats and are great
    for making intervals.
ID = ids. They hold no attribute value and just represent that these are
     the names for each data point.

Direct Questions to Ian Howell at ianh413@gmail.com
