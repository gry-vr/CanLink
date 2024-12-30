import re
import sys


def parse_structs(cpp_code):
    """
    Parse C++ structs and extract their names and fields.

    Args:
    cpp_code (str): The C++ code as a string.

    Returns:
    dict: A dictionary mapping struct names to lists of field names.
    """
    # Dictionary to store the result
    structs = {}

    # Regex to match struct definitions and field names
    struct_pattern = r"struct\s+(\w+)\s*{(.*?)};"
    field_pattern = r"\b\w+\s+(\w+);"

    # Find all structs in the code
    struct_matches = re.findall(struct_pattern, cpp_code, re.DOTALL)
    
    for struct_name, body in struct_matches:
        # Find all field names within the struct body
        fields = re.findall(field_pattern, body)
        # Add the struct name and fields to the dictionary
        structs[struct_name] = fields

    return structs


def write_decode_func(struct_name, field_names):
    output = f"void decode_{struct_name[:-2]}"
    output += f"(std::unordered_map<std::string, double>& value_map, { struct_name } * strct )\n"
    output += "{\n"
    def write_field_access(struct_name, field_names):
        _output = [f"\tvalue_map[\"{name}\"] =  {struct_name[:-1]+name}_decode(strct->{name});" for name in field_names]
        return _output
    lines = write_field_access(struct_name, field_names)
    for line in lines:
        output += line + "\n"
    output += "}"

    return output

def write_decode_signature(struct_name):
    output = f"void decode_{struct_name[:-2]}"
    output += f"(std::unordered_map<std::string, double>& value_map, { struct_name } * strct );\n\n"
    return output

cpp_code = """
struct dura_max_eec9_electronic_engine_control_9_t {
    /**
     * Range: 0..64255 (0..160.6375 %)
     * Scale: 0.0025
     * Offset: 0
     */
    uint16_t engine_exhaust_gas_recirculation;

    /**
     * Range: 0..64255 (0..250.996 Mpa)
     * Scale: 0.00390625
     * Offset: 0
     */
    uint16_t commanded_fuel_rail_pressure;

    /**
     * Range: 0..64255 (0..250.996 Mpa)
     * Scale: 0.00390625
     * Offset: 0
     */
    uint16_t commanded_engine_fuel_injection_;
};
"""


"""
# Parse the C++ code and print the results
structs = parse_structs(cpp_code)
for struct_name, fields in structs.items():
    #print(f"Struct: {struct_name}")
    #print(f"Fields: {fields}")

    print(write_decode_func(struct_name,fields))
"""




file_path = "../include/dura_max.h"
implementation = open("../src/decoding.cpp","w+")
header = open("../include/decoding.h","w+")

header.write("#pragma once\n")
header.write("#include <unordered_map> \n")
header.write("#include <string> \n")
header.write("#include \"dura_max.h\" \n")


implementation.write("#include \"decoding.h\" \n")

with open(file_path) as file:
    contents = file.read()

# Parse the C++ code and print the results
structs = parse_structs(contents)
for struct_name, fields in structs.items():
    #print(f"Struct: {struct_name}")
    #print(f"Fields: {fields}")
    implementation.write(write_decode_func(struct_name,fields)+"\n")
    header.write(write_decode_signature(struct_name) + "\n")





