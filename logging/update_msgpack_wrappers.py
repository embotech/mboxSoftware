# @file update_msgpack_wrappers.py
# @author embotech AG
# @date 18 Jun 2021
# @brief Create a C++ function to serialize Obrttg structures.

import os
import sys

sys.path.insert(
    0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..", "..", "..", "..", "libembotech", "python"))
)  # nopep8
import itsawrap.wrap_msgpack.wrap_msgpack as wmpack

headerName = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "obrttg", "include", "obrttg_types.hpp"))  
outHeaderName = os.path.abspath(os.path.join(os.path.dirname(__file__), "include", "msgpack_wrapper_obrttg_types.hpp"))
outSrcName = os.path.abspath(os.path.join(os.path.dirname(__file__), "src", "test_logging_types.cpp"))
structNames = ["busGncParameters",
               "busGncCommIn",
               "busGncCommOut",
               "busGncNavigation",
               "busGncGuidance",
               "busGncController",
               "busGncOtp",
               "busGncMvm"]
wrapper_code = wmpack.create_msgpack_wrapper(headerName, structNames, "C++")
with open(outHeaderName, "w+") as ouf:
    ouf.write(wrapper_code)
#tester_code = wmpack.create_test_function(outHeaderName, structNames[0])
#with open(outSrcName, "w+") as ouf:
#    ouf.write(tester_code)