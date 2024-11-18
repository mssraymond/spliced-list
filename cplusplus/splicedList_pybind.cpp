#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "splicedList.hpp"

namespace py = pybind11;

PYBIND11_MODULE(splicedList, m)
{
    m.doc() = "Python binding for the C++ SplicedList class";

    // First, bind the custom exception
    py::register_exception<SplicedListNonexistentKeyException>(m, "SplicedListNonexistentKeyException");

    // Bind the SplicedList class
    py::class_<SplicedList>(m, "SplicedList")
        .def(py::init<>()) // Constructor
        .def("exists", &SplicedList::exists, "Check if a key exists in the list",
             py::arg("key"))
        .def("pop", &SplicedList::popValue, "Remove and return the value for a given key",
             py::arg("key"))
        .def("insert", [](SplicedList &self, const std::string &key, const py::object &after)
             {
            if (after.is_none()) {
                self.insert(key, nullptr);
            } else {
                std::string after_str = after.cast<std::string>();
                self.insert(key, &after_str);
            } }, "Insert a key into the list, optionally after another key", py::arg("key"), py::arg("after") = py::none())
        .def("get_all", [](SplicedList &self)
             {
            auto [arr, size] = self.getAll();
            std::vector<std::string> result(arr, arr + size);
            delete[] arr;  // Clean up the C++ array
            return result; }, "Get all values in the list as a Python list");
}