#include <iostream>

extern "C"{

#include "parson.h"

}

using namespace std;


int main(){

        JSON_Value *root_value;
        JSONArray *src,keywords;

        root_value=json_parse_file("package.json");

        JSON_Object *name=json_value_get_object(root_value);

        const char* v_name=json_object_get_string(name,"name");

        cout<<v_name<<endl;


}
